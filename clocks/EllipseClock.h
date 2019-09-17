#pragma once
#include "clock.h"
#include"Shape.h"

class EllipseClock :
	public Clock,public CShape
{

	
public:
	EllipseClock(int x,int y,int width,int height);
	EllipseClock(int x,int y,int width,int height,int h,int m,int s);
	
	~EllipseClock(void);

	void Draw();
	

};
