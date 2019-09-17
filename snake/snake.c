#include <stdio.h>
#include <windows.h>
#include "acllib.h"
#include <stdlib.h>
#include <time.h> //用到产生随机数
#include <dos.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct FOOD {
	int x; //食物的横坐标;
	int y; //食物的纵坐标;
	int yes; //判断是否要出现食物;
} food; //定义食物的结构体

typedef struct SNAKE {
	int x[200];
	int y[200];
	int jieshu; //蛇的节数;
	int direction; //蛇的移动方向
	int life; //蛇的存活
} snake; //定义蛇的结构体

food Food;
snake Snake1, Snake2;

void over()
{
	cancelTimer(0);

	beginPaint();
	setTextBkColor(EMPTY);
	setTextSize(80);

	if(Snake1.life==0&&Snake2.life==0){
        if (Snake1.jieshu>Snake2.jieshu) {
            setTextColor(RED);
            paintText(180,150,"RED WIN");
        } else if (Snake1.jieshu<Snake2.jieshu) {
            setTextColor(BLUE);
            paintText(150,150,"BLUE WIN");
        } else {
            setTextColor(GREEN);
            paintText(100,150,"RED :) BLUE");
        }
	}else if(Snake1.life==0){
	    setTextColor(BLUE);
        paintText(150,150,"BLUE WIN");
	}else if(Snake2.life==0){
	    setTextColor(RED);
        paintText(180,150,"RED WIN");
	}

	endPaint();
}

void play() //游戏过程的函数
{
	int i;

	srand(time(NULL));
	if (Food.yes==0) { // 没有食物
		Food.x=rand()%WIDTH; //产生食物的随机x坐标
		Food.y=rand()%HEIGHT; //产生食物的随机y坐标
		while(Food.x%10!=0) {
			Food.x--; //判断食物的x坐标是否为整数，不是就调整
		}
		while(Food.y%10!=0) {
			Food.y--; //判断食物的y坐标是否为整数，不是就调整
		}
		Food.yes=1; //产生符合的坐标后，产生食物
	}

	for (i=Snake1.jieshu-1;i>0;i--) { //关键!!
		Snake1.x[i]=Snake1.x[i-1]; //蛇往前移动了，所以前一个坐标给到后一个坐标
		Snake1.y[i]=Snake1.y[i-1];
	}

	for (i=Snake2.jieshu-1;i>0;i--) { //关键!!
		Snake2.x[i]=Snake2.x[i-1]; //蛇往前移动了，所以前一个坐标给到后一个坐标
		Snake2.y[i]=Snake2.y[i-1];
	}

	switch (Snake1.direction) { //判断蛇头的移动方向，1234表示右左上下
		case 1:Snake1.x[0]+=10;break; //向右移动十格
		case 2:Snake1.x[0]-=10;break;
		case 3:Snake1.y[0]-=10;break;
		case 4:Snake1.y[0]+=10;break;
	}

	switch (Snake2.direction) { //判断蛇头的移动方向，1234表示右左上下
		case 1:Snake2.x[0]+=10;break; //向右移动十格
		case 2:Snake2.x[0]-=10;break;
		case 3:Snake2.y[0]-=10;break;
		case 4:Snake2.y[0]+=10;break;
	}

	//判断蛇是否撞到自己
	for (i=1;i<Snake1.jieshu;i++) {
		if (Snake1.x[i]==Snake1.x[0]&&Snake1.y[i]==Snake1.y[0]) {
            Snake1.life=0; //蛇死亡的标志
        }
    }

	for (i=1;i<Snake2.jieshu;i++) {
		if (Snake2.x[i]==Snake2.x[0]&&Snake2.y[i]==Snake2.y[0]) {
            Snake2.life=0; //蛇死亡的标志
        }
	}

	//判断蛇是否撞到对方
	for (i=0;i<Snake1.jieshu;i++) {
		if (Snake1.x[i]==Snake2.x[0]&&Snake1.y[i]==Snake2.y[0]) {
            Snake2.life=0; //蛇死亡的标志
        }
    }

	for (i=0;i<Snake2.jieshu;i++) {
		if (Snake2.x[i]==Snake1.x[0]&&Snake2.y[i]==Snake1.y[0]) {
            Snake1.life=0; //蛇死亡的标志
        }
	}

	//判断蛇是否出现撞墙的情况
	if (Snake1.x[0]<0||Snake1.x[0]>WIDTH-10||Snake1.y[0]<0||Snake1.y[0]>HEIGHT-10) {
		Snake1.life=0;
	}

	if (Snake2.x[0]<0||Snake2.x[0]>WIDTH-10||Snake2.y[0]<0||Snake2.y[0]>HEIGHT-10) {
		Snake2.life=0;
	}

	if(Snake1.life==0 || Snake2.life==0){
        over();
        return;
	}

	if (Snake1.x[0]==Food.x&&Snake1.y[0]==Food.y) {
		Food.yes=0; //产生新的食物
		Snake1.jieshu++; //蛇的身体加长一节
	}

	if (Snake2.x[0]==Food.x&&Snake2.y[0]==Food.y) {
		Food.yes=0; //产生新的食物
		Snake2.jieshu++; //蛇的身体加长一节
	}
}

