#pragma once
#include "character.h"

// ���� ���
#define leftDir 0
#define rightDir 1

// ���� ���
#define idle 2
#define runFront 3
#define runBack 4
#define jump 5
#define die 6

#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44

// �ܺ� ���� ����
extern PAINTSTRUCT ps;
extern HDC hdc;
extern HDC printMemDC, copyMemDC;
extern HBITMAP printHBIT, oldPrintHBIT, copyHBIT, oldCopyHBIT;

// �÷��̾� �ܺ� ����
extern CHARACTER player;
extern POINT mouse;