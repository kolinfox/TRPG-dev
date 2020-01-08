#include<iostream>
#include<string>
using namespace std;
string armr(string job,int damage,int str,int dex,int iq)//不用理這裡
{
	if (job == "fighter" and damage  == 3 and str == 5)
	{
		return "木劍";
	}
	if (job == "fighter" and damage == 5 and str == 7)
	{
		return "高等劍";
	}
}
/////////////////////////////////////////更改下面就好
int Damage(string ItemName)//我是多的程式碼
{
	if (ItemName == "none")return 0;
	if (ItemName == "匕首")return 30;
	if (ItemName == "木杖")return 20;
	if (ItemName == "木弓") return 30;
	if (ItemName == "木劍") return 35;
	if (ItemName == "高等劍") return 50;
	if (ItemName == "新手上衣") return 0;
	if (ItemName == "新手褲子") return 0;
	if (ItemName == "高級頭盔") return 0;
}
int Def(string ItemName)
{
	if (ItemName == "none")return 0;
	if (ItemName == "木杖")return 0;
	if (ItemName == "木弓") return 0;
	if (ItemName == "木劍") return 0;
	if (ItemName == "匕首")return 0;
	if (ItemName == "高等劍") return 0;
	if (ItemName == "新手上衣") return 50;
	if (ItemName == "新手褲子") return 35;
	if (ItemName == "高級頭盔") return 150;
}
int Str(string ItemName)
{

	if (ItemName == "none")return 0;
	if (ItemName == "匕首")return 0;
	if (ItemName == "木杖")return 0;
	if (ItemName == "木弓") return 0;
	if (ItemName == "木劍") return 12;
	if (ItemName == "高等劍") return 20;
	if (ItemName == "新手上衣") return 0;
	if (ItemName == "新手褲子") return 0;
	if (ItemName == "高級頭盔") return 0;
}
int Dex(string ItemName)
{	
	if (ItemName == "木杖")return 0;
	if (ItemName == "none")return 0;
	if (ItemName == "匕首")return 0;
	if (ItemName == "木弓") return 16;
	if (ItemName == "木劍") return 0;
	if (ItemName == "高等劍") return 0;
	if (ItemName == "新手上衣") return 0;
	if (ItemName == "新手褲子") return 0;
	if (ItemName == "高級頭盔") return 0;
}
int Int(string ItemName)
{
	if (ItemName == "木杖")return 20;
	if (ItemName == "none")return 0;
	if (ItemName == "匕首")return 0;
	if (ItemName == "木弓") return 0;
	if (ItemName == "木劍") return 0;
	if (ItemName == "高等劍") return 0;
	if (ItemName == "新手上衣") return 0;
	if (ItemName == "新手褲子") return 0;
	if (ItemName == "高級頭盔") return 0;
}
int Luk(string ItemName)
{
	if (ItemName == "木杖")return 0;
	if (ItemName == "匕首")return 16;
	if (ItemName == "木弓") return 0;
	if (ItemName == "none")return 0;
	if (ItemName == "木劍") return 0;
	if (ItemName == "高等劍") return 0;
	if (ItemName == "新手上衣") return 0;
	if (ItemName == "新手褲子") return 0;
	if (ItemName == "高級頭盔") return 0;
}
int check(string ItemName)
{
	if (ItemName == "木杖")return 0;
	if (ItemName == "匕首")return 0;
	if (ItemName == "木弓") return 0;
	if (ItemName == "木劍") return 0;
	if (ItemName == "高等劍") return 0;
	if (ItemName == "新手上衣") return 2;
	if (ItemName == "新手褲子") return 3;
	if (ItemName == "高級頭盔") return 1;
}
int UseItem(string Item)
{
	if (Item == "艾草")
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int ItemHp(string Item)
{
	if (Item == "艾草")
	{
		return 50;
	}
}
