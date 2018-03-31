//****************************************************************************
//                            SK.Games | SK_Snake
//****************************************************************************

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<bios.h>
#include<dos.h>

#define up    18432
#define down  20480
#define right 19712
#define left  19200
#define esc   283

int x=40,y=13;
int a,b;
int s=0,z=0,k=20,p=10;
char nm[21];
int m[21],n[21],i;

void clean()
	{
	clrscr();
	int j,k;
	gotoxy(5,3);for(j=0;j<70;j++)cout<<(char)205;
	gotoxy(5,24);for(j=0;j<70;j++)cout<<(char)205;
	for(k=0;k<20;k++) {gotoxy(5,4+k);cout<<(char)186;}
	for(k=0;k<20;k++) {gotoxy(75,4+k);cout<<(char)186;}
	gotoxy(5,3);cout<<(char)201;
	gotoxy(5,24);cout<<(char)200;
	gotoxy(75,3);cout<<(char)187;
	gotoxy(75,24);cout<<(char)188;
	gotoxy(6,4);
	}
void blink(char str[])
	{
	textcolor(5+143);textbackground(BLUE);
	cprintf(str);
	textbackground(BLACK);textcolor(GREEN);
	}
void shut()
	{
	clean();
	gotoxy(35,13);blink("Sandeep Kumar");
	delay(2000);exit(0);
	}

void digest()
	{
	for(i=0;nm[i]!='\0';i++)
		{
		gotoxy(m[i],n[i]);
		cout<<nm[i];
		}
	}
void move()
	{
	for(i=0;nm[i]!='\0';i++)
		{
		m[i]=m[i+1];
		n[i]=n[i+1];
		}
	m[i]=x;n[i]=y;
	digest();
	}
void score(int x,int y,int &a,int &b)
	{
	if(x==a&&y==b)
		{
		a=random(68)+6;
		b=random(19)+4;
		s=s+p;
		z++;nm[z]='#';
		if(z==k)
			{
			clean();
			gotoxy(35,13);cout<<"You Win !!!";
			gotoxy(35,14);cout<<"Score : "<<s;
			delay(2000);shut();
			}
		m[i+1]=x;n[i+1]=y;
		digest();
		}
	else move();
	}
void dir(int key)
	{
	switch(key)
		{
		case right :x++;break;
		case left  :x--;break;
		case down  :y++;break;
		case up    :y--;break;
		case esc   :shut();break;
		}
	score(x,y,a,b);
	if((x<6||x>74)||(y<4||y>23))
		{
		clean();
		gotoxy(35,13);cout<<"You Loss!!!";
		gotoxy(35,14);cout<<"Score : "<<s;
		delay(2000);shut();
		}
	}
void stroke()
	{
	again:
	int key=bioskey(0);
	while(!kbhit())
		{
		clean();
		gotoxy(40,13);cout<<s;
		gotoxy(a,b);cout<<"*";
		dir(key);
		delay(75);
		}
	goto again;
	}
void start()
	{
	clean();
	gotoxy(32,13);cout<<"Welcome To SK.Games";delay(1000);
	clean();
	gotoxy(37,13);cout<<"SK_Snake";delay(1000);
	clean();
	nm[0]='#';m[0]=x,n[0]=y;
	gotoxy(m[0],n[0]);
	cout<<nm[z];
	randomize();
	a=random(68)+6;
	b=random(19)+4;
	stroke();
	}
void main()
	{
	_setcursortype(_NOCURSOR);
	textcolor(GREEN);
	start();
	getch();
	}