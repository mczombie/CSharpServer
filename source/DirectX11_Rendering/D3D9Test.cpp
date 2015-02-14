#include "stdafx.h"

#include "mczd3d11.h"
#include "D3D9Test.h"


CD3D9Test::CD3D9Test()
{
}


CD3D9Test::~CD3D9Test()
{
}

bool CD3D9Test::Init()
{
	mczd3d::D3D11_INIT initInfo;

	//여기서 Init을 해주면 오켕
	
	mczd3d::Init(initInfo);
	return false;
}

void CD3D9Test::Exit()
{

}

void CD3D9Test::Run()
{


}
