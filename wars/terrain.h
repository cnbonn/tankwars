#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
using namespace std;

#include <vector>
#include <time.h>
#include <stdlib.h>
#include <tuple>
#include <cmath>

class Terrain
{
    private:
	float width;
	float height;
	float displacement;
	float roughness;
        int smoothness;	

	struct point
	{
	    float x;
	    float y;
	};
        vector<point> linepoints;
    
    public:
	Terrain(); //constuctor
	Terrain(float w, float h, float d, float r, int s); //copy constructor
	~Terrain(); //deconstructor
	int generate();
	void genpoints();
	void draw();
	void print();
	void printPoints();
};

#endif
