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
	// 모션 초기화
	if (motionIdle == 5)
	{
		motionIdle = 0;
	}
	// 이미지 변수와 이미지 이름 문자열 생성
	TCHAR charIdle[50];
	CImage charImage;
	// 플레이어 방향에 따라서 다른 이미지 출력
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
	// 오브젝트 해제, 모션 변경
	charImage.Destroy();
	++motionIdle;
}

void CharRunFront()
{
	// 모션 초기화
	if (motionRun == 8)
	{
		motionRun = 0;
	}
	// 이미지 변수와 이미지 이름 문자열 생성
	TCHAR charRun[50];
	CImage charImage;
	// 플레이어 방향에 따라서 다른 이미지 출력
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
	// 오브젝트 해제, 모션 변경
	player.xPos += 30;
	OffsetRect(&player.rect, 30, 0);
	charImage.Destroy();
	++motionRun;
}

void CharRunBack()
{
	// 모션 초기화
	if (motionRun == 8)
	{
		motionRun = 0;
	}
	// 이미지 변수와 이미지 이름 문자열 생성
	TCHAR charRun[50];
	CImage charImage;
	// 플레이어 방향에 따라서 다른 이미지 출력
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
	
	// 오브젝트 해제, 모션 변경
	player.xPos -= 30;
	OffsetRect(&player.rect, -30, 0);
	charImage.Destroy();
	++motionRun;
}

void CharJump()
{
	// 이미지 변수 생성
	CImage charImage;
	

	// 동시 키 입력 감지
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

	// 플레이어 방향에 따라서 다른 이미지 출력
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

	// 플레이어 위치 변경
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
	
	// 오브젝트 해제, 모션 변경
	charImage.Destroy();
}
