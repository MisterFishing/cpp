#ifndef CusrSprite_h
#define CusrSprite_h

#include"acllib.h"
#include"CautoSprite.h"

class CusrSprite
{
	ACL_Image img;	
	int x,y;
	int dx,dy;
	int width,height;
	int winWidth,winHeight;
public:
	CusrSprite(CusrSprite &);
	CusrSprite(char const *name,int x,int y,int dx,int dy,int w,int h,int wWidth,int wHeight);
	~CusrSprite(void);

	void keyMove(int key);
	int collision(CautoSprite &a); 
	void drawScale(int w,int h);
};

#endif
