#include "stdafx.h"

#include "VertexBuffer.h"
#include "Device.h"
#include "D3DFactory.h"

namespace mczd3d 
{

CD3DFactory::CD3DFactory()
{
}


CD3DFactory::~CD3DFactory()
{

}

static void ConvertBufferInfo(const VB_CREATE_INFO& info, D3D11_BUFFER_DESC* pOutInfo, D3D11_SUBRESOURCE_DATA* pOutResource)
{
	ZeroMemory(pOutInfo, sizeof(D3D11_BUFFER_DESC));
	switch (info.usage)
	{
	case BU_CONST:		pOutInfo->Usage = D3D11_USAGE_IMMUTABLE;	break;
	case BU_DYNAMIC:	pOutInfo->Usage = D3D11_USAGE_DYNAMIC;		break;
	case BU_STATIC:		pOutInfo->Usage = D3D11_USAGE_STAGING;		break;
	}

	pOutInfo->BindFlags = D3D11_BIND_VERTEX_BUFFER;
	pOutInfo->ByteWidth = mczd3d::GetVertexSize(info.format) * info.count;
	pOutInfo->CPUAccessFlags = 0;

	ZeroMemory(pOutResource, sizeof(D3D11_SUBRESOURCE_DATA));
	pOutResource->pSysMem = info.initializeData;
}

ID3DBuffer* CD3DFactory::CreateVertexBuffer(const VB_CREATE_INFO& info) const
{
	D3D11_BUFFER_DESC bd;
	D3D11_SUBRESOURCE_DATA initData;
	ConvertBufferInfo(info, &bd, &initData);

	ID3D11Buffer* pD3DBuffer = nullptr;
	ID3DBuffer*	pNewBuffer = nullptr;
	HRESULT hr = GetRealDevice()->Get3DDevice()->CreateBuffer(&bd, &initData, &pD3DBuffer);
	if ( SUCCEEDED(hr) ){
		pNewBuffer = new CVertexBuffer(pD3DBuffer);
	}
	return pNewBuffer;
}

}

