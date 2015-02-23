#include "stdafx.h"

#include "Device.h"
#include "VertexShader.h"
#include "InputLayout.h"

namespace mczd3d {

CInputLayout::CInputLayout()
: m_pInputLayout(nullptr)
{
}

CInputLayout::~CInputLayout()
{
	SAFE_RELEASE(m_pInputLayout);
}

bool CInputLayout::Create(const D3D11_INPUT_ELEMENT_DESC* pLayOut, unsigned int numLayout, IVertexShader* pShader)
{
	CVertexShader* pRealShader = dynamic_cast<CVertexShader*>(pShader);
	assert(pRealShader);

	ID3D11Device* pRealDev = GetRealDevice()->Get3DDevice();
	HRESULT hRet = pRealDev->CreateInputLayout(pLayOut, numLayout, pRealShader->GetBlob()->GetBufferPointer(), pRealShader->GetBlob()->GetBufferSize(), &m_pInputLayout);
	if (SUCCEEDED(hRet))
		return true;
	return false;
}

ID3D11InputLayout* CInputLayout::GetLayout()
{
	return m_pInputLayout;
}

}

