#include "RectangleClock.h"
#include "acllib.h"
#include "math.h"
RectangleClock::RectangleClock(int x,int y,int width,int height):Clock(),CShape(x,y,width,height)
{
	
}
RectangleClock::RectangleClock(int x,int y,int width,int height,int h,int m,int s):Clock(h,m,s),CShape(x,y,width,height)
{
	
}
RectangleClock::~RectangleClock(void)
{
}

void GetXY(int x0, int y0, int r, int jiaodu, int &x, int &y) {
	if((jiaodu>=0 && jiaodu<45)||(jiaodu>=315 && jiaodu<360)){
		x=x0+r*tan(RAD(jiaodu));
		y=y0-r;
	}
	else if(jiaodu>=45 && jiaodu<135){
		x=x0+r;
		y=y0+r/tan(RAD(jiaodu));
	}
	else if(jiaodu>=135 && jiaodu<225){
		x=x0+r*tan(RAD(jiaodu));
		y=y0+r;
	}
	else if(jiaodu>=225 && jiaodu<315){
		x=x0-r;
		y=y0+r/tan(RAD(jiaodu));
	}
}


void RectangleClock::Draw()
{
	int h,m,s;
	int x,y,width,height;
	GetShapeData(x,y,width,height);
	int ox =x+ width/2;//150;
	int oy =y+ height/2;//150;

	int min=width<height?width:height;
	int hl = min/4-min/7;//46;
	int ml = min/3-min/6;//74;
	int sl = min/2-min/5;//120;

	int i;
	GetTime (h,m,s);
	setPenWidth(2);
	setPenColor(BLACK);
	setBrushColor(WHITE);
	rectangle(x,y,x+width,y+height);

	// label
	setPenWidth(1);
	setPenColor(BLACK);

	int r1=width*6/16, r2=width*7/16;
	for(i=0;i<12;++i)
	{
		GetXY(ox, oy, r1, i*30, x, y);
		moveTo(x,y);
		GetXY(ox, oy, r2, i*30, x, y);
		lineTo(x,y);
	}	
/*	int len1=min/2-min/8,len2=len1+10;
	for(i=0;i<12;++i)
	{
		moveTo(ox+len1*sin(RAD(180-i*30)),oy+len1*cos(RAD(180-i*30)));
		lineTo(ox+len2*sin(RAD(180-i*30)),oy+len2*cos(RAD(180-i*30)));
	}
*/
	// hour
	setPenWidth(8);
	setPenColor(BLACK);
	moveTo(ox,oy);
	lineTo(ox+hl*sin(RAD(180-h*30)),oy+hl*cos(RAD(180-h*30)));

	// minute
	setPenWidth(4);
	setPenColor(GREEN);
	moveTo(ox,oy);
	lineTo(ox+ml*sin(RAD(180-m*6)),oy+ml*cos(RAD(180-m*6)));

	// second
	setPenWidth(2);
	setPenColor(RED);
	moveTo(ox,oy);
	lineTo(ox+sl*sin(RAD(180-s*6)),oy+sl*cos(RAD(180-s*6)));

//	endPaint();
}
