#include <windows.h>
#include <atlImage.h>
#include "basic.h"
#include "character.h"
#include "batRed.h"

void TimeProc(HWND hWnd, UINT uMsg, UINT_PTR idEvnet, DWORD dwTime)
{
	hdc = GetDC(hWnd);

	// �޸�DC�� ȣȯ�Ǵ� 1600 X 900 ��Ʈ���� �����.
	// �޸�DC�� HDC�� ȣȯ�ǰ��Ѵ�.
	// �޸�DC�� �����Ѵ�.
	printHBIT = CreateCompatibleBitmap(hdc, 1600, 900);
	printMemDC = CreateCompatibleDC(hdc);
	oldPrintHBIT = (HBITMAP)SelectObject(printMemDC, printHBIT);
	// �׸���
	printChar(); // ĳ����

	// ������Ʈ, DC �����ϱ�, ��ȿȭ ���� ����
	SelectObject(printMemDC, oldPrintHBIT); DeleteDC(printMemDC);
	ReleaseDC(hWnd, hdc);
	InvalidateRect(hWnd, NULL, false);
}