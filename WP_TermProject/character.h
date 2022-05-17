#pragma once
#include "basic.h"

typedef struct CHARACTER {
	RECT rect;
	BOOL direction;
	BOOL isRun;
	BOOL isJump;
	int xPos, yPos;
	int status;
	int hp;
}CHARACTER;

typedef struct HAND {

}HAND;

void CALLBACK CharIdle(HWND hWnd, UINT uMsg, UINT_PTR idEvnet, DWORD dwTime);
void CALLBACK CharRunFront(HWND hWnd, UINT uMsg, UINT_PTR idEvnet, DWORD dwTime);
void CALLBACK CharRunBack(HWND hWnd, UINT uMsg, UINT_PTR idEvnet, DWORD dwTime);
void CharJumpUp(HWND hWnd);
void CharJumpDown(HWND hWnd);