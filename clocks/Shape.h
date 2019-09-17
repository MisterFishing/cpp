#pragma once

class CShape
{
	int x,y,width,height;
public:
	CShape(int x,int y,int w,int h);
	~CShape(void);
	void GetShapeData(int &x,int &y,int &width,int &height);
	void Draw(){};
};
