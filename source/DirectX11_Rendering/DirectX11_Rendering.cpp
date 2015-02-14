// ZWindow.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "TestWindowFrame.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CTestWindow testWindow;
	testWindow.SetWindowName(_T("Test"), _T("Test"));
	testWindow.SetWindowSize(1280, 720);
	if (testWindow.CreateTestWindow() != TRUE)
		return 1;

	testWindow.Run();
	return 1;
}
