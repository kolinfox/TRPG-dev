#include<iostream>
#include<string>
using namespace std;
struct MAP
{
	string MapName;
	string MonsterName;
};
MAP MapData;
int PrintMonster(int map)
{
	if (map == 0)
	{
		cout << "輸入1與轉轉鳥戰鬥   輸入2與小石怪戰鬥   輸入0返回\n";
		return 1;
	}
	else if (map == 1)
	{
		return 0;
	}
	else if (map == 2)
	{
		cout << "輸入1與哥布林小鬼戰鬥   輸入2與哥布林戰士戰鬥   輸入0返回\n";
		return 1;
	}

}
string Choose(int ck,int map)
{
	if (map == 0)
	{
		if (ck == 1)
		{
			return "轉轉鳥";
		}
		else if (ck == 2)
		{
			return "小石怪";
		}
		else
		{
			return "Wrong";
		}
	}
	else if (map == 2)
	{
		if (ck == 1)
		{
			return "哥布林小鬼";
		}
		else if (ck == 2)
		{
			return "哥布林戰士";
		}
		else
		{
			return "Wrong";
		}
	}
}
string where(int MapNumber)
{
	if (MapNumber == 0)
	{
		MapData.MapName = "探險發源地(LV1~3)";
		return MapData.MapName;
	}
	else if (MapNumber == 1)
	{
		MapData.MapName = "艾村";
		return MapData.MapName;
	}
	else if (MapNumber == 2)
	{
		MapData.MapName = "探險小徑(LV3~6)";
		return MapData.MapName;
	}
	else
	{
		return "none";
	}
}
int npc(int map)
{
	if (map == 0)
	{
		return 0;
	}
	else if (map == 1)
	{
		return 1;
	}
	else if (map == 2)
	{
		return 0;
	}
}
