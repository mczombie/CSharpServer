#include "stdafx.h"

#include "mczd3d11.h"
#include "mczd3d11Format.h"

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

	CreateTest();

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
	mczd3d::IDevice* pDev = mczd3d::GetDevice();

	mcz::vector4 flipColor;
	flipColor.x = 0.0f;
	flipColor.y = 0.0f;
	flipColor.z = 0.0f;
	flipColor.w = 0.0f;

	pDev->ClearMainRt(flipColor);

	pDev->SetVertexShader(m_pVS);
	pDev->SetPixelShader(m_pPS);


	pDev->Draw(3, 0);

	mczd3d::GetDevice()->Flip();
}

void CD3D9Test::CreateTest()
{
	{
		mczd3d::VS_LOADINFO loadInfo;
		loadInfo.fullfilename = L"..\\BasicShader.fx";
		m_pVS = mczd3d::GetDevice()->GetFactory()->CreateVertexShader(loadInfo);
	}

	{
		mczd3d::PS_LOADINFO loadInfo;
		loadInfo.fullfilename = L"..\\BasicShader.fx";
		m_pPS = mczd3d::GetDevice()->GetFactory()->CreatePixelShader(loadInfo);
	}

	{
		mczd3d::POS_VERT posVert[3];
		posVert[0].pos = mcz::vector3(0.0f, 0.5f, 0.5f);
		posVert[1].pos = mcz::vector3(0.5f, -0.5f, 0.5f);
		posVert[2].pos = mcz::vector3(-0.5f, -0.5f, 0.5f);

		mczd3d::VB_CREATE_INFO loadInfo;
		loadInfo.format = mczd3d::POS_VERTEX;
		loadInfo.count = 3;
		loadInfo.initializeData = posVert;
		loadInfo.usage = mczd3d::BU_CONST;
		m_pVB = mczd3d::GetDevice()->GetFactory()->CreateVertexBuffer(loadInfo);

		mczd3d::GetDevice()->SetVertexBuffer(m_pVB);
		mczd3d::GetDevice()->SetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	}

	{
		m_pIL = mczd3d::GetDevice()->GetFactory()->CreateInputLayout(mczd3d::POS_VERTEX, m_pVS);
		mczd3d::GetDevice()->SetInputLayout(m_pIL);
	}
}