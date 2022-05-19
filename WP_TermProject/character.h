#pragma once
#include "basic.h"

typedef struct CHARACTER {
	RECT rect;
	BOOL direction;
	BOOL isJump;
	BOOL isDown;

	int xPos, yPos;
	int status;
	int hp;
}CHARACTER;

typedef struct HAND {

}HAND;

// 타이머 프로시저 함수
void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT_PTR idEvnet, DWORD dwTime);

// 캐릭터 관련 함수들
void CharIdle();
void CharRunFront();
void CharRunBack();
void CharJump();
void CharDown();