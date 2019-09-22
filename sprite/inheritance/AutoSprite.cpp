#include "AutoSprite.h"

CAutoSprite::CAutoSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1):SpriteBase(x,y,width,height,dx,dy,img,r1)
{
}
CAutoSprite::CAutoSprite(CAutoSprite &sprite):SpriteBase(sprite)
{

}

CAutoSprite::~CAutoSprite()
{
}
void CAutoSprite::move()
{
	x += dx;
	y += dy;
	if (x<r.x || x>(r.x + r.width - width))dx *= -1;
	if (y<r.y || y>(r.y + r.height - height))dy = -1;
}
