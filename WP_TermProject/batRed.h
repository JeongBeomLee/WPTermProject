#pragma once
#include "basic.h"

typedef struct BATFIREBALL {
	RECT rect;
	int fireBallMotion, boomMotion, xIncrease, yIncrease;
	int damage, start;
	BOOL touch;
}BATFIREBALL;

typedef struct BAT {
	RECT rect;

	BATFIREBALL fireBall;

	int xPos, yPos;
	int motion, direction, HP, ver, Map;
	int batMotion, batAttMotion, batAttMotionCharge, batTimer, randomMove;
}BAT;

int playerXAim(int bX, int cX);
int playerYAim(int bY, int cY);
BOOL contactCharater(BATFIREBALL fire, CHARACTER c);
BATFIREBALL fireBallPic(HWND hWnd, HDC mdc, BAT b);
BATFIREBALL boomPic(HWND hWnd, HDC mdc, BAT b);

BAT batPic(HWND hWnd, HDC mdc, int xPos, int yPos, BAT batRed, CHARACTER player);
BAT batAttPic(HWND hWnd, HDC mdc, int xPos, int yPos, BAT b, CHARACTER c);
int batWatchChar(int bXPos, int cXPos);
float lengthPts(BAT b, CHARACTER c);
BOOL inBatRange(BAT b, CHARACTER c);
BAT batMove(BAT b, CHARACTER c, int width, int height);
RECT returnRect(int x1, int x2, int y1, int y2);