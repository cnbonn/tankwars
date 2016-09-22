#ifndef DASH_H
#define DASH_H

#include <iostream>
using namespace std;

#include <GL/freeglut.h>

#include "drawingfuncs.h"

void drawDash(int player, int velocity, int angle, int ScreenWidth, int ScreenHeight);
void drawAngle();
void drawVelocity();
void drawPlayer();

#endif
