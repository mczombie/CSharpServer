#pragma once

namespace mczd3d {

bool CompileShaderFromFile(const std::wstring& fileName, const char* szEntryPoint, const char* szShaderModel, ID3DBlob** ppBlobOut);

}

