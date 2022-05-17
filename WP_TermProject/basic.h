#pragma once
#include "character.h"

#define leftDir 0
#define rightDir 1

extern PAINTSTRUCT ps;
extern HDC hdc;
extern HDC printMemDC, copyMemDC;
extern HBITMAP printHBIT, oldPrintHBIT, copyHBIT, oldCopyHBIT;
extern CHARACTER player;
extern POINT mouse;