#include"acllib.h"
#include"CautoSprite.h"
#include"CusrSprite.h"
#include<stdlib.h>
#include<time.h>

const int winWidth = 880, winHeight = 600,width=100,height=100;
const int MAXNUM=50;
CautoSprite *autos[MAXNUM]={NULL};
CusrSprite *usr=NULL;
void timerEvent(int id);
void paintSprites();
void keyEvent(int key,int e);
int d=0;
int Setup()
{
	initWindow("load Image", DEFAULT, DEFAULT, winWidth, winHeight);
	srand((unsigned)time(NULL));
	int x,y,dx,dy;
	x=rand()%winWidth;
	y=rand()%winHeight;
	if(x>winWidth-width)x=winWidth-width;
	if(y>winHeight-height)y=winHeight-height;
	dx=dy=5;
	usr=new CusrSprite("dog.jpg",x,y,dx,dy,width,height,winWidth,winHeight);
	registerTimerEvent(timerEvent);
	startTimer(0,500);
	startTimer(1,50);
	registerKeyboardEvent(keyEvent);
	paintSprites();
	return 0;
}
void timerEvent(int id)
{
	switch(id)
	{
	case 0:
		if(d>=MAXNUM) return;
		int x,y,dx,dy;
		x=rand()%winWidth;
		y=rand()%winHeight;
		if(x>winWidth-width)x=winWidth-width;
		if(y>winHeight-height)y=winHeight-height;
		dx=rand()%5+1;
		dy=rand()%5+1;
		autos[d]=new CautoSprite("cat.jpg",x,y,dx,dy,width,height,winWidth,winHeight);
		if(autos[d]) 
			d++;

		break;
	case 1:
		for(int i=0;i<d;++i)
			if(autos[i]) 
				autos[i]->move();

		paintSprites();

		break;
	}
}
void paintSprites()
{
	int i;
	beginPaint();
	clearDevice();
	for(i=0;i<d;++i)
	{
		if(autos[i])
		{
			autos[i]->drawScale(width,height);
		}
	}
	usr->drawScale(width,height);
	endPaint();
}
void keyEvent(int key,int e)
{
	if(e!=KEY_DOWN)return;
	usr->keyMove(key);
	for(int i=0;i<d;++i)
	{
		if(autos[i])
		{
			if(usr->collision(*autos[i]))
			{
				delete autos[i];
				autos[i]=NULL;
			}
		}
	}
	paintSprites();
}