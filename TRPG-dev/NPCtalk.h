#include<iostream>
#include<string>
#include<time.h>
#include"Quest.h"
void SetColor(int f = 7, int b = 0)//好
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
		return "1.村民   2.農民   3.商人";
	}
}
int BuyOrNot(int MapNumber, int NPC)
{
	if (MapNumber == 1)
	{
		if (NPC == 3)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}
void NpcTK(int MapNumber,int NPC,int w)
{
	if (MapNumber == 1)
	{
		switch (NPC)
		{
		case 1:
			SetColor(5, 15);
			NpcSay("早安阿 今天真是風平浪靜");
			SetColor();
			cout << endl << endl;
			break;
		case 2:
			switch (w)
				{
				case 1:
					SetColor(5, 15);
					NpcSay("可惡的轉轉鳥和小石怪 不斷地破壞我的農作物");
					SetColor();
					break;
				case 2:
					SetColor(5, 15);
					NpcSay("可不可以幫我消滅一隻轉轉鳥和一隻小石怪? 而且帶給我一顆碎石和一根羽毛?");
					SetColor();
					break;
				case 99:
					SetColor(5, 15);
					NpcSay("謝謝你!");
					SetColor();
					break;
				}
			break;
		case 3:
			switch (w)
			{
				case 1:
					SetColor(5, 15);
					NpcSay("歡迎來看看呦!");
					SetColor();
					break;
				case 2:
					SetColor(5, 15);
					NpcSay("這裡的東西品質都很好的!");
					SetColor();
					break;
				case 3:
					SetColor(5, 15);
					NpcSay("我的錢包好像被轉轉鳥偷走了...可以幫我找回來嗎?");
					SetColor();
					break;
				case 99:
					SetColor(5, 15);
					NpcSay("真是謝謝你啊! 幫我找回了錢包");
					SetColor();
					break;
			}
			break;
		}
	}
}
