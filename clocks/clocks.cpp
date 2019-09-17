#include "acllib.h"
#include "EllipseClock.h"
#include "RectangleClock.h"
#include <stdlib.h>
#include <math.h>

EllipseClock c1(430,30,250,250);
RectangleClock c2(30,30,250,250);

void timerEvent(int tid)
{
	beginPaint();
	clearDevice();
	c2.AddOneS();
	c2.Draw();
	c1.AddOneS();
	c1.Draw();
	endPaint();
}

int Setup()
{
    initWindow("Clock",DEFAULT,DEFAULT,800,300);
	registerTimerEvent(timerEvent);
	startTimer(0,1000);
	return 0;
}
