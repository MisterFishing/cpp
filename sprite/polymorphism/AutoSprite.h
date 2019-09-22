#ifndef AutoSprite_h
#define AutoSprite_h

#include "SpriteBase.h"

class CAutoSprite :
	public SpriteBase
{
	int score;
public:
	CAutoSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1,int score);
	CAutoSprite(CAutoSprite &sprite);
	~CAutoSprite();

	void move(rect r);
	int getScore();
};

#endif
