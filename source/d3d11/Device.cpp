#include "StdAfx.h"

#include "VertexTypeMgr.h"
#include "Device.h"

namespace mczd3d {

CDevice::CDevice(void)
: m_p3dDevice(nullptr), m_pImmediateContext(nullptr), m_pSwapChain(nullptr), m_pMainRtView(nullptr)
{
}


CDevice::~CDevice(void)
{
}

bool CDevice::Init( const INIT_INFO& info )
{
	HRESULT hr = S_OK;

	UINT createDeviceFlags = 0;
#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE,
	};
	UINT numDriverTypes = ARRAYSIZE( driverTypes );

	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
	};
	UINT numFeatureLevels = ARRAYSIZE( featureLevels );

	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory( &sd, sizeof(sd) );
	sd.BufferCount			= 1;
	sd.BufferDesc.Width		= info.width;
	sd.BufferDesc.Height	= info.height;
	sd.BufferDesc.Format	= DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage			= DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow			= info.hWnd;
	sd.SampleDesc.Count		= 1;
	sd.SampleDesc.Quality	= 0;
	sd.Windowed				= info.isWindow;

	D3D_DRIVER_TYPE driveTYpe		= D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL fetureLevel	= D3D_FEATURE_LEVEL_11_0;

	for( UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++ ) {
		driveTYpe = driverTypes[driverTypeIndex];
		hr = D3D11CreateDeviceAndSwapChain( nullptr, driveTYpe, nullptr, createDeviceFlags, featureLevels, numFeatureLevels, D3D11_SDK_VERSION, &sd, &m_pSwapChain, &m_p3dDevice, &fetureLevel, &m_pImmediateContext);
		if ( SUCCEEDED(hr) )
			break;
	}

	if ( FAILED(hr) )
		return false;

	if ( CreateMainRT() == false ) 
		return false;
	
	SetupViewPort(info);

	return true;
}

void CDevice::SetupViewPort(const INIT_INFO& info)
{
	D3D11_VIEWPORT vp;
	vp.Width	= static_cast<float>(info.width);
	vp.Height	= static_cast<float>(info.height);
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	m_pImmediateContext->RSSetViewports(1, &vp);
}

void CDevice::Exit()
{
	if ( m_pImmediateContext ) 
		m_pImmediateContext->ClearState();

	SAFE_RELEASE(m_pMainRtView);
	SAFE_RELEASE(m_pSwapChain);
	SAFE_RELEASE(m_pImmediateContext);
	SAFE_RELEASE(m_p3dDevice);
}

void CDevice::ClearMainRt( const mcz::vector4& vColor )
{
	m_pImmediateContext->ClearRenderTargetView(m_pMainRtView, &vColor.x);
}

bool CDevice::Flip()
{
	if ( FAILED(m_pSwapChain->Present( 0, 0 )) ) 
		return false;
	return true;
}

IVertexTypeMgr* CDevice::GetVertexTypeMgr()
{
	return GetVertexTypeMgr();
}

ID3DFactory* CDevice::GetFactory()
{
	return &m_resFactory;
}

bool CDevice::CreateMainRT()
{
	ID3D11Texture2D* pBackBuffer = nullptr;
	HRESULT hr = m_pSwapChain->GetBuffer( 0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer );
	if ( FAILED(hr) )
		return false;

	hr = m_p3dDevice->CreateRenderTargetView( pBackBuffer, nullptr, &m_pMainRtView );
	pBackBuffer->Release();
	if ( FAILED(hr) )
		return false;

	m_pImmediateContext->OMSetRenderTargets(1, &m_pMainRtView, nullptr);

	return true;
}

ID3D11Device* CDevice::Get3DDevice() const
{
	return m_p3dDevice;
}

CDevice* GetRealDevice()
{
	static CDevice g_sDevice;	
	return &g_sDevice;
}

}