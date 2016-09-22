#ifndef DASH_H
#define DASH_H

#include <iostream>
using namespace std;

#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "drawingfuncs.h"

static int SWidth, SHeight;

void initDash(int ScreenWidth, int ScreenHeight);
void drawDash(int player, int velocity, int angle);
void drawAngle(int angle);
void drawVelocity(int velocity);
void drawPlayer(const char *string, int player);

#endif
