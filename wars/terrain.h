#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
using namespace std;

#include <vector>
#include <time.h>
#include <stdlib.h>
#include <tuple>
#include <cmath>
#include <GL/freeglut.h>
#include <random>

static float twidth;
static float theight;
static float troughness;
static int tsmoothness;	

// structure for points
struct point
{
    float x;
    float y;
};
static vector<point> linepoints; // vector for points

//functions
void initTerrain(float w, float h,float r, int s);     
int generate();
void genpoints();
void drawTerrain(int bumpup);
void print();
void printPoints();
double genrandom();
float randomnum(float x, float y);

#endif
