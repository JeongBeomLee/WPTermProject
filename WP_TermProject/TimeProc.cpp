#include <windows.h>
#include <atlImage.h>
#include "basic.h"
#include "character.h"
#include "batRed.h"

void TimeProc(HWND hWnd, UINT uMsg, UINT_PTR idEvnet, DWORD dwTime)
{
	hdc = GetDC(hWnd);

	// 메모리DC와 호환되는 1600 X 900 비트맵을 만든다.
	// 메모리DC와 HDC를 호환되게한다.
	// 메모리DC를 선택한다.
	printHBIT = CreateCompatibleBitmap(hdc, 1600, 900);
	printMemDC = CreateCompatibleDC(hdc);
	oldPrintHBIT = (HBITMAP)SelectObject(printMemDC, printHBIT);
	// 그리기
	printChar(); // 캐릭터

	// 오브젝트, DC 해제하기, 무효화 영역 생성
	SelectObject(printMemDC, oldPrintHBIT); DeleteDC(printMemDC);
	ReleaseDC(hWnd, hdc);
	InvalidateRect(hWnd, NULL, false);
}