#pragma once

#include "mczd3d11.h"

class CD3D9Test
{
public:
	CD3D9Test();
	~CD3D9Test();

public:
	bool	Init(unsigned int width, unsigned int height, HWND hWnd);
	void	Exit();

public:
	void	Run();

private:
	void	Control();
	void	Update(float elapsedTime);
	void	Render(float elapsedTime);

private:
	void	CreateTest();

private:
	mczd3d::IVertexShader*	m_pVS;
	mczd3d::IPixelShader*	m_pPS;
	mczd3d::ID3DBuffer*		m_pVB;
	mczd3d::IInputLayout*	m_pIL;
};

