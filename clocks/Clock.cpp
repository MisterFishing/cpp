#include<iostream>
#include"Clock.h"
#include"acllib.h"
#include"time.h"
#include"math.h"
using namespace std;

//角度转换为弧度
double RAD(double x)
{
	return ((x)/360.0*2*3.1415926535);
}

Clock::Clock(void)
{
	time_t t;
	struct tm *tmm;
	t = time(NULL);
	tmm=localtime(&t);
	h=tmm->tm_hour;
	m=tmm->tm_min;
	s=tmm->tm_sec;
}

Clock::~Clock(void)
{
}

//根据指定时间初始化时钟
Clock::Clock(int h,int m,int s)
{
	this->h=h;
	this->m=m;
	this->s=s;
}

//根据已经存在的时钟初始化该时钟
Clock::Clock(Clock &c)
{
	h=c.h;
	m=c.m;
	s=c.s;
}

//设置时间
void Clock::SetTime(int h,int m,int s)
{
	this->h=h;
	this->m=m;
	this->s=s;
}

//获取时间
void Clock::GetTime(int &h,int &m,int &s)
{
	h=this->h;
	m=this->m;
	s=this->s;
}

void Clock::AddOneS()
{
	s++;
	if(s>=60)
	{
		m++;
		s=0;
		if(m>=60)
		{
			m=0;
			h++;
			if(h>=12)
			{
				h=0;
			}
		}
	}
}

