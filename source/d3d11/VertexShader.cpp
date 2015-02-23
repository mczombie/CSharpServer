#include "stdafx.h"

#include "Device.h"
#include "D3D11Util.h"

#include "VertexShader.h"

namespace mczd3d {

CVertexShader::CVertexShader()
{
}


CVertexShader::~CVertexShader()
{
	SAFE_RELEASE(m_pVS);
	SAFE_RELEASE(m_pVSBlob);
}

bool CVertexShader::Create(const VS_LOADINFO& loadInfo)
{
	HRESULT hr = CompileShaderFromFile(loadInfo.fullfilename, "VS", "vs_4_0", &m_pVSBlob);
	if (FAILED(hr)) {
		return false;
	}

	hr = GetRealDevice()->Get3DDevice()->CreateVertexShader(m_pVSBlob->GetBufferPointer(), m_pVSBlob->GetBufferSize(), nullptr, &m_pVS);
	if (FAILED(hr)) {
		return false;
	}
	return true;
}

ID3DBlob* CVertexShader::GetBlob()
{
	return m_pVSBlob;
}

ID3D11VertexShader* CVertexShader::GetShader()
{
	return m_pVS;
}

}