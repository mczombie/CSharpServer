#include "stdafx.h"

#include <d3dcompiler.h>
#include "D3D11Util.h"

namespace mczd3d {

bool CompileShaderFromFile(const std::wstring& fileName, const char* szEntryPoint, const char* szShaderModel, ID3DBlob** ppBlobOut)
{
	HRESULT hr = S_OK;
	DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#ifdef _DEBUG
	dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

	ID3DBlob* pErrorBlob = nullptr;
	hr = D3DX11CompileFromFile(fileName.c_str(), nullptr, nullptr, szEntryPoint, szShaderModel, dwShaderFlags, 0, nullptr, ppBlobOut, &pErrorBlob, nullptr);
	if (FAILED(hr)) {
		if (pErrorBlob)
			OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
		SAFE_RELEASE(pErrorBlob);
		return false;
	}
	SAFE_RELEASE(pErrorBlob);
	return true;
}

}