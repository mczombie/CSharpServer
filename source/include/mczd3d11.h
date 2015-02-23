#pragma once

#include <xstring>
#include <d3d11.h>
#include <d3dx11.h>

#include "mczCore.h"
#include "mczMath.h"
#include "mczd3d11Format.h"

namespace mczd3d
{

class IDevice;
struct INIT_INFO {
	INIT_INFO();
	unsigned int width;
	unsigned int height;
	HWND		 hWnd;
	bool		 isWindow;
};

bool		Init(const INIT_INFO& info);
void		Exit();

IDevice*	GetDevice();

class ID3DBuffer;
class IInputLayout;
class IVertexTypeMgr;
class IVertexShader;
class ID3DBuffer;
class IPixelShader;
class ID3DFactory;

class IDevice {
public:
	virtual ~IDevice() {}
	virtual	void	ClearMainRt(const mcz::vector4& vColor) ZOMBIE_PURE;
	virtual	bool	Flip() ZOMBIE_PURE;

	virtual	void	SetInputLayout(IInputLayout* pInputLayout) ZOMBIE_PURE;
	virtual	void	SetVertexShader(IVertexShader* pShader) ZOMBIE_PURE;
	virtual	void	SetPixelShader(IPixelShader* pShader) ZOMBIE_PURE;
	virtual	void	SetVertexBuffer(ID3DBuffer* pVertexBufrfer) ZOMBIE_PURE;
	virtual	void	SetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY primitive) ZOMBIE_PURE;
	virtual	void	Draw(unsigned int vertCount, unsigned int startPoint) ZOMBIE_PURE;

	virtual	IVertexTypeMgr*	GetVertexTypeMgr() ZOMBIE_PURE;
	virtual	ID3DFactory*	GetFactory() ZOMBIE_PURE;
};

enum VERTEXFORMAT;

enum BUFFER_USAGE
{
	BU_CONST,
	BU_DYNAMIC,
	BU_STATIC,
};
struct VB_CREATE_INFO
{
	VB_CREATE_INFO();
	VERTEXFORMAT	format;
	unsigned int	count;
	const void*		initializeData;
	BUFFER_USAGE	usage;
};

struct VS_LOADINFO {
	VS_LOADINFO();
	std::wstring fullfilename;
};

struct PS_LOADINFO {
	PS_LOADINFO();
	std::wstring fullfilename;
};

enum VERTEXFORMAT;
class ID3DFactory {
public:
	virtual ~ID3DFactory() {}
	virtual ID3DBuffer*		CreateVertexBuffer(const VB_CREATE_INFO& info) const ZOMBIE_PURE;
	virtual	IVertexShader*	CreateVertexShader(const VS_LOADINFO& info) const ZOMBIE_PURE;
	virtual	IPixelShader*	CreatePixelShader(const PS_LOADINFO& info) const ZOMBIE_PURE;
	virtual	IInputLayout*	CreateInputLayout(VERTEXFORMAT format, IVertexShader* pVB) ZOMBIE_PURE;
};

enum D3DBUFFER_TYPE
{
	D3D_VERTEX = 0,
	D3D_INDEX,
};

class ID3DBuffer {
public:
	virtual ~ID3DBuffer() {}
	virtual	D3DBUFFER_TYPE	GetType() const ZOMBIE_PURE;
};

class IVertexTypeMgr {
public:
	virtual ~IVertexTypeMgr() {}
};

class IInputLayout {
public:
	virtual ~IInputLayout() {}
};

class IVertexShader {
public:
	virtual ~IVertexShader() {}
};

class IPixelShader {
public:
	virtual ~IPixelShader() {}
};

}