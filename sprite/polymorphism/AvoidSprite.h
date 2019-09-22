#ifndef AvoidSprite_h
#define AvoidSprite_h

#include"acllib.h"
#include "AutoSprite.h"

class CAvoidSprite :
	public CAutoSprite
{
	int oldx, oldy;
	bool danger(rect ur);
	bool bfirst;
public:
	CAvoidSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1,int score);
	CAvoidSprite(CAvoidSprite &sprite);
	virtual ~CAvoidSprite();

	void move(rect ur);
};

#endif
