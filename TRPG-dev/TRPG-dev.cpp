#include <iostream>
#include <fstream>
#include "item.h"
#include "map.h"
#include<iomanip>
#include<time.h>
#include"MonsterData.h"
#include<windows.h>
#include<math.h>
#include"NPCtalk.h"
using namespace std;
ofstream fo;
ifstream fw;
string X = "none";
string clothitem[50];
int map = 0;
int QuestCheck = 0;
int AllQuest[100];
int whatsquest;
int doneornot = 0;
string bag[100];
int bagcount[100];
int SaveNumber;
int npcm = 0;
struct Character
{
	string name;
	string job;
	string Head = X;
	string Armor = X;
	string Pants = X;
	string Shoes = X;
	string Gloves = X;
	string Armr = X;
	int HP = 0;
	int fightingHP = 0;
	int MP = 0;
	int exp = 0;
	int Money;
	int level = 0;
	int attack = 0;
	int realattack;
	int def = 0;
	int bdef = 0;
	int defsum = 0;//裝備防禦力總和
	int str = 0;
	int basicStr = 0;
	int dex = 0;
	int basicDex = 0;
	int luk = 0;
	int basicLuk = 0;
	int iq = 0;
	int basiciq = 0;
};
Character player;
int ps() //調整數字位數和空格的影響
{
	if (player.fightingHP >= 100000)
	{
		return -3;
	}
	else if (player.fightingHP >= 10000)
	{
		return -2;
	}
	else if (player.fightingHP >= 1000)
	{
		return -1;
	}
	else if (player.fightingHP >= 100)
	{
		return 0;
	}
	else if (player.fightingHP >= 10)
	{
		return 1;
	}
}
void HpLine(float y,float z,double MonsterHP,string Monster) //輸出血量和調整空格
{
	int f;
	y = (player.fightingHP * 100) / player.HP;
	z = (MonsterHP * 100) / HisHP(Monster);
	f = 15;
	for (int gg = 0; gg < y / 10; gg++)
	{
		SetColor(11, 0);
		cout << "▓";
		SetColor();
		f--;
	}
	cout << setw(2*f-2);
	for (int gg = 0; gg < z / 10; gg++)
	{
		SetColor(12, 0);
		cout << "▓";
		SetColor();
	}
	cout << setw(8);
}
void QuestDone(int ckk)
{
	doneornot = 0;
	cout << "\n獲得報酬!\n\n";
	for (int gg = 0; bag[gg] != "none"; gg++)
	{
		bagcount[gg] -= DeleteItemCount(bag[gg], whatsquest);
	}
	whatsquest = -1;
	QuestCheck = 0;
	AllQuest[Quest(where(map), ckk)] = 0;
	int money = 0;
	int exp = 0;
	string item = "";
	money = PrizeMoneyCheck(where(map), ckk);
	exp = PrizeExpCheck(where(map), ckk);
	item = PrizeItemCheck(where(map), ckk, player.job);
	if (money != 0)
	{
		cout << "獲得" << money << "元!\n";
		player.Money += money;
	}
	if (exp != 0)
	{

		cout << "獲得" << exp << "點經驗值!\n";
		player.exp += exp;
		while (player.exp >= 150 + pow(2, player.level * 0.35))
		{
			cout << "                           \\LEVEL UP!/" << endl;;
			player.exp -= 150 + pow(2, player.level * 0.35);
			player.fightingHP = player.HP;
			player.level++;
		}
	}
	if (item != "NULL")
	{
		cout << "獲得" << item << "!\n";
		int y = 0;
		for (int x = 0; clothitem[x] != "none"; x++)
		{
			y = x;
		}
		clothitem[y + 1] = item;
	}
}
void save()
{
	switch (SaveNumber)
	{
	case 1:
		fo.open("PlayerData.txt", ios::out);
		break;
	case 2:
		fo.open("PlayerData2.txt", ios::out);
		break;
	case 3:
		fo.open("PlayerData3.txt", ios::out);
		break;
	case 4:
		fo.open("PlayerData4.txt", ios::out);
		break;
	}
	fo << player.name << endl;
	fo << player.job << endl;
	fo << player.Head << endl;
	fo << player.Armor << endl;
	fo << player.Pants << endl;
	fo << player.Shoes << endl;
	fo << player.Gloves << endl;
	fo << player.Armr << endl;
	fo << player.HP << endl;
	fo << player.fightingHP << endl;
	fo << player.MP << endl;
	fo << player.level << endl;
	fo << player.exp << endl;
	fo << player.attack << endl;
	fo << player.realattack << endl;
	fo << player.def << endl;
	fo << player.bdef << endl;
	fo << player.str << endl;
	fo << player.basicStr << endl;
	fo << player.dex << endl;
	fo << player.basicDex << endl;
	fo << player.luk << endl;
	fo << player.basicLuk << endl;
	fo << player.iq << endl;
	fo << player.basiciq << endl;
	fo << map << endl;
	for (int oq = 1; oq < 50; oq++)
	{
		fo << clothitem[oq] << endl;
	}
	for (int pa = 1; pa < 100; pa++)
	{
		fo << AllQuest[pa] << endl;
	}
	fo << QuestCheck << endl;
	fo << whatsquest << endl;
	fo << doneornot << endl;
	for (int oqq = 0; oqq <= 99; oqq++)
	{
		fo << bag[oqq] << endl;
		fo << bagcount[oqq] << endl;
	}
	fo << player.Money << endl;
	fo.close();
}
int z;
void ingame()
{
	int owo = 0;
	cout << endl;
	while (1)
	{
		srand(time(NULL));
		cout << "K來戰鬥 輸入N前往下一張地圖 輸入L前往上一張地圖 C查看角色資料 \nS手動存檔 Q來換裝備 P查看該地NPC I查看道具欄 輸入其他按鍵離開" << endl;
		cout << "\n目前所在地:" << where(map) << endl << endl;
		save();
		if (owo == 1)
		{
			save();
			cout << "已離開 可能是錯誤或者手動離開" << endl;
			break;
		}
		owo = 1;
		if (player.job == "fighter")
		{
			player.basicStr = (player.level * 2.5);
			player.realattack = player.attack + (player.str / 4) + player.basicStr;
			player.bdef = (player.str / 3) + player.level * 3;
			player.def = player.bdef + player.defsum;
			player.HP = 450 + (player.level - 1) * 180;
			player.MP = 100 + (player.level - 1) * 50;
		}
		if (player.job == "shoter")
		{
			player.basicDex = (player.level * 2);
			player.realattack = player.attack + (player.dex / 4) + player.basicDex;
			player.bdef = (player.dex / 4) + player.level * 2;
			player.def = player.bdef + player.defsum;
			player.HP = 300 + (player.level - 1) * 130;
			player.MP = 100 + (player.level - 1) * 50;
		}
		if (player.job == "magic")
		{
			player.basiciq = player.level * 3;
			player.realattack = player.attack + (player.iq / 5) + player.basiciq;
			player.bdef = player.iq / 5 + player.level * 2;
			player.def = player.bdef + player.defsum;
			player.HP = 250 + (player.level - 1) * 100;
			player.MP = 300 + (player.level - 1) * 150;
		}
		if (player.job == "ninja")
		{
			player.basicLuk = player.level * 3;
			player.realattack = player.attack + (player.luk / 4) + player.basicLuk;
			player.bdef = player.luk / 4 + player.level * 2;
			player.def = player.bdef + player.defsum;
			player.HP = 350 + (player.level - 1) * 145;
			player.MP = 100 + (player.level - 1) * 50;
		}
		string move;
		cin >> move;
		if (move == "i" or move == "I")
		{
			system("cls");
			owo = 0;
			cout << "道具名稱" << setw(12) << "數量" << endl << endl;
			for (int x = 0; bag[x] != "none"; x++)
			{
				cout << x + 1 << "." << bag[x] << setw(20 - bag[x].length()) << bagcount[x] << endl << endl;
			}
			cout << "輸入左側代碼來使用道具\n";
			int ch;
			cin >> ch;
			if (UseItem(bag[ch - 1]) == -1)
			{
				cout << bag[ch - 1];
				cout << "無法使用" << endl;
			}
			else if (player.HP == player.fightingHP)cout << "血量已滿!\n";
			else if (UseItem(bag[ch - 1]) == 1)
			{
				int g = player.fightingHP;
				player.fightingHP += ItemHp(bag[ch - 1]);
				if (player.fightingHP > player.HP)player.fightingHP = player.HP;
				int gg = player.fightingHP;
				cout << "\n以回復" << gg - g << "點血量\n";
				bagcount[ch - 1]--;
			}
		}
		if (move == "P" or move == "p")
		{
			system("cls");
			if (npc(map) == 1)
			{
				int owowo = 0;
				cout << "\nNPC:" << Npc(map) << setw(5);
				cout << "\n\n";
				cout << "請輸入欲對話的NPC代號 輸入0返回\n\n";
				int ckk;
				cin >> ckk;
				int w = 1;
				if (Quest(where(map), ckk) == 1 and Quest(where(map), ckk) != AllQuest[Quest(where(map), ckk)])
				{
					NpcTK(map, ckk, 99);
					cout << "\n\n";
				}
				else if (BuyOrNot(map, ckk) == 1 and (Quest(where(map), ckk) < 0))
				{
					cout << "\n對話按1 進入商店按2\n";
					cin >> w;
					NpcTK(map, ckk, w);
				}
				else if((BuyOrNot(map, ckk) == 1 and (Quest(where(map), ckk) >= 1)))
				{
					cout<<"\n對話按1 進入商店按2 查看任務按3\n";
					cin >> w;
					if (w == 1)
					{
						NpcTK(map, ckk, w);
					}
					else if (w == 2)
					{
						NpcTK(map, ckk, w);
						//shop
					}
					else if (QuestCheck==1 and whatsquest != AllQuest[Quest(where(map), ckk)])
					{
						cout << "\n請先完成目前所接的任務\n\n";
					}
					else if (doneornot == 1 and whatsquest != AllQuest[Quest(where(map), ckk)] and AllQuest[Quest(where(map), ckk)]==0)
					{
						NpcTK(map, ckk, 99);
					}
					else if (w == 3 and QuestCheck!=1)
					{
						if (AllQuest[Quest(where(map), ckk)] == 0)
						{
							NpcTK(map, ckk, 99);
						}
						else
						{
							NpcTK(map, ckk, w);
							cout << "\n是否要接取任務?(Y/N)\n";
							string ck;
							cin >> ck;
							if (ck == "Y" or ck == "y")
							{
								whatsquest = Quest(where(map), ckk);
								QuestCheck = 1;
								npcm = ckk;
							}
							else if (ck == "n" or ck == "N")
							{
								cout << "\n已拒絕\n";
							}
						}
					}
					else if (QuestCheck == 1 and doneornot!=1)
					{
						cout << "\n請先完成目前所接的任務\n\n";
					}
					else if (QuestCheck == 1 and whatsquest == Quest(where(map), ckk))
					{
						QuestDone(ckk);
					}
				}
				else if (Quest(where(map), ckk) >=1 and QuestCheck != 1)
				{
					cout << "對話按1 查看任務按下2 按0返回\n";
					cin >> w;
					if (w == 1)
					{
						NpcTK(map, ckk, w);
						cout << "\n\n";
					}
					else if (w == 2)
					{
						NpcTK(map, ckk,w);
						cout << "\n是否要接取任務?(Y/N)\n";
						string ck;
						cin >> ck;
						if (ck == "Y" or ck == "y")
						{
							whatsquest = Quest(where(map), ckk);
							QuestCheck = 1;
							npcm = ckk;
						}
						else if (ck == "n" or ck == "N")
						{
							cout << "\n已拒絕\n";
						}
					}

				}
				else if (Quest(where(map), ckk) == 0)
				{
					NpcTK(map, ckk,0);
				}
				else if (doneornot == 1 and whatsquest==Quest(where(map),ckk))
				{
					QuestDone(ckk);
				}
				else if (QuestCheck == 1)
				{
					cout << "\n請先完成目前所接的任務\n\n";
				}
			}
			else
			{
				cout << endl << "這裡沒有NPC\n\n";
			}
			owo = 0;
			save();
		}
		if (move == "L" or move == "l")
		{
			system("cls");
			if (map == 0)
			{
				cout << "已經在第一張地圖了\n";
			}
			else
			{
				map--;
			}
			owo = 0;
			save();
		}
		if (move == "N" or move == "n")
		{
			system("cls");
			if (where(map + 1) == "none")
			{
				cout << "已經在最後一張地圖了 請等待日後開放\n";
			}
			else
			{
				map++;
			}
			owo = 0;
			save();
		}
		if (move == "K" or move == "k")
		{
			owo = 0;
			system("cls");
			if (PrintMonster(map) == 0)
			{

			}
			else
			{
				string Monster;
				int MonsterHP, MonsterD;
				int cs;
				int back = 0;
				cin >> cs;
				Monster = Choose(cs, map);
				system("cls");
				if (cs == 0)
				{
					cout << "已返回" << endl << endl;
					back = 1;
				}
				else if (Monster == "Wrong" and back == 0)
				{
					cout << "\n錯誤!\n\n";
				}
				else if (back == 0)
				{
					cout << "遇到了" << Monster << "(LV" << LV(Monster) << ")" << endl << endl;
					MonsterHP = HisHP(Monster);
					MonsterD = HisDamage(Monster);
					float y = (player.fightingHP * 100) / player.HP;
					HpLine(y, z, MonsterHP, Monster);
					cout << endl;
					cout << "你的血量:" << player.fightingHP << setw(14 + ps()) << " " << "對手的血量:" << MonsterHP << endl << endl;
					int dag = int(player.realattack + ((((rand() * 76 - 475) % 369 * 478) % player.realattack) * 0.345));
					cout << "對手受到" << dag << "點傷害     \n\n";
					MonsterHP -= dag;
					int oneshot = 0;
					if (MonsterHP <= 0)
					{
						float y = (player.fightingHP * 100) / player.HP;
						float z = (MonsterHP * 100) / HisHP(Monster);
						oneshot = 1;
						cout << "\n秒殺!\n";
						player.exp = player.exp + HisEXP(Monster);
						cout << "獲得了" << HisEXP(Monster) << "點經驗" << endl;
						string Prize;
						Prize = GetPrize(Monster,whatsquest,doneornot);
						int ckk = 0;
						if (Prize != "none")
						{
							int ct = GetCount(Monster,whatsquest);
							for (int k = 0; k <= 99; k++)
							{
								if (bag[k] == Prize)
								{
									ckk = 1;
									bagcount[k] += ct;
									break;
								}
							}
							if (ckk == 0)
							{
								for (int g = 0; g <= 99; g++)
								{
									if (bag[g] == "none")
									{
										bag[g] = Prize;
										bagcount[g] += ct;
										break;
									}
								}
							}
						}
						for (int gg = 0; bag[gg] != "none"; gg++)
						{
							QuestItem(whatsquest, bag[gg], bagcount[gg]);
						}
						if (QuestReturn(whatsquest, Monster, SaveNumber) == 1)
						{
							if (QuestItem(whatsquest) == 1)
							{
								cout << "\n任務完成!\n\n";
								doneornot = 1;
							}
						}
						while (player.exp >= 150 + pow(2, player.level * 0.35))
						{
							cout << "                           \\LEVEL UP!/" << endl;;
							player.exp -= 150 + pow(2, player.level * 0.35);
							player.fightingHP = player.HP;
							player.level++;
						}
						save();
					}
					while ((player.HP > 0 or MonsterHP > 0) and oneshot != 1)
					{
						float y = (player.fightingHP * 100) / player.HP;
						float z = (MonsterHP * 100) / HisHP(Monster);
						HpLine(y, z, MonsterHP, Monster);
						cout << endl;
						cout << "你的血量:" << player.fightingHP << setw(14 + ps()) << " " << "對手的血量:" << MonsterHP << endl << endl;
						float MonsterDamage = MonsterD + (((rand() * 76 - 475) % 369 * 478) % MonsterD) * 0.345;
						if (HisSkill(Monster) == 1)
						{
							;
							float Dam;
							Dam = GetSkillDamage(HisSkillName(Monster));
							MonsterDamage *= Dam;
							cout << "\n" << Monster << "發動了技能:" << HisSkillName(Monster) << endl << endl;
						}
						if (MonsterDamage * 10 < player.def)
						{
							MonsterDamage = 0;
						}
						else if (MonsterDamage <= player.def) //50 25
						{
							MonsterDamage = MonsterDamage * (1 - ((player.def / MonsterDamage) / 10));
						}
						else if (MonsterDamage > player.def)
						{
							MonsterDamage = MonsterDamage * (1 + ((MonsterDamage / player.def) / 10));
						}
						player.fightingHP -= (MonsterDamage - 1);
						int dizzy = 0;
						int effect = SpecialEffect(Monster);
						if (effect == 601)
						{
							cout << "你已被暈眩\n";
							dizzy = 1;
						}
						Sleep(750);
						SetColor(12, 0);
						cout << "你受到";
						SetColor();
						SetColor(6, 0);
						cout << int(MonsterDamage);
						SetColor();
						SetColor(12, 0);
						cout << "點傷害        \n\n";
						SetColor();
						y = (player.fightingHP * 100) / player.HP;
						z = (MonsterHP * 100) / HisHP(Monster);
						HpLine(y, z, MonsterHP, Monster);
						cout << endl;
						if (player.fightingHP <= 0)
						{
							cout << "你的血量:" << "0"<< setw(14 + ps()) << " " << "對手的血量:" << MonsterHP << endl << endl;
							cout << "死亡\n";
							player.fightingHP = player.HP;
							save();
							break;
						}
						cout << "你的血量:" << player.fightingHP << setw(14 + ps()) << " " << "對手的血量:" << MonsterHP << endl << endl;
						Sleep(750);
						int dag = int(player.realattack + (rand() % player.realattack) * 0.345);
						if (dizzy == 1)
						{
							dag = 0;
						}
						cout << "對手受到" << dag << "點傷害\n\n";
						MonsterHP -= dag;
						if (player.fightingHP <= 0 and MonsterHP <= 0)
						{
							cout << "同歸於盡!";
							player.fightingHP = player.HP;
							save();
						}
						else if (player.fightingHP <= 0)
						{
							cout << "你的血量:" << "0" << "              對手的血量:" << MonsterHP << endl;
							cout << "死亡\n";
							player.fightingHP = player.HP;
							save();
							break;
						}
						else if (MonsterHP <= 0)
						{
							y = (player.fightingHP * 100) / player.HP;
							z = (MonsterHP * 100) / HisHP(Monster);
							HpLine(y, z, MonsterHP, Monster);
							cout << endl;
							cout << "你的血量:" << player.fightingHP << setw(14 + ps()) << " " << "對手的血量:0" << endl << endl;
							cout << "\n勝利\n\n";
							player.exp = player.exp + HisEXP(Monster);
							string Prize;
							Prize = GetPrize(Monster,whatsquest, doneornot);
							int ckk = 0;
							if (Prize != "none")
							{
								int ct = GetCount(Monster,whatsquest);
								for (int k = 0; k <= 99; k++)
								{
									if (bag[k] == Prize)
									{
										ckk = 1;
										bagcount[k] += ct;
										break;
									}
								}
								if (ckk == 0)
								{
									for (int g = 0; g <= 99; g++)
									{
										if (bag[g] == "none")
										{
											bag[g] = Prize;
											bagcount[g] += ct;
											break;
										}
									}
								}
							}
							cout << "獲得了" << HisEXP(Monster) << "點經驗" << endl;
							for (int gg = 0; bag[gg] != "none"; gg++)
							{
								QuestItem(whatsquest, bag[gg], bagcount[gg]);
							}
							if (QuestReturn(whatsquest, Monster, SaveNumber) == 1)
							{
								if (QuestItem(whatsquest) == 1)
								{
									cout << "\n任務已完成!\n\n";
									doneornot = 1;
								}
							}
							while (player.exp >= 150 + pow(2, player.level * 0.35))
							{
								cout << "                           \\LEVEL UP!/" << endl;;
								player.exp -= 150 + pow(2, player.level * 0.35);
								player.fightingHP = player.HP;
								player.level++;
							}
							save();
							break;
						}
					}
				}
			}
		}
		int def1 = 0, def2 = 0, def3 = 0, def4 = 0, def5 = 0;
		int c1 = 1, c2 = 1, c3 = 1, c4 = 1, c5 = 1;
		if (move == "Q" or move == "q")
		{
			save();
			system("cls");
			owo = 0;
			cout << "您所擁有的道具:    STR   DEX   INT   LUK   Damage   Def" << endl;
			//cout << z << "." << clothitem[z] << "            " << Str(clothitem[z]) << "   " << Dex(clothitem[z]) << "   " << Int(clothitem[z]) << "   " << Luk(clothitem[z]) << "   " << Damage(clothitem[z]) << endl;
			for (int z = 1; clothitem[z] != "none"; z++)
			{
				cout << z << "." << clothitem[z];
				cout << setw(14 - (clothitem[z].length()) + 6) << Str(clothitem[z]);
				cout << setw(6) << Dex(clothitem[z]);
				cout << setw(6) << Int(clothitem[z]);
				cout << setw(6) << Luk(clothitem[z]);
				cout << setw(6) << Damage(clothitem[z]);
				cout << setw(7) << Def(clothitem[z]);
				cout << endl;
			}
			cout << "輸入0返回 輸入道具左側的代碼換上該裝備" << endl;
			int w;
			cin >> w;
			int kk = 1;
			if (w == 0)
			{
				cout << "返回";
				int kk = 0;
			}
			if (clothitem[w] == player.Armr or clothitem[w] == player.Head or clothitem[w] == player.Armor or clothitem[w] == player.Shoes or clothitem[w] == player.Gloves or player.Pants == clothitem[w])
			{
				SetColor(12, 0);
				cout << "\n你早就穿著這件裝備了\n" << endl;
				SetColor();
				kk = 0;
			}
			while (clothitem[w] == "none")
			{
				if (kk == 0)break;
				cout << "這個位置是空的．\n";
				cin >> w;
				if (w == 0)
				{
					cout << "返回\n";
					w = 0;
					kk = 0;
					break;
				}
			}
			if (kk == 1)
			{
				if (check(clothitem[w]) == 0)//武器
				{
					if (clothitem[w] != player.Armr and player.job == "fighter")
					{
						player.Armr = clothitem[w];
						player.str = Str(clothitem[w]) + player.basicStr;
						player.attack = Damage(clothitem[w]);
					}
					else if (clothitem[w] != player.Armr and player.job == "shoter")
					{
						player.Armr = clothitem[w];
						player.dex = Dex(clothitem[w]) + player.basicDex;
						player.attack = Damage(clothitem[w]);
					}
					else if (clothitem[w] != player.Armr and player.job == "magic")
					{
						player.Armr = clothitem[w];
						player.iq = Dex(clothitem[w]) + player.basiciq;
						player.attack = Damage(clothitem[w]);
					}
					else if (clothitem[w] != player.Armr and player.job == "ninja")
					{
						player.Armr = clothitem[w];
						player.luk = Dex(clothitem[w]) + player.basicLuk;
						player.attack = Damage(clothitem[w]);
					}
				}
				else if (check(clothitem[w]) == 1)//帽子
				{
					player.Head = clothitem[w];
				}
				else if (check(clothitem[w]) == 2)
				{
					player.Armor = clothitem[w];
				}
				else if (check(clothitem[w]) == 3)
				{
					player.Pants = clothitem[w];
				}
				else if (check(clothitem[w]) == 4)
				{
					player.Shoes = clothitem[w];
				}
				else if (check(clothitem[w]) == 5)
				{
					player.Gloves = clothitem[w];
				}
			}
			save();
		}
		if (c1 == 1)//頭盔
		{
			def1 = Def(player.Head);
		}
		if (c2 == 1)//上衣
		{
			def2 = Def(player.Armor);
		}
		if (c3 == 1)//褲子
		{
			def3 = Def(player.Pants);
		}
		if (c4 == 1)//鞋子
		{
			def4 = Def(player.Shoes);
		}
		if (c5 == 1)//手套
		{
			def5 = Def(player.Gloves);
		}
		player.defsum = def1 + def2 + def3 + def4 + def5;
		if (move == "S" or move == "s")
		{
			owo = 0;
			system("cls");
			save();
			cout << "存檔完畢" << endl;
		}
		if (move == "C" or move == "c")
		{
			save();
			system("cls");
			owo = 0;
			cout << "\n名稱:" << player.name << endl;
			cout << "職業:" << player.job << endl;
			cout << "頭盔:" << player.Head << endl;
			cout << "上衣:" << player.Armor << endl;
			cout << "褲子:" << player.Pants << endl;
			cout << "鞋子:" << player.Shoes << endl;
			cout << "手套:" << player.Gloves << endl;
			cout << "武器:" << player.Armr << endl;
			cout << "血量:" << player.HP << endl;
			cout << "目前的血量:" << player.fightingHP << endl;
			cout << "魔力:" << player.MP << endl;
			cout << "等級:" << player.level << endl;
			cout << "經驗值:" << player.exp << "      還需要" << 150 + pow(2, player.level * 0.35) - player.exp << endl;
			cout << "艾斐幣:" << player.Money << endl;
			cout << "攻擊力:" << player.attack << endl;
			cout << "普通攻擊傷害:" << player.realattack << endl;
			cout << "防禦力:" << player.def << endl;
			cout << "力量:" << player.str << endl;
			cout << "敏捷:" << player.dex << endl;
			cout << "運氣:" << player.luk << endl;
			cout << "智力:" << player.iq << endl << endl;
			save();
		}
	}
}
int main()
{
	//戰士 射手 法師 忍者
	int start;
	for (int z = 1; z < 100; z++)
	{
		AllQuest[z] = z;
	}
	for (int f = 1; f < 50; f++)
	{
		clothitem[f] = "none";
	}
	for (int h = 0; h <= 99; h++)
	{
		bag[h] = "none";
		bagcount[h] = 0;
	}
	while (1)
	{
		cout << "輸入1創建角色 輸入2讀檔\n";
		cin >> start;
		if (start == 1)
		{
			cout << "請輸入角色名稱(輸入後會直接創建 請注意)" << endl;
			string name;
			cin >> name;
			player.name = name;
			player.level = 1;
			cout << "你的名稱為" << name << endl;
			cout << "請輸入職業代碼 戰士1 射手2 法師3 忍者4  輸入其他數字返回 (無法更改 輸入後會直接創建 請慎選)" << endl;
			int p;
			cin >> p;
			cout << "請輸入存檔代號(1 2 3 4)" << endl;
			cin >> SaveNumber;
			if (p == 1)
			{
				player.job = "fighter";
				player.HP = 450;
				player.MP = 100;
				player.Armr = armr(player.job, 3, 5, 0, 0);
				player.attack = 35;
				player.str = 14;
				clothitem[1] = player.Armr;
				player.fightingHP = player.HP;
				clothitem[2] = "新手上衣";
				player.Armor = "新手上衣";
				clothitem[3] = "新手褲子";
				player.Pants = "新手褲子";
				player.defsum = 85;
			}
			if (p == 2)
			{
				player.job = "shoter";
				player.HP = 350;
				player.MP = 100;
				player.fightingHP = player.HP;
				player.Armr = "木弓";
				player.dex = 16;
				player.attack = 30;
				clothitem[1] = player.Armr;
				clothitem[2] = "新手上衣";
				player.Armor = "新手上衣";
				clothitem[3] = "新手褲子";
				player.Pants = "新手褲子";
				player.defsum = 85;
			}
			if (p == 3)
			{
				player.Armr = "木杖";
				player.job = "magic";
				player.HP = 250;
				player.fightingHP = player.HP;
				player.MP = 300;
				clothitem[1] = player.Armr;
				clothitem[2] = "新手上衣";
				player.Armor = "新手上衣";
				clothitem[3] = "新手褲子";
				player.Pants = "新手褲子";
				player.iq = Int(clothitem[1]);
				player.attack = 20;
				clothitem[1] = player.Armr;
				player.defsum = Def(clothitem[2]) + Def(clothitem[3]);
			}
			if (p == 4)
			{
				player.Armr = "匕首";
				player.job = "ninja";
				player.HP = 350;
				player.fightingHP = player.HP;
				player.MP = 100;
				clothitem[1] = player.Armr;
				clothitem[2] = "新手上衣";
				player.Armor = "新手上衣";
				clothitem[3] = "新手褲子";
				player.Pants = "新手褲子";
				player.attack = Damage(clothitem[1]);
				player.luk = Luk(clothitem[1]);
				player.defsum = Def(clothitem[2]) + Def(clothitem[3]);
			}
			if (p >= 1 and p <= 4)
			{
				cout << "創建完畢"; break;
			}
		}
		else if (start == 2)
		{
			cout << "請輸入要讀的檔" << endl;
			cin >> SaveNumber;
			switch (SaveNumber)
			{
			case 1:
				fw.open("PlayerData.txt", ios::in);
				break;
			case 2:
				fw.open("PlayerData2.txt", ios::in);
				break;
			case 3:
				fw.open("PlayerData3.txt", ios::in);
				break;
			case 4:
				fw.open("PlayerData4.txt", ios::in);
				break;
			}
			fw >> player.name;
			fw >> player.job;
			fw >> player.Head;
			fw >> player.Armor;
			fw >> player.Pants;
			fw >> player.Shoes;
			fw >> player.Gloves;
			fw >> player.Armr;
			fw >> player.HP;
			fw >> player.fightingHP;
			fw >> player.MP;
			fw >> player.level;
			fw >> player.exp;
			fw >> player.attack;
			fw >> player.realattack;
			fw >> player.def;
			fw >> player.bdef;
			fw >> player.str;
			fw >> player.basicStr;
			fw >> player.dex;
			fw >> player.basicDex;
			fw >> player.luk;
			fw >> player.basicLuk;
			fw >> player.iq;
			fw >> player.basiciq;
			fw >> map;
			for (int qwe = 1; qwe < 50; qwe++)
			{
				fw >> clothitem[qwe];
			}
			for (int pa = 1; pa < 100; pa++)
			{
				fw >> AllQuest[pa];
			}
			fw >> QuestCheck;
			fw >> whatsquest;
			fw >> doneornot;
			for (int oqq = 0; oqq <= 99; oqq++)
			{
				fw >> bag[oqq];
				fw >> bagcount[oqq];
			}
			loadQuest(SaveNumber);
			fw >> player.Money;
			int def1 = 0, def2 = 0, def3 = 0, def4 = 0, def5 = 0;
			int c1 = 1, c2 = 1, c3 = 1, c4 = 1, c5 = 1;
			if (c1 == 1)//頭盔
			{
				def1 = Def(player.Head);
			}
			if (c2 == 1)//上衣
			{
				def2 = Def(player.Armor);
			}
			if (c3 == 1)//褲子
			{
				def3 = Def(player.Pants);
			}
			if (c4 == 1)//鞋子
			{
				def4 = Def(player.Shoes);
			}
			if (c5 == 1)//手套
			{
				def5 = Def(player.Gloves);
			}
			player.defsum = def1 + def2 + def3 + def4 + def5;
			if (player.job == "fighter")
			{
				player.basicStr = (player.level * 2.5);
				player.realattack = player.attack + (player.str / 4) + player.basicStr;
				player.bdef = (player.str / 3) + player.level * 3;
				player.def = player.bdef + player.defsum;
				player.HP = 500 + (player.level - 1) * 180;
				player.MP = 100 + (player.level - 1) * 50;
			}
			if (player.job == "shoter")
			{
				player.basicDex = (player.level * 2);
				player.realattack = player.attack + (player.dex / 4) + player.basicDex;
				player.bdef = (player.dex / 4) + player.level * 2;
				player.def = player.bdef + player.defsum;
				player.HP = 350 + (player.level - 1) * 130;
				player.MP = 100 + (player.level - 1) * 50;
			}
			if (player.job == "magic")
			{
				player.basiciq = player.level * 3;
				player.realattack = player.attack + (player.iq / 5) + player.basiciq;
				player.bdef = player.iq / 5 + player.level * 2;
				player.def = player.bdef + player.defsum;
				player.HP = 200 + (player.level - 1) * 100;
				player.MP = 300 + (player.level - 1) * 150;
			}
			if (player.job == "ninja")
			{
				player.basicLuk = player.level * 3;
				player.realattack = player.attack + (player.luk / 4) + player.basicLuk;
				player.bdef = player.luk / 4 + player.level * 2;
				player.def = player.bdef + player.defsum;
				player.HP = 350 + (player.level - 1) * 145;
				player.MP = 100 + (player.level - 1) * 50;
			}
			fw.close();
			for (int gg = 0; bag[gg] != "none"; gg++)
			{
				QuestItem(whatsquest, bag[gg], bagcount[gg]);
			}
			break;
		}
		else
		{
			cout << "請重新輸入";
		}
	}
	ingame();
	system("pause");
}
