#pragma once

namespace mczd3d
{

	struct D3D11_INIT
	{
		HWND hwnd;

	};

bool Init(const D3D11_INIT& initInfo);
void Exit();


}