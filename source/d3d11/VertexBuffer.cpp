#include "stdafx.h"

#include "VertexBuffer.h"

namespace mczd3d {

CVertexBuffer::CVertexBuffer(ID3D11Buffer* pBuffer)
: m_pVertexBuffer(pBuffer)
{
}


CVertexBuffer::~CVertexBuffer()
{
}

D3DBUFFER_TYPE CVertexBuffer::GetType() const
{
	return D3D_VERTEX;
}

const ID3D11Buffer* CVertexBuffer::GetBuffer() const
{
	return m_pVertexBuffer;
}

}