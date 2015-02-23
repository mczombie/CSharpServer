#include "StdAfx.h"

#include "mczd3d11Format.h"
#include "InputLayout.h"
#include "VertexTypeMgr.h"

namespace mczd3d {

static const UINT MAX_NUMDECLAR = 15;	//언제나 바뀔 수 있음.
static D3D11_INPUT_ELEMENT_DESC g_vertexElem[NUM_VERTEXFORMAT][1] = 
{
	{	//	POS_VERTEX
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	},
};

CVertexTypeMgr::CVertexTypeMgr(void)
{
}

CVertexTypeMgr::~CVertexTypeMgr(void)
{
}

bool CVertexTypeMgr::Init()
{
	for ( unsigned int index = 0 ; index < NUM_VERTEXFORMAT ; ++index ) {
		m_size[index] = sizeof(g_vertexElem[index]);
	}
	return true;
}

void CVertexTypeMgr::Exit()
{

}

IInputLayout* CVertexTypeMgr::CreateInputLayout( VERTEXFORMAT format, IVertexShader* pShader )
{
	CInputLayout* pInputlayout = new CInputLayout;
	pInputlayout->Create(g_vertexElem[format], ARRAYSIZE(g_vertexElem[format]), pShader);
	return pInputlayout;
}

unsigned int CVertexTypeMgr::GetVertexSize( VERTEXFORMAT format ) const
{
	return m_size[format];
}

CVertexTypeMgr* GetVertexTypeMgr()
{
	static CVertexTypeMgr g_VertexTypeMgr;
	return &g_VertexTypeMgr;
}

}