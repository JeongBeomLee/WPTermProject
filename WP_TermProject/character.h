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

// Ÿ�̸� ���ν��� �Լ�
void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT_PTR idEvnet, DWORD dwTime);

// ĳ���� ���� �Լ���
void CharIdle();
void CharRunFront();
void CharRunBack();
void CharJump();
void CharDown();