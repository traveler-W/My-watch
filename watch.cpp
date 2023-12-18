#include <graphics.h>
#include <stdio.h>
#include <Windows.h>
#include <easyx.h>
IMAGE ima[10];
char image[64];
IMAGE zz[28];
char zo[64];
void ZZ()
{
	for (int j = 0; j < 27; j++)
	{
		sprintf_s(zo, sizeof(zo), "תת_0%d.png", j);
		loadimage(&zz[j], zo, 50, 37, true);
	}
}
void lon(int u)
{
	putimage(1453, 145, &zz[u]);
	Sleep(100);
	u = u + 1;
	putimage(1453, 145, &zz[u]);
	Sleep(100);
	u = u + 1;
	putimage(1453, 145, &zz[u]);
	Sleep(100);
	u = u + 3;
	putimage(1453, 145, &zz[u]);
	Sleep(100);
	u = u + 3;
	putimage(1453, 145, &zz[u]);
	Sleep(100);
	u = u + 4;
	putimage(1453, 145, &zz[u]);
	Sleep(100);
	u = u + 4;
	putimage(1453, 145, &zz[u]);
	Sleep(100);
	u = u + 4;
	putimage(1453, 145, &zz[u]);
	Sleep(100);
	u = u + 4;
	putimage(1453, 145, &zz[u]);
	Sleep(100);
	u = u + 1;
	putimage(1453, 145, &zz[u]);
	Sleep(100);
	u = u + 1;
}
void drawsecond()
{
	for (int i = 0; i < 10; i++)
	{
		sprintf_s(image, sizeof(image), "%d.png", i);
		loadimage(&ima[i], image, 20, 20, true);
	}
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	int s1, s2;
	s1 = sys.wSecond / 10;
	s2 = sys.wSecond % 10;
	putimage(1455, 110, &ima[s1]);
	putimage(1475, 110, &ima[s2]);
}
void drawminute()
{
	for (int i = 0; i < 10; i++)
	{
		sprintf_s(image, sizeof(image), "%d.png", i);
		loadimage(&ima[i], image, 30, 30, true);
	}
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	int m1, m2;
	m1 = sys.wMinute / 10;
	m2 = sys.wMinute % 10;
	putimage(1390, 100, &ima[m1]);
	putimage(1420, 100, &ima[m2]);
}
void drawhour()
{
	for (int i = 0; i < 10; i++)
	{
		sprintf_s(image, sizeof(image), "%d.png", i);
		loadimage(&ima[i], image, 40, 40, true);
	}
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	int h1, h2;
	h1 = sys.wHour / 10;
	h2 = sys.wHour % 10;
	putimage(1300, 90, &ima[h1]);
	putimage(1340, 90, &ima[h2]);
}
void drawwkend()
{
	settextcolor(RGB(135, 119, 85));
	settextstyle(30, 0, "����");
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	int w;
	w = sys.wDayOfWeek % 6;
	switch (w)
	{
	case 1:
		outtextxy(1320, 145, "һ");
		break;
	case 2:
		outtextxy(1320, 145, "��");
		break;
	case 3:
		outtextxy(1320, 145, "��");
		break;
	case 4:
		outtextxy(1320, 145, "��");
		break;
	case 5:
		outtextxy(1320, 145, "��");
		break;
	case 6:
		outtextxy(1320, 145, "��");
		break;
	case 0:
		outtextxy(1320, 145, "��");
		break;
	}
}

int main(void)
{
	initgraph(GetSystemMetrics(16), GetSystemMetrics(17));
	HWND hwnd = GetHWnd();
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) - WS_CAPTION);//�����ޱ�����
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, GetSystemMetrics(16), GetSystemMetrics(17), SWP_SHOWWINDOW);//�������ö�
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);//�����ڷֲ��Ա�����Ϊ͸��
	SetLayeredWindowAttributes(hwnd,
		RGB(0, 0, 0),//��ԭɫ
		0,//͸���ȣ�225Ϊ��͸��
		LWA_COLORKEY);//��ʾ�ķ�ʽ
	//����������Ϊ͸����������
	setbkcolor(RGB(0, 0, 0));
	cleardevice();
	//����������ͼ������
	IMAGE m;
	loadimage(&m, "11.png", 300, 300, true);//����ͼƬ
	ZZ();
	putimage(1250, 0, &m);//��ʾͼƬ
	setfillcolor(RGB(255, 255, 224));
	fillrectangle(1296, 133, 1383, 87);
	fillrectangle(1387, 133, 1452, 97);
	fillrectangle(1453, 133, 1497, 107);
	setfillcolor(RGB(225, 165, 0));
	fillrectangle(1382, 106, 1387, 112);
	fillrectangle(1382, 120, 1387, 126);
	settextcolor(RGB(135, 119, 85));
	settextstyle(30, 0, "����");
	outtextxy(1290, 145, "��");
	setlinecolor(RGB(0, 0, 0));
	setlinestyle(PS_SOLID, 47);
	circle(1400, 150, 158);
	circle(1400, 150, 190);
	while (1)
	{
		int u = 0;
		drawsecond();
		drawminute();
		drawhour();
		drawwkend();
		lon(u);
	}
	system("pause");
}