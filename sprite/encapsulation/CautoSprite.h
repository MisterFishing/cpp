#ifndef CautoSprite_h
#define CautoSprite_h

#include"acllib.h"

struct rect
{
	int x,y,width,height;
};
class CautoSprite
{
	ACL_Image img;	
	int x,y;
	int dx,dy;
	int width,height;
	int winWidth,winHeight;
public:
	//CautoSprite(void);
	CautoSprite(CautoSprite &);
	CautoSprite(char const *name,int x,int y,int dx,int dy,int w,int h,int wWidth,int wHeight);
	~CautoSprite(void);
	void move();
	void drawScale(int w,int h);
	struct rect getRect();
};

#endif
