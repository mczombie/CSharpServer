#pragma once

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

class IInputLayout;
class IVertexTypeMgr;

class IDevice {
public:
	virtual ~IDevice() {}
	virtual	void	ClearMainRt(const mcz::vector4& vColor) ZOMBIE_PURE;
	virtual	bool	Flip() ZOMBIE_PURE;
	virtual	IVertexTypeMgr*	GetVertexTypeMgr() ZOMBIE_PURE;
};


class IVertexTypeMgr {
public:
	virtual ~IVertexTypeMgr() {}
};

class IInputLayout {
public:
	virtual ~IInputLayout() {}
};

}