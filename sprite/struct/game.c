//#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"acllib.h"
#define MAXNUM 10
struct autoSprite
{
	int x,y;
	int dx,dy;
	int width,height;
	int bDead;
}sprites[MAXNUM];
const int winWidth = 880, winHeight = 600;
ACL_Image img;
struct usrSprite
{
	int x,y;
	int dx,dy;
	ACL_Image img;
	int width,height;
	
}usr;
void initSprites();
void initUsr();
void timerEvent(int id);
void paintSprites();
void keyEvent(int key,int e);
int collision(struct usrSprite r1, struct autoSprite r2);
void JudgeCollision();
int Setup()
{
	initWindow("load Image", DEFAULT, DEFAULT, winWidth, winHeight);
	srand((unsigned)time(NULL));
	loadImage("cat.jpg",&img);
	initUsr();	
	initSprites();
	paintSprites();
	registerTimerEvent(timerEvent);
	startTimer(0,50);
	registerKeyboardEvent(keyEvent);
	return 0;
}
void initSprites()
{
	int i=0;
	for(i=0;i<MAXNUM;++i)
	{
		sprites[i].width=sprites[i].height=70;
		sprites[i].x=rand()%winWidth;
		sprites[i].y=rand()%winHeight;
		if(sprites[i].x>=winWidth-sprites[i].width)
			sprites[i].x = winWidth-sprites[i].width;
		if(sprites[i].y>=winHeight-sprites[i].height)
		{
			sprites[i].y = winHeight-sprites[i].height;
		}
		sprites[i].dx=rand()%5+1;
		sprites[i].dy=rand()%5+1;
		sprites[i].bDead=0;
	}
}
void timerEvent(int id)
{
	int i;
	if(id==0)
	{
		for(i=0;i<MAXNUM;++i)
		{
			if(sprites[i].bDead==0)
			{
				if(sprites[i].x>=winWidth-sprites[i].width || sprites[i].x<=0)
					sprites[i].dx *= -1;
				if(sprites[i].y>=winHeight-sprites[i].height|| sprites[i].y<=0)
				{
					sprites[i].dy *= -1;
				} 
				sprites[i].x+=sprites[i].dx;
				sprites[i].y+=sprites[i].dy;
				
			}
		}
		JudgeCollision();
		paintSprites();
	}
}
void paintSprites()
{
	int i;
	beginPaint();
	clearDevice();
	for(i=0;i<MAXNUM;++i)
	{
		if(sprites[i].bDead==0)
		{
			putImageScale(&img,sprites[i].x,sprites[i].y,sprites[i].width,sprites[i].height);
		}
	}
	putImageScale(&usr.img,usr.x,usr.y,usr.width,usr.height);
	endPaint();
}
void initUsr()
{
	loadImage("dog.jpg",&usr.img);
	usr.x=rand()%winWidth;
	usr.y=rand()%winHeight;
	usr.width=usr.height=100;
	usr.dx=usr.dy=5;
	if(usr.x>=winWidth-usr.width)usr.x = winWidth-usr.width;
	if(usr.y>=winHeight-usr.height)usr.y = winHeight-usr.height;
}
void keyEvent(int key,int e)
{
	if(e!=KEY_DOWN)return;
	switch(key)
	{
	case VK_UP:usr.y-=usr.dy;
		if(usr.y<0)usr.y=0;
		break;
	case VK_DOWN:
		usr.y+=usr.dy;
		if(usr.y>=winHeight-usr.height)usr.y = winHeight-usr.height;
		break;
	case VK_LEFT:
		usr.x -=usr.dx;
		if(usr.x<=0)usr.x=0;
		break;
	case VK_RIGHT:
		usr.x+=usr.dx;
		if(usr.x>=winWidth-usr.width)usr.x = winWidth-usr.width;
		break;
	}
	JudgeCollision();
	paintSprites();
}
int collision(struct usrSprite r1, struct autoSprite r2){
int c = 1;
if (r1.x < r2.x && r1.x+r1.width >r2.x ){
if (r1.y > r2.y && r1.y<r2.y + r2.height  )return c;
if (r1.y <r2.y && r1.y + r1.height >r2.y)return c;
}
else{
if (r1.x > r2.x && r2.x + r2.width > r1.x)
{
if (r1.y > r2.y && r1.y<r2.y + r2.height)return c;
if (r1.y <r2.y && r1.y + r1.height >r2.y)return c;
}
}
c = 0;
return c;
}
void JudgeCollision()
{
	int i;
	for(i=0;i<MAXNUM;++i)
	{
		if(collision(usr,sprites[i]))
		{
			sprites[i].bDead=1;
		}
	}
}
