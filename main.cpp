#include "Player/Player.h"
#include "Player/Output.h"
#include "Player/Dice.h"
#include "Player/Menu.h"
#include "Ground/InitGrounds.h"

bool isServer = false;
Player *players = nullptr;

using namespace std;

int main(int argc, char** argv)
{
	if (argc == 2 && argv[1] == string("server"))
		isServer = true;

	srand((unsigned int)time(NULL));

	vector<Ground*> mapVector;

	mapVector.push_back(new Beginning);
	Prison* prison = new Prison;
	Arrest* arrest = new Arrest(prison);
	Country* country;

	country = new Country("China", 2000, 1200, 1, 900, 10800);                      //�й�
	mapVector.push_back(country);
	country = new Country("Japan", 1400, 800, 2, 800, 9200);                        //�ձ�
	mapVector.push_back(country);
	country = new Country("South Korea", 1600, 1000, 3, 800, 9000);            //����
	mapVector.push_back(country);
	country = new Country("Syria", 600, 400, 4, 600, 5200);                         //������
	mapVector.push_back(country);
	mapVector.push_back(new PowerStation(0));
	country = new Country("Pakistan", 800, 600, 5, 600, 6200);                   //�ͻ�˹̹
	mapVector.push_back(country);
	country = new Country("Maldives", 1600, 600, 6, 900, 12400);                 //�������
	mapVector.push_back(country);
	country = new Country("Philippines", 1400, 800, 7, 800, 7200);            //���ɱ�
	mapVector.push_back(country);
	mapVector.push_back(new ChanceGround);
	country = new Country("Bangladesh", 1000, 600, 1, 800, 8000);              //�ϼ�����
	mapVector.push_back(country);
	country = new Country("India", 800, 800, 2, 700, 9000);                         //ӡ��
	mapVector.push_back(country);
	country = new Country("Sri Lanka", 800, 1000, 3, 700, 7600);                 //˹������
	mapVector.push_back(country);
	mapVector.push_back(arrest);
	country = new Country("Saudi Arabia", 2000, 800, 4, 1000, 11200);         //ɳ�ذ�����
	mapVector.push_back(country);
	country = new Country("Afghanistan", 800, 400, 5, 700, 6400);             //������
	mapVector.push_back(country);
	country = new Country("Israel", 600, 1200, 6, 600, 5800);                      //��ɫ��
	mapVector.push_back(country);
	country = new Country("Turkey", 1600, 1200, 7, 750, 8400);                     //������
	mapVector.push_back(country);
	mapVector.push_back(new PowerStation(1));
	country = new Country("Russia", 1000, 600, 1, 800, 9000);                      //����˹
	mapVector.push_back(country);
	country = new Country("Kazakhstan", 800, 1200, 2, 500, 7400);              //������˹̹
	mapVector.push_back(country);
	country = new Country("Vietnam", 800, 1200, 3, 450, 6600);                    //Խ��
	mapVector.push_back(country);
	mapVector.push_back(new FateGround);
	country = new Country("Cambodia", 400, 200, 4, 700, 7600);                   //����կ
	mapVector.push_back(country);
	country = new Country("Thailand", 1400, 1000, 5, 750, 8600);                 //̩��
	mapVector.push_back(country);
	mapVector.push_back(prison);
	country = new Country("Malaysia", 1600, 1000, 6, 800, 8600);                 //��������
	mapVector.push_back(country);
	country = new Country("Singapore", 1600, 1800, 7, 600, 7800);               //�¼���
	mapVector.push_back(country);
	country = new Country("Indonesia", 800, 800, 1, 600, 8800);                 //ӡ��������

	Map map(mapVector);
	Dice dice;
	players = new Player[4];
	map.initPlayers();

	for (int j = 0; j <= 9; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			int n = 0;
			string mainText;
			vector<string> operations;
			string serverText;

			n = players[i].getPause();
			if (n > 0)
			{
				mainText = "You're suspended for this round.";
				serverText = "pause";
				Output::instance->print(mainText, serverText);

				players[i].bePaused();
				continue;
			}

			mainText = "It's No." + to_string(i+1) + "player's turn.\nPlease choose your operations.";
			operations = { "Shoot dice", "Search informations" };
			serverText = "choice " + to_string(i + 1);

			Menu menu(mainText, operations, serverText);

			while (n != 1)
			{
				n = menu.exec();

				switch (n)
				{
				case 1:
					int num;
					num = dice.getNum();
					mainText = "The result is " + to_string(num) + ".";
					serverText = "move" + to_string(num);
					Output::instance->print(mainText, serverText);

					map.movePlayer(i, num);
					break;

				case 2:
					players[i].show();
					break;
				}
			}
		}
	}
	return 0;
}