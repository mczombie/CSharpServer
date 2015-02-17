#include "stdafx.h"

#include "Device.h"
#include "mczd3d11.h"

namespace mczd3d
{

bool Init(const INIT_INFO& info)
{
	GetRealDevice()->Init(info);
	return false;
}

IDevice* GetDevice()
{
	return GetRealDevice();
}

INIT_INFO::INIT_INFO()
: width(1024), height(768), hWnd(nullptr), isWindow(true)
{
}

VB_CREATE_INFO::VB_CREATE_INFO()
: format(ERROR_FORMAT), count(0), usage(BU_STATIC), initializeData(nullptr)
{

}

}