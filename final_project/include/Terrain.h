#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "TerrainBlock.h"

#ifndef TERRAIN_H
#define TERRAIN_H
 
#define RT3DIV2    0.8660254f  //used for translation from square to triangle space
#define RT3DIV3    0.5773503f  //used for translate from traingle to square space

class Terrain
{

	TerrainBlock **blocks;   //the blocks of terrain
	int n;  //the dimension of the terrain.  How many blocks (nxn) we have
	int N;  //the number of sub blocks in a triangle block.  = (1 << (d-1));
	int d;  // the max depth to which the blocks are rendered
	float H;  //the roughness value for the blocks
	float minHeight;  //the min starting height of block generation  
	float maxHeight;  //the max starting height of block generation
	float blockLength;  //how long a block's side length is

public:
	Terrain(int numBlocksSide, int depth, float roughness, float minheight, float maxheight, float blocklength);
	~Terrain();

	int getN();
	int getD();
	TerrainBlock *getBlockAtXY(float x, float y);
	TerrainBlock *getBlockAtST(float s, float t);
	TerrainBlock *getBlock(int s, int t);
	TerrainBlock *getBlockAt(int s, int t, int S, int T);
	float xToS(float x, float y);
	float yToT(float x, float y);
	float sToX(float s, float t);
	float tToY(float s, float t);
	float getSideLength();
	float getTerrainSideLength();
};

#endif