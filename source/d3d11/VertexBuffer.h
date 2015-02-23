#pragma once

#include "mczd3d11.h"

namespace mczd3d {

class CVertexBuffer
	: public ID3DBuffer
{
public:
	CVertexBuffer(ID3D11Buffer* pBuffer);
	~CVertexBuffer();

public:
	D3DBUFFER_TYPE	GetType() const override;

public:
	 ID3D11Buffer*	GetBuffer() const;

private:
	ID3D11Buffer*	m_pVertexBuffer;
};

}