#include <windows.h>
#include <atlImage.h>
#include "basic.h"
#include "batRed.h"
#include "character.h"
#include "TimeProc.h"

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
		WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		//--- ������ ���� ���� ����
		WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		WndClass.hInstance = hInstance;
		WndClass.lpfnWndProc = (WNDPROC)WndProc;
		WndClass.lpszClassName = lpszClass;
		WndClass.lpszMenuName = NULL;
		WndClass.style = CS_HREDRAW | CS_VREDRAW;
		RegisterClass(&WndClass);
	}
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, 0, 0, 1633, 966, NULL, (HMENU)NULL, hInstance, NULL);		//--- ������ ũ�� ���� ����
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
		SetTimer(hWnd, 1, 80, TimeProc);
		player.xPos = 0;
		player.yPos = 400;
		player.rect.left = 0;
		player.rect.right = 85;
		player.rect.top = 400;
		player.rect.bottom = 505;
		player.status = idle;
		player.direction = rightDir;
		player.isJump = FALSE;
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		printMemDC = CreateCompatibleDC(hdc);
		oldPrintHBIT = (HBITMAP)SelectObject(printMemDC, printHBIT);
		BitBlt(hdc, 0, 0, 1600, 900, printMemDC, 0, 0, SRCCOPY);
		SelectObject(printMemDC, oldPrintHBIT); DeleteDC(printMemDC);
		EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN:
		if (GetAsyncKeyState(VK_A))
		{
			if (player.status != jump)
			{
				player.status = runBack;
			}
		}
		if (GetAsyncKeyState(VK_D))
		{
			if (player.status != jump)
			{
				player.status = runFront;
			}
		}
		if (GetAsyncKeyState(VK_W))
		{
			player.status = jump;
		}
		break;
	case WM_KEYUP:
		if (player.status != jump)
		{
			player.status = idle;
		}
		break;
	case WM_MOUSEMOVE:
		// ���콺 ��ġ�� �������� �÷��̾� ���� ����
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

