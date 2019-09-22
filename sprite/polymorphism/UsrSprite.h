#ifndef UsrSprite_h
#define UsrSprite_h

#include "SpriteBase.h"

class CUsrSprite :
	public SpriteBase
{
	int score;
public:
	CUsrSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1);
	CUsrSprite(CUsrSprite &sprite);
	~CUsrSprite();

//	void move(int x,int y);
	void move(int key);
	void move(rect r);

	int collision(rect r1);
	int getScore();
	void setScore(int s);
	void addScore(int m);
};

#endif
