#include <windows.h>
#include <atlImage.h>
#include "basic.h"
#include "character.h"
int motionIdle = 0;
int motionRun = 0;

void CharIdle(HWND hWnd, UINT uMsg, UINT_PTR idEvnet, DWORD dwTime)
{
	if (motionIdle == 5)
	{
		motionIdle = 0;
	}

	
	if (player.direction == leftDir)
	{
		hdc = GetDC(hWnd);
		TCHAR charIdle[50];
		CImage charImage;

		wsprintf(charIdle, L"char//charidleleft//CharIdle%d.png", motionIdle);
		charImage.Load(charIdle);

		printHBIT = CreateCompatibleBitmap(hdc, 1600, 900);

		printMemDC = CreateCompatibleDC(hdc);
		oldPrintHBIT = (HBITMAP)SelectObject(printMemDC, printHBIT);
		Rectangle(printMemDC, 0, 0, 1600, 1600);
		charImage.Draw(printMemDC, player.xPos, player.yPos, 85, 105, 0, 0, 17, 21);

		charImage.Destroy();
		SelectObject(printMemDC, oldPrintHBIT); DeleteDC(printMemDC);
		ReleaseDC(hWnd, hdc);
		++motionIdle;
		InvalidateRect(hWnd, NULL, false);
	}
	else if (player.direction == rightDir)
	{
		hdc = GetDC(hWnd);
		TCHAR charIdle[50];
		CImage charImage;

		wsprintf(charIdle, L"char//charidleright//CharIdle%d.png", motionIdle);
		charImage.Load(charIdle);

		printHBIT = CreateCompatibleBitmap(hdc, 1600, 900);

		printMemDC = CreateCompatibleDC(hdc);
		oldPrintHBIT = (HBITMAP)SelectObject(printMemDC, printHBIT);
		Rectangle(printMemDC, 0, 0, 1600, 1600);
		charImage.Draw(printMemDC, player.xPos, player.yPos, 85, 105, 0, 0, 17, 21);

		charImage.Destroy();
		SelectObject(printMemDC, oldPrintHBIT); DeleteDC(printMemDC);
		ReleaseDC(hWnd, hdc);
		++motionIdle;
		InvalidateRect(hWnd, NULL, false);
	}
}

void CharRunFront(HWND hWnd, UINT uMsg, UINT_PTR idEvnet, DWORD dwTime)
{
	if (motionRun == 8)
	{
		motionRun = 0;
	}
	
	if (player.direction == leftDir)
	{
		hdc = GetDC(hWnd);
		TCHAR charRun[50];
		CImage charImage;

		wsprintf(charRun, L"char//charrunleft//CharRun%d.png", motionRun);
		charImage.Load(charRun);

		printHBIT = CreateCompatibleBitmap(hdc, 1600, 900);

		printMemDC = CreateCompatibleDC(hdc);
		oldPrintHBIT = (HBITMAP)SelectObject(printMemDC, printHBIT);
		Rectangle(printMemDC, 0, 0, 1600, 1600);
		charImage.Draw(printMemDC, player.xPos, player.yPos, 85, 105, 0, 0, 17, 21);

		charImage.Destroy();
		SelectObject(printMemDC, oldPrintHBIT); DeleteDC(printMemDC);
		ReleaseDC(hWnd, hdc);
		++motionRun;
		player.xPos += 15;
		OffsetRect(&player.rect, 15, 0);
		InvalidateRect(hWnd, NULL, false);
	}
	else if (player.direction == rightDir)
	{
		hdc = GetDC(hWnd);
		TCHAR charRun[50];
		CImage charImage;

		wsprintf(charRun, L"char//charrunright//CharRun%d.png", motionRun);
		charImage.Load(charRun);

		printHBIT = CreateCompatibleBitmap(hdc, 1600, 900);

		printMemDC = CreateCompatibleDC(hdc);
		oldPrintHBIT = (HBITMAP)SelectObject(printMemDC, printHBIT);
		Rectangle(printMemDC, 0, 0, 1600, 1600);
		charImage.Draw(printMemDC, player.xPos, player.yPos, 85, 105, 0, 0, 17, 21);

		charImage.Destroy();
		SelectObject(printMemDC, oldPrintHBIT); DeleteDC(printMemDC);
		ReleaseDC(hWnd, hdc);
		++motionRun;
		player.xPos += 15;
		OffsetRect(&player.rect, 15, 0);
		InvalidateRect(hWnd, NULL, false);
	}
}

void CharRunBack(HWND hWnd, UINT uMsg, UINT_PTR idEvnet, DWORD dwTime)
{
	if (motionRun == 8)
	{
		motionRun = 0;
	}

	if (player.direction == leftDir)
	{
		hdc = GetDC(hWnd);
		TCHAR charRun[50];
		CImage charImage;

		wsprintf(charRun, L"char//charrunleft//CharRun%d.png", motionRun);
		charImage.Load(charRun);

		printHBIT = CreateCompatibleBitmap(hdc, 1600, 900);

		printMemDC = CreateCompatibleDC(hdc);
		oldPrintHBIT = (HBITMAP)SelectObject(printMemDC, printHBIT);
		Rectangle(printMemDC, 0, 0, 1600, 1600);
		charImage.Draw(printMemDC, player.xPos, player.yPos, 85, 105, 0, 0, 17, 21);

		charImage.Destroy();
		SelectObject(printMemDC, oldPrintHBIT); DeleteDC(printMemDC);
		ReleaseDC(hWnd, hdc);
		++motionRun;
		player.xPos -= 15;
		OffsetRect(&player.rect, -15, 0);
		InvalidateRect(hWnd, NULL, false);
	}
	else if (player.direction == rightDir)
	{
		hdc = GetDC(hWnd);
		TCHAR charRun[50];
		CImage charImage;

		wsprintf(charRun, L"char//charrunright//CharRun%d.png", motionRun);
		charImage.Load(charRun);

		printHBIT = CreateCompatibleBitmap(hdc, 1600, 900);

		printMemDC = CreateCompatibleDC(hdc);
		oldPrintHBIT = (HBITMAP)SelectObject(printMemDC, printHBIT);
		Rectangle(printMemDC, 0, 0, 1600, 1600);
		charImage.Draw(printMemDC, player.xPos, player.yPos, 85, 105, 0, 0, 17, 21);

		charImage.Destroy();
		SelectObject(printMemDC, oldPrintHBIT); DeleteDC(printMemDC);
		ReleaseDC(hWnd, hdc);
		++motionRun;
		player.xPos -= 15;
		OffsetRect(&player.rect, -15, 0);
		InvalidateRect(hWnd, NULL, false);
	}
}
