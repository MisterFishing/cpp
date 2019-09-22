#include "AutoSprite.h"

CAutoSprite::CAutoSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1,int score):SpriteBase(x,y,width,height,dx,dy,img,r1)
{
	this->score = score;
}
CAutoSprite::CAutoSprite(CAutoSprite &sprite):SpriteBase(sprite)
{
	score = sprite.score;
}

CAutoSprite::~CAutoSprite()
{
}
void CAutoSprite::move(rect r1)
{
	
	if (x<0 || x>(r.width - width)) dx *= -1;
	if (y<0 || y>(r.height - height)) dy *= -1;
	x += dx;
	y += dy;
	
}
int CAutoSprite::getScore()
{
	return score;
}
