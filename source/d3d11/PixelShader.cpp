#include "stdafx.h"

#include "D3D11Util.h"
#include "Device.h"

#include "PixelShader.h"

namespace mczd3d {

CPixelShader::CPixelShader(void)
: m_pPS(nullptr)
{
}


CPixelShader::~CPixelShader(void)
{
	SAFE_RELEASE(m_pPS);
}

bool CPixelShader::Create(const PS_LOADINFO& loadInfo)
{
	ID3DBlob* pBlob = nullptr;
	HRESULT hr = CompileShaderFromFile(loadInfo.fullfilename, "PS", "ps_4_0", &pBlob);
	if (FAILED(hr)) {
		return false;
	}

	hr = GetRealDevice()->Get3DDevice()->CreatePixelShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &m_pPS);
	if (FAILED(hr)) {
		return false;
	}
	SAFE_RELEASE(pBlob);
	return true;
}

ID3D11PixelShader* CPixelShader::GetShader()
{
	return m_pPS;
}

}