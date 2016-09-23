#ifndef TANK_H
#define TANK_H

#include <iostream>
using namespace std;

#include <GL/freeglut.h>

#include "drawingfuncs.h"
#include "terrain.h"

void initTank();
void drawTank(int x, int bumpup);
int calcHeight(int x);

#endif
