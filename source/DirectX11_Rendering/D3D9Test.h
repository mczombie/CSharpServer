#pragma once

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



};

