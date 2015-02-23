#pragma once

#include "mczd3d11.h"

namespace mczd3d {

class CPixelShader
	: public IPixelShader
{
public:
	CPixelShader(void);
	~CPixelShader(void);

public:
	bool	Create(const PS_LOADINFO& loadInfo);

	ID3D11PixelShader*		GetShader();

private:
	ID3D11PixelShader*		m_pPS;
};

}