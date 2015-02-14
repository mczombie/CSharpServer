#pragma once

class CTestWindow
{
public:
	CTestWindow(void);
	~CTestWindow(void);

public:
	void	SetWindowName(const TCHAR* pTitle, const TCHAR* pWindowClassName);
	void	SetWindowSize(UINT width, UINT height);
	void	SetWindowInst(HINSTANCE hInst);

	BOOL	CreateTestWindow();
	void	Run();

private:
	void	SetWindowRealSize();
	ATOM	_RegisterClass();
	BOOL	_InitInstance();

private:
	enum { MAX_LOADSTRING = 100 };
	HINSTANCE	m_hInst;
	TCHAR		m_szTitle[MAX_LOADSTRING];
	TCHAR		m_szWindowClass[MAX_LOADSTRING];
	UINT		m_width, m_height;
	HWND		m_hWnd;
};
