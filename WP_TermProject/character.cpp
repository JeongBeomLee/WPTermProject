#include <windows.h>
#include <atlImage.h>
#include "basic.h"
#include "character.h"
int motionIdle = 0;
int motionRun = 0;
int motionJump = 0;

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
		CharJump();
		break;
	}
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
	// ������Ʈ ����, ��� ����
	player.xPos += 30;
	OffsetRect(&player.rect, 30, 0);
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
	
	// ������Ʈ ����, ��� ����
	player.xPos -= 30;
	OffsetRect(&player.rect, -30, 0);
	charImage.Destroy();
	++motionRun;
}

void CharJump()
{
	// �̹��� ���� ����
	CImage charImage;
	

	// ���� Ű �Է� ����
	if (GetAsyncKeyState(VK_A))
	{
		player.xPos -= 20;
		OffsetRect(&player.rect, -20, 0);
	}
	if (GetAsyncKeyState(VK_D))
	{
		player.xPos += 20;
		OffsetRect(&player.rect, +20, 0);
	}

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

	// �÷��̾� ��ġ ����
	if (motionJump < 5)
	{
		player.yPos -= 50;
		OffsetRect(&player.rect, 0, -50);
		++motionJump;
	}
	if (motionJump >= 5)
	{
		player.yPos += 50;
		OffsetRect(&player.rect, 0, 50);
		++motionJump;
		if (motionJump == 10)
		{
			motionJump = 0;
			player.status = idle;
		}
	}
	
	// ������Ʈ ����, ��� ����
	charImage.Destroy();
}
