#pragma once
#include "character.h"

// 플레이어 방향 상수
#define leftDir 0
#define rightDir 1

// 플레이어 상태 상수
#define idle 2
#define runFront 3
#define runBack 4
#define jump 5
#define die 6

extern PAINTSTRUCT ps;
extern HDC hdc;
extern HDC printMemDC, copyMemDC;
extern HBITMAP printHBIT, oldPrintHBIT, copyHBIT, oldCopyHBIT;
extern CHARACTER player;
extern POINT mouse;