void paint()
{
	int i;

    beginPaint();

    setBrushColor(GREEN);  // Food
    setBrushColor(GREEN);
    rectangle(Food.x,Food.y,Food.x+10,Food.y+10);

    setBrushColor(RED);  // Snake1
    setPenColor(RED);
    for (i=0;i<Snake1.jieshu;i++) {
    	rectangle(Snake1.x[i],Snake1.y[i],Snake1.x[i]+10,Snake1.y[i]+10);
	}
	setPenColor(WHITE);  // Snake1 Tail
	setBrushColor(WHITE);
	rectangle(Snake1.x[Snake1.jieshu-1], Snake1.y[Snake1.jieshu-1], Snake1.x[Snake1.jieshu-1]+10, Snake1.y[Snake1.jieshu-1]+10);

	setBrushColor(BLUE);  // Snake2
	setPenColor(BLUE);
    for (i=0;i<Snake2.jieshu;i++) {
    	rectangle(Snake2.x[i],Snake2.y[i],Snake2.x[i]+10,Snake2.y[i]+10);
	}
	setPenColor(WHITE);   // Snake2 Tail
	setBrushColor(WHITE);
	rectangle(Snake2.x[Snake2.jieshu-1], Snake2.y[Snake2.jieshu-1], Snake2.x[Snake2.jieshu-1]+10, Snake2.y[Snake2.jieshu-1]+10);
	endPaint();
}

void keyListener(int key, int event)
{
    if(key==0x26 && Snake1.direction!=4) {  //按键 ↑
    	Snake1.direction=3;
	}
    if(key==0x28 && Snake1.direction!=3) {  //按键 ↓
    	Snake1.direction=4;
	}
	if(key==0x25 && Snake1.direction!=1) {  //按键 ←
		Snake1.direction=2;
	}
	if(key==0x27 && Snake1.direction!=2) {  //按键 →
		Snake1.direction=1;
	}
	 if(key==0x45 && Snake2.direction!=4) {  //按键e ↑
    	Snake2.direction=3;
	}
    if(key==0x44 && Snake2.direction!=3) {  //按键d ↓
    	Snake2.direction=4;
	}
	if(key==0x53 && Snake2.direction!=1) {  //按键s ←
		Snake2.direction=2;
	}
	if(key==0x46 && Snake2.direction!=2) {  //按键f →
		Snake2.direction=1;
	}
}

void timerListener(int id) //Timer定时器
{
	play();
	paint();
}

int Setup()
{
	initWindow("Snake Fighting", 300,100,WIDTH,HEIGHT); //画游戏界面
	Food.yes=0; //初始化一开始没有食物

	Snake1.life=1;
	Snake1.jieshu=20; //一开始蛇的节数
	Snake1.x[0]=WIDTH-10;
	Snake1.y[0]=HEIGHT/2-10;
	Snake1.direction=2; //一开始蛇的方向是向左

	Snake2.life=1;
	Snake2.jieshu=20; //一开始蛇的节数
	Snake2.x[0]=0;
	Snake2.y[0]=HEIGHT/2-10;
	Snake2.direction=1; //一开始蛇的方向是向右

	registerKeyboardEvent(keyListener);
	registerTimerEvent(timerListener);

	startTimer(0,100);
	return 0;
}
