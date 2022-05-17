#include <windows.h>
#include <atlImage.h>
#include "basic.h"
#include "character.h"

PAINTSTRUCT ps;
HDC hdc;
HDC printMemDC, copyMemDC;
HBITMAP printHBIT, oldPrintHBIT, copyHBIT, oldCopyHBIT;
CHARACTER player;
HINSTANCE g_hInst;
TCHAR lpszClass[] = TEXT("TermProject");
POINT mouse;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	if (!hPrevInstance) {
		WndClass.cbClsExtra = 0;
		WndClass.cbWndExtra = 0;
		WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		//--- 윈도우 배경색 변경 가능
		WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		WndClass.hInstance = hInstance;
		WndClass.lpfnWndProc = (WNDPROC)WndProc;
		WndClass.lpszClassName = lpszClass;
		WndClass.lpszMenuName = NULL;
		WndClass.style = CS_HREDRAW | CS_VREDRAW;
		RegisterClass(&WndClass);
	}
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, 0, 0, 1633, 966, NULL, (HMENU)NULL, hInstance, NULL);		//--- 윈도우 크기 변경 가능
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	switch (iMessage) {
	case WM_CREATE:
		SetTimer(hWnd, 1, 100, CharIdle);
		player.xPos = 0;
		player.yPos = 400;
		player.rect.left = 0;
		player.rect.right = 85;
		player.rect.top = 400;
		player.rect.bottom = 505;
		player.isRun = FALSE;
		player.isJump = FALSE;
		player.direction = rightDir;
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		printMemDC = CreateCompatibleDC(hdc);
		oldPrintHBIT = (HBITMAP)SelectObject(printMemDC, printHBIT);

		StretchBlt(hdc, 0, 0, 1600, 1600, printMemDC, 0, 0, 1600, 1600, SRCCOPY);

		SelectObject(printMemDC, oldPrintHBIT); DeleteDC(printMemDC);
		EndPaint(hWnd, &ps);
		break;
	case WM_CHAR:
		switch (wParam)
		{
		case 'w':
			KillTimer(hWnd, 1);
			KillTimer(hWnd, 2);
			KillTimer(hWnd, 3);
			player.isJump = TRUE;
			CharJumpUp(hWnd);
			break;
		case 'a':
			if (player.isRun == FALSE)
			{
				KillTimer(hWnd, 1);
				SetTimer(hWnd, 3, 50, CharRunBack);
				player.isRun = TRUE;
			}
			break;
		case 'd':
			if (player.isRun == FALSE)
			{
				KillTimer(hWnd, 1);
				SetTimer(hWnd, 2, 50, CharRunFront);
				player.isRun = TRUE;
			}
			break;
		}
		break;
	case WM_KEYUP:
		KillTimer(hWnd, 2);
		KillTimer(hWnd, 3);
		KillTimer(hWnd, 4);
		player.isRun = FALSE;
		SetTimer(hWnd, 1, 100, CharIdle);
		break;
	case WM_MOUSEMOVE:
		mouse.x = LOWORD(lParam);
		mouse.y = HIWORD(lParam);
		if (mouse.x > (player.rect.left + player.rect.right) / 2)
		{
			player.direction = rightDir;
		}
		if (mouse.x < (player.rect.left + player.rect.right) / 2)
		{
			player.direction = leftDir;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

