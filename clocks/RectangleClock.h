#pragma once
#include "clock.h"
#include"Shape.h"
class RectangleClock :
	public Clock,public CShape
{
	
public:
	RectangleClock(int x,int y,int width,int height);
	RectangleClock(int x,int y,int width,int height,int h,int m,int s);
	~RectangleClock(void);
	void Draw();
};
