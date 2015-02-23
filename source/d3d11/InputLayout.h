#pragma once

#include <mczd3d11.h>

namespace mczd3d {

class CInputLayout
	: public IInputLayout
{
public:
	CInputLayout(void);
	~CInputLayout(void);

public:
	bool Create(const D3D11_INPUT_ELEMENT_DESC* pLayOut, unsigned int numLayout, IVertexShader* pShader);

public:
	ID3D11InputLayout*	GetLayout();

private:
	ID3D11InputLayout*	m_pInputLayout;
};

}