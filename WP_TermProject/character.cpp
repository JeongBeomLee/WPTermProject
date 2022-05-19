#include <windows.h>
#include <atlImage.h>
#include "basic.h"
#include "character.h"
int motionIdle = 0;
int motionRun = 0;
int motionJump = 0;
int motionDown = 0;

void printChar()
{
	switch (player.status)
	{
	case idle:
		CharIdle();
		break;
	case runFront:
		CharRunFront();
		break;
	case runBack:
		CharRunBack();
		break;
	case jump:
		if (player.isJump)
		{
			CharJump();
		}
		if (player.isDown)
		{
			CharDown();
		}
		break;
	}
}

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

void CharIdle()
{
	// ��� �ʱ�ȭ
	if (motionIdle == 5)
	{
		motionIdle = 0;
	}
	// �̹��� ������ �̹��� �̸� ���ڿ� ����
	TCHAR charIdle[50];
	CImage charImage;
	// �÷��̾� ���⿡ ���� �ٸ� �̹��� ���
	if (player.direction == leftDir)
	{
		wsprintf(charIdle, L"char//charidleleft//CharIdle%d.png", motionIdle);
		charImage.Load(charIdle);
		charImage.Draw(printMemDC, player.xPos, player.yPos, 85, 105, 0, 0, 17, 21);
	}
	else if (player.direction == rightDir)
	{
		wsprintf(charIdle, L"char//charidleright//CharIdle%d.png", motionIdle);
		charImage.Load(charIdle);
		charImage.Draw(printMemDC, player.xPos, player.yPos, 85, 105, 0, 0, 17, 21);
	}
	// ������Ʈ ����, ��� ����
	charImage.Destroy();
	++motionIdle;
}

void CharRunFront()
{
	// ��� �ʱ�ȭ
	if (motionRun == 8)
	{
		motionRun = 0;
	}
	// �̹��� ������ �̹��� �̸� ���ڿ� ����
	TCHAR charRun[50];
	CImage charImage;
	// �÷��̾� ���⿡ ���� �ٸ� �̹��� ���
	if (player.direction == leftDir)
	{
		wsprintf(charRun, L"char//charrunleft//CharRun%d.png", motionRun);
		charImage.Load(charRun);
		charImage.Draw(printMemDC, player.xPos, player.yPos, 85, 105, 0, 0, 17, 21);
	}
	else if (player.direction == rightDir)
	{
		wsprintf(charRun, L"char//charrunright//CharRun%d.png", motionRun);
		charImage.Load(charRun);;
		charImage.Draw(printMemDC, player.xPos, player.yPos, 85, 105, 0, 0, 17, 21);
	}
	// �÷��̾� ��ġ�� RECT ����
	player.xPos += 30;
	OffsetRect(&player.rect, 30, 0);
	// ������Ʈ ����, ��� ����
	charImage.Destroy();
	++motionRun;
}

void CharRunBack()
{
	// ��� �ʱ�ȭ
	if (motionRun == 8)
	{
		motionRun = 0;
	}
	// �̹��� ������ �̹��� �̸� ���ڿ� ����
	TCHAR charRun[50];
	CImage charImage;
	// �÷��̾� ���⿡ ���� �ٸ� �̹��� ���
	if (player.direction == leftDir)
	{
		wsprintf(charRun, L"char//charrunleft//CharRun%d.png", motionRun);
		charImage.Load(charRun);
		charImage.Draw(printMemDC, player.xPos, player.yPos, 85, 105, 0, 0, 17, 21);
	}
	else if (player.direction == rightDir)
	{
		wsprintf(charRun, L"char//charrunright//CharRun%d.png", motionRun);
		charImage.Load(charRun);;
		charImage.Draw(printMemDC, player.xPos, player.yPos, 85, 105, 0, 0, 17, 21);
	}
	// �÷��̾� ��ġ�� RECT ����
	player.xPos -= 30;
	OffsetRect(&player.rect, -30, 0);
	// ������Ʈ ����, ��� ����
	charImage.Destroy();
	++motionRun;
}

void CharJump()
{
	// �̹��� ���� ����
	CImage charImage;
	// �÷��̾� ���⿡ ���� �ٸ� �̹��� ���
	if (player.direction == leftDir)
	{
		charImage.Load(L"char//charjumpleft//CharJump0.png");
		charImage.Draw(printMemDC, player.xPos, player.yPos, 85, 105, 0, 0, 17, 21);
	}
	else if (player.direction == rightDir)
	{
		charImage.Load(L"char//charjumpright//CharJump0.png");;
		charImage.Draw(printMemDC, player.xPos, player.yPos, 85, 105, 0, 0, 17, 21);
	}
	// �÷��̾� ��ġ�� RECT ����
	player.yPos -= 30;
	OffsetRect(&player.rect, 0, -30);
	// ������Ʈ ����, ��� ����
	charImage.Destroy();
	++motionJump;

	if (motionJump == 5)
	{
		player.isJump = FALSE;
		player.isDown = TRUE;
		motionJump = 0;
	}
}

void CharDown()
{
	// �̹��� ���� ����
	CImage charImage;
	// �÷��̾� ���⿡ ���� �ٸ� �̹��� ���
	if (player.direction == leftDir)
	{
		charImage.Load(L"char//charjumpleft//CharJump0.png");
		charImage.Draw(printMemDC, player.xPos, player.yPos, 85, 105, 0, 0, 17, 21);
	}
	else if (player.direction == rightDir)
	{
		charImage.Load(L"char//charjumpright//CharJump0.png");;
		charImage.Draw(printMemDC, player.xPos, player.yPos, 85, 105, 0, 0, 17, 21);
	}
	// �÷��̾� ��ġ�� RECT ����
	player.yPos += 30;
	OffsetRect(&player.rect, 0, +30);
	// ������Ʈ ����, ��� ����
	charImage.Destroy();
	++motionDown;

	if (motionDown == 5)
	{
		player.isDown = FALSE;
		motionDown = 0;
		player.status = idle;
	}
}
