#include<iostream>
#include<string>
#include<time.h>
using namespace std;
int p;
int HisHP(string Monster)
{
	if (Monster == "小石怪")
	{
		return 135;
	}
	else if (Monster == "轉轉鳥")
	{
		return 90;
	}
	else if (Monster == "哥布林小鬼")
	{
		return 140;
	}
	else if (Monster == "哥布林戰士")
	{
		return 177;
	}
}
int HisDamage(string Monster)
{
	if (Monster == "小石怪")
	{
		return 12;
	}
	else if (Monster == "轉轉鳥")
	{
		return 9;
	}
	else if (Monster == "哥布林小鬼")
	{
		return 15;
	}
	else if (Monster == "哥布林戰士")
	{
		return 18;
	}
}
int HisEXP(string Monster)
{
	if (Monster == "小石怪")
	{
		return 35;
	}
	else if (Monster == "轉轉鳥")
	{
		return 30;
	}
	else if (Monster == "哥布林小鬼")
	{
		return 35;
	}
	else if (Monster == "哥布林戰士")
	{
		return 40;
	}
}
int HisSkill(string Monster)
{
	srand(time(NULL));
	p = ((rand() * rand()) % 1648) % 100;
	if (Monster == "小石怪")
	{
		return 0;
	}
	else if (Monster == "轉轉鳥")
	{
		if (p >= 20)
		{
			return 0;
		}
		else if (p < 20)
		{
			return 1;
		}
	}
	else if (Monster == "哥布林小鬼")
	{
		return 0;
	}
	else if (Monster == "哥布林戰士")
	{
		if (p >= 20)
		{
			return 0;
		}
		else if (p < 20)
		{
			return 1;
		}
	}
}
int LV(string MonsterName)
{
	if (MonsterName == "轉轉鳥")
	{
		return 1;
	}
	else if (MonsterName == "小石怪")
	{
		return 2;
	}
	else if (MonsterName == "哥布林小鬼")
	{
		return 3;
	}
	else if (MonsterName == "哥布林戰士")
	{
		return 4;
	}
}
float GetSkillDamage(string HisSkillName)
{
	if (HisSkillName == "二連啄")
	{
		return 2;
	}
	if (HisSkillName == "重捶")
	{
		return 1.5;
	}
}
int SpecialEffect(string Monster)
{
	srand(time(NULL));
	p = ((rand() * rand()) % 1608) % 100; //601是暈眩
	//if (Monster == "轉轉鳥")
	//{
	//	if (p < 10)
	//	{
	//		return 601;
	//	}
	//	else
	//	{
	//		return 0;
	//	}
	//}
}
string HisSkillName(string Monster)
{
	if (Monster == "小石怪")
	{
		return "none";
	}
	else if (Monster == "轉轉鳥")
	{
		return "二連啄";
	}
	else if (Monster == "哥布林小鬼")
	{
		return "none";
	}
	else if (Monster == "哥布林戰士")
	{
		return "重捶";
	}
}
string GetPrize(string MonsterName,int QuestOrNot ,int done)
{
	int p;
	if (MonsterName == "轉轉鳥")
	{
		p = (rand() * 35 % 352 * rand() + 32) % 100;
		if (QuestOrNot == 2 and done==0)
		{
			if (p >= 75)
			{
				cout << "你獲得了商人的錢包";
				return "商人的錢包";
			}
		}
		if (p >= 20)
		{
			cout << "你獲得了羽毛";
			return "羽毛";
		}
		else
		{
			return "none";
		}
	}
	else if (MonsterName == "小石怪")
	{
		p = (rand() * 35 % 352 * rand() + 32) % 100;
		if (p >= 20)
		{
			cout << "你獲得了碎石";
			return "碎石";
		}
		else
		{
			return "none";
		}
	}
	else if (MonsterName == "哥布林小鬼")
	{
		p = (rand() * 35 % 352 * rand() + 32) % 100;
		if (p >= 20)
		{
			cout << "你獲得了哥布林圖騰";
			return "哥布林圖騰";
		}
		else
		{
			return "none";
		}
	}
	else if (MonsterName == "哥布林戰士")
	{
		p = (rand() * 35 % 352 * rand() + 32) % 100;
		if (p >= 20)
		{
			cout << "你獲得了哥布林圖騰";
			return "哥布林圖騰";
		}
		else
		{
			return "none";
		}
	}
}
int GetCount(string MonsterName,int Quest)
{
	int p;
	if (MonsterName == "轉轉鳥")
	{
		if (Quest == 2)
		{
			cout << "!\n\n";
			return 1;
		}
		p = (rand() * 35 % 352 * rand() + 32) % 100;
		if (p >= 50)
		{
			cout << "x2!\n\n";
			return 2;
		}
		else
		{
			cout << "!" << endl << endl;
			return 1;
		}
	}
	else if (MonsterName == "小石怪")
	{
		p = (rand() * 35 % 352 * rand() + 32) % 100;
		if (p >= 50)
		{
			cout << "x2!\n\n";
			return 2;
		}
		else
		{
			cout << "!\n\n";
			return 1;
		}
	}
	else if (MonsterName == "哥布林小鬼")
	{
		p = (rand() * 35 % 352 * rand() + 32) % 100;
		if (p >= 50)
		{
			cout << "x2!\n\n";
			return 2;
		}
		else
		{
			cout << "!\n\n";
			return 1;
		}
	}
	else if (MonsterName == "哥布林戰士")
	{
		p = (rand() * 35 % 352 * rand() + 32) % 100;
		if (p >= 50)
		{
			cout << "x2!\n\n";
			return 2;
		}
		else
		{
			cout << "!\n\n";
			return 1;
		}
	}
}

