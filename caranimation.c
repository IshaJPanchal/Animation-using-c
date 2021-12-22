#include<stdio.h>
#include<graphics.h>
void b_fill(int,int,int,int);
void f_fill(int,int,int,int);
void main()
{
	int gd=DETECT,gm,x1,x2,y1,y2,tx=1;
	clrscr();
	initgraph(&gd,&gm,"C:/TURBOC3/BGI");
	x1=0,x2=50,y1=300,y2=325;
	while(x2!=640)
	{
		cleardevice();
		line(0,331,650,331);
		rectangle(x1,y1,x2,y2);
		setcolor(0);
		line(x1+6,y2,x1+18,y2);
		line(x2-6,y2,x2-18,y2);
		setcolor(15);
		circle(x1+12,y2,6);
		circle(x2-12,y2,6);
		f_fill(x1+1,y1+1,10,0);
	//printf("White colour:%d",getpixel(100,300));
		b_fill(x1+12,y2,8,15);
		b_fill(x2-12,y2,8,15);
		x1=x1+tx;
		x2=x2+tx;
		delay(50);
	}
	getch();
	closegraph();
}
void b_fill(int x,int y,int fc,int bc)
{
	if(getpixel(x,y)!=bc && getpixel(x,y)!=fc)
	{
		putpixel(x,y,fc);
		b_fill(x+1,y,fc,bc);
		b_fill(x-1,y,fc,bc);
		b_fill(x,y+1,fc,bc);
		b_fill(x,y-1,fc,bc);
		/*b_fill(x+1,y+1,fc,bc);
		b_fill(x+1,y-1,fc,bc);
		b_fill(x-1,y+1,fc,bc);
		b_fill(x-1,y-1,fc,bc);*/
	}
}
void f_fill(int x,int y,int fc,int oc)
{
	if(getpixel(x,y)==oc)
	{
		putpixel(x,y,fc);
		f_fill(x+1,y,fc,oc);
		f_fill(x-1,y,fc,oc);
		f_fill(x,y+1,fc,oc);
		f_fill(x,y-1,fc,oc);
	}
}
