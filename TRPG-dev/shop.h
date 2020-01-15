#include<iostream>
using namespace std;
void shop(int Map,int ckk)
{
	if (Map == 1 and ckk == 3)
	{
		cout << "\n輸入1買道具 輸入2賣道具\n";
	}
}
string shoplist(int Map, int ckk,int money)
{
	if (Map == 1 and ckk == 3)
	{
		string list[10] = {"紅色藥水","藍色藥水","end" };
		int moneylist[10] = { 50,50 };
		string effect[10] = { "恢復點生命","恢復點魔力" };
		for (int k = 0; list[k] != "end"; k++)
		{
			cout << k + 1 << "." << list[k] << setw(15) << effect[k]<<setw(10)<<moneylist[k] << "艾斐幣" << endl << endl;
		}
		cout  << "艾斐幣:" << money;
		cout << "\n\n輸入道具代號來購買 輸入0返回\n";
		int g;
		cin >> g;
		while (g < 0 or g>=3)
		{
			cout<<"\n請重新輸入!\n";
			cin >> g;
		}

		if (g == 0)return "stop";
		return list[g - 1];
	}
}
int ItemMoney(string ItemName)
{
	if (ItemName == "紅色藥水")return 50;
	if (ItemName == "藍色藥水")return 50;
}