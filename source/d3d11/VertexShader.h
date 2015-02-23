#pragma once

#include "mczd3d11.h"

namespace mczd3d {

class CVertexShader
	: public IVertexShader
{
public:
	CVertexShader(void);
	~CVertexShader(void);

public:
	bool		Create(const VS_LOADINFO& loadInfo);
	ID3DBlob*	GetBlob();
	ID3D11VertexShader*		GetShader();

private:
	ID3D11VertexShader*		m_pVS;
	ID3DBlob*				m_pVSBlob;
};

}