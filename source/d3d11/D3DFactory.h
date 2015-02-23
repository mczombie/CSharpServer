#pragma once

#include "mczd3d11.h"

namespace mczd3d {

class CD3DFactory
	: public ID3DFactory
{
public:
	CD3DFactory();
	~CD3DFactory();

public:
	ID3DBuffer*		CreateVertexBuffer(const VB_CREATE_INFO& info) const override;
	IVertexShader*	CreateVertexShader(const VS_LOADINFO& info) const override;
	IPixelShader*	CreatePixelShader(const PS_LOADINFO& info) const override;
	IInputLayout*	CreateInputLayout(VERTEXFORMAT format, IVertexShader* pVB) override;
};

}

