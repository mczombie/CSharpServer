#include "stdafx.h"

#include "mczd3d11.h"
#include "D3D9Test.h"


CD3D9Test::CD3D9Test()
{
}


CD3D9Test::~CD3D9Test()
{
}

bool CD3D9Test::Init(unsigned int width, unsigned int height, HWND hWnd)
{
	mczd3d::INIT_INFO initInfo;
	initInfo.width = width;
	initInfo.height = height;
	initInfo.hWnd = hWnd;
	initInfo.isWindow = true;

	mczd3d::Init(initInfo);
	return false;
}

void CD3D9Test::Exit()
{

}

void CD3D9Test::Run()
{
	Update(1.0f);
	Render(1.0f);
}

void CD3D9Test::Update(float elapsedTime)
{
	//Update
}

void CD3D9Test::Render(float elapsedTime)
{
	//Render
	mcz::vector4 flipColor;
	flipColor.x = 1.0f;
	flipColor.y = 1.0f;
	flipColor.z = 0.0f;
	flipColor.w = 0.0f;

	mczd3d::GetDevice()->ClearMainRt(flipColor);
	mczd3d::GetDevice()->Flip();
}
