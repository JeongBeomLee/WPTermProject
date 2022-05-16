#include <windows.h>
#include <atlImage.h>

#define left 0
#define right 1

typedef struct PLAYER {
	RECT rect;
	BOOL direction;
	int status;
	int hp;
}PLAYER;

typedef struct HAND {

}HAND;

HINSTANCE g_hInst;
TCHAR lpszClass[] = TEXT("TermProject");

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

PAINTSTRUCT ps;
HDC hdc;
HDC printMemDC, copyMemDC;
HBITMAP printHBIT, oldPrintHBIT, copyHBIT, oldCopyHBIT;
CImage img;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	static int count = 1;

	switch (iMessage) {
	case WM_CREATE:
		SetTimer(hWnd, 1, 100, NULL);
		hdc = GetDC(hWnd);

		if (printHBIT == NULL) printHBIT = CreateCompatibleBitmap(hdc, 1024, 768);

		printMemDC = CreateCompatibleDC(hdc);
		copyMemDC = CreateCompatibleDC(printMemDC);

		oldPrintHBIT = (HBITMAP)SelectObject(printMemDC, printHBIT);
		oldCopyHBIT = (HBITMAP)SelectObject(copyMemDC, copyHBIT);

		BitBlt(printMemDC, 0, 0, 17, 21, copyMemDC, 0, 0, SRCCOPY);

		SelectObject(copyMemDC, oldCopyHBIT); DeleteDC(copyMemDC);
		SelectObject(printMemDC, oldPrintHBIT); DeleteDC(printMemDC);
		ReleaseDC(hWnd, hdc);

		InvalidateRect(hWnd, NULL, false);
		break;
	case WM_TIMER:
		hdc = GetDC(hWnd);
		if (printHBIT == NULL) printHBIT = CreateCompatibleBitmap(hdc, 1024, 768);

		printMemDC = CreateCompatibleDC(hdc);
		copyMemDC = CreateCompatibleDC(printMemDC);

		oldPrintHBIT = (HBITMAP)SelectObject(printMemDC, printHBIT);
		oldCopyHBIT = (HBITMAP)SelectObject(copyMemDC, copyHBIT);

		BitBlt(printMemDC, 0, 0, 17, 21, copyMemDC, 0, 0, SRCCOPY);

		SelectObject(copyMemDC, oldCopyHBIT); DeleteDC(copyMemDC);
		SelectObject(printMemDC, oldPrintHBIT); DeleteDC(printMemDC);
		ReleaseDC(hWnd, hdc);
		InvalidateRect(hWnd, NULL, false);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		printMemDC = CreateCompatibleDC(hdc);
		oldPrintHBIT = (HBITMAP)SelectObject(printMemDC, printHBIT);

		StretchBlt(hdc, 0, 0, 85, 105, printMemDC, 0, 0, 17, 21, SRCCOPY);

		SelectObject(printMemDC, oldPrintHBIT); DeleteDC(printMemDC);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

