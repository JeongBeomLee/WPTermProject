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

// ĳ���� ���� �Լ���
void printChar();
void CharIdle();
void CharRunFront();
void CharRunBack();
void CharJump();
void CharDown();