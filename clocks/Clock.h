#ifndef __CLOCK_H__
#define __CLOCK_H__

double RAD(double x);

class Clock
{
private:
	int h,m,s,z;

public:
	Clock(void);
	//根据指定时间初始化时钟
	Clock(int h,int m,int s);
	//根据已经存在的时钟初始化该时钟
	Clock(Clock &);
	~Clock(void);
	//设置时间
	void SetTime(int h,int m,int s);
	//获取时间
	void GetTime(int &h,int &m,int &s);
	//时间增加1秒
	void AddOneS();
};
	
#endif

