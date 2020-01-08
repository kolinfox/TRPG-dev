#include<iostream>
#include<string>
#include<time.h>
#include"Quest.h"
void SetColor(int f = 7, int b = 0)//我是多的程式碼
{
	unsigned short ForeColor = f + 16 * b;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, ForeColor);
}
using namespace std;
void NpcSay(string a)
{
	string b;
	for (int p = 0; p < a.length(); p+=2)
	{
		cout << b.assign(a, p, 2);
		Sleep(85);
	}
	cout << endl;
}
string Npc(int MapNumber)
{
	if (MapNumber == 1)
	{
		return "1.作者   2.一直害我出BUG的機掰NPC";
	}
}
void NpcTK(int MapNumber,int NPC)
{
	if (MapNumber == 1)
	{
		switch (NPC)
		{
		case 1:
			SetColor(5, 15);
			NpcSay("早安 感謝KolinFox讓我們有更快速建立對話的方法");
			NpcSay("第二行測試 再次感謝狐玲賽高");
			SetColor();
			cout << endl << endl;
			break;
		case 2:
			SetColor(5, 15);
			NpcSay("可不可以幫我消滅一隻轉轉鳥和一隻小石怪? 而且帶給我一顆碎石和一根羽毛");
			SetColor();
			break;
		}
	}
}
