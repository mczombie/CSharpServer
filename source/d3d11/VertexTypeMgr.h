#pragma once

#include "mczd3d11.h"
#include "mczd3d11Format.h"

namespace mczd3d {

class IDevice;
class IVertexShader; 
class CVertexTypeMgr
	: public IVertexTypeMgr
{
public:
	CVertexTypeMgr(void);
	~CVertexTypeMgr(void);

public:
	bool		Init();
	void		Exit();

public:
	IInputLayout*		CreateInputLayout(VERTEXFORMAT format, IVertexShader* pShader);
	unsigned int		GetVertexSize(VERTEXFORMAT format) const;

private:
	unsigned int		m_size[NUM_VERTEXFORMAT];
};

CVertexTypeMgr* GetVertexTypeMgr();

}