#include "StdAfx.h"
#include "TestWindowFrame.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

CTestWindow::CTestWindow(void)
	: m_width(1200), m_height(800), m_hInst(NULL), m_hWnd(NULL)
{
}

CTestWindow::~CTestWindow(void)
{
}

void CTestWindow::SetWindowName(const TCHAR* pTitle, const TCHAR* pWindowClassName)
{
	wsprintf(m_szTitle, _T("%s"), pTitle);
	wsprintf(m_szWindowClass, _T("%s"), pWindowClassName);
}

void CTestWindow::SetWindowSize(UINT width, UINT height)
{
	m_width = width;
	m_height = height;
}

BOOL CTestWindow::CreateTestWindow()
{
	_RegisterClass();
	if (_InitInstance() != TRUE) {
		::MessageBoxW(NULL, _T("InitInstance Fail"), _T("WindowCreate Error"), MB_ICONERROR);
		return FALSE;
	}
	return TRUE;
}

ATOM CTestWindow::_RegisterClass()
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hInst;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = m_szWindowClass;
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	return RegisterClassEx(&wcex);
}

BOOL CTestWindow::_InitInstance()
{
	m_hWnd = CreateWindow(m_szWindowClass, m_szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, m_hInst, NULL);
	ShowWindow(m_hWnd, TRUE);

	if (!m_hWnd)
	{
		return FALSE;
	}

	ShowWindow(m_hWnd, TRUE);
	UpdateWindow(m_hWnd);

	return TRUE;
}

void CTestWindow::Run()
{
	MSG msg;


	m_test.Init(m_width, m_height, m_hWnd);
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT)
			{
				PostQuitMessage(0);
				return;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			//Run
			Sleep(1);
			m_test.Run();
			//
		}
	}
	m_test.Exit();
	return;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}