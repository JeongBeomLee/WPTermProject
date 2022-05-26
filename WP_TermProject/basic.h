#pragma once
#include "character.h"

// 방향 상수
#define leftDir 0
#define rightDir 1

// 상태 상수
#define idle 2
#define runFront 3
#define runBack 4
#define jump 5
#define die 6

#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44

// 외부 변수 선언
extern PAINTSTRUCT ps;
extern HDC hdc;
extern HDC printMemDC, copyMemDC;
extern HBITMAP printHBIT, oldPrintHBIT, copyHBIT, oldCopyHBIT;

// 플레이어 외부 변수
extern CHARACTER player;
extern POINT mouse;