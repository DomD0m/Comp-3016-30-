#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


class Player
{

private:
	int health = 100;

	int mxdmg = 30;
	int mindmg = 20;

	int mxheal = 12;
	int minheal = 6;
	int minsmitedmg = 45;
	int mxsmitedmg = 60;
	int smitecounter = 1;

public:

	 Player() 
	 {
		 std::ifstream file("Race.txt");
		 std::string playerrace;
		 std::string racefile;
		 int hpfile;
		 int mxdmgfile;
		 int mindmgfile;
		 int mxhealfile;
		 int minhealfile;
		 std::cout << "pick your race out of these elf, tiefling, Half-Orc, Half-Elf, Kobold and Goblin";
		 std::cin >> playerrace;
		 if (file.is_open()) {
			 while (file >> racefile >> hpfile >> mxdmgfile >> mindmgfile >> mxhealfile >> minhealfile) 
			 {
				 std::transform(playerrace.begin(), playerrace.end(), playerrace.begin(), ::tolower);
				 if (playerrace == racefile) {
					 health = hpfile;
					 mxdmg = mxdmgfile;
					 mindmg = mindmgfile;
					 mxheal = mxhealfile;
					 minheal = minhealfile;
					 break;
				 }
				 else
				 {
					 std::cout<<"you are basic";
				 }
			 }
			 file.close();

		 }
		 else
		 {
			 std::cout << "unable to open character races";
		 }
		 std::cout << "\nthe stats of Player\n";
		 std::cout << "\nPlayer health is : \n" << health;
		 std::cout << "\nPlayer attack range is : \n" << mindmg << "-" << mxdmg;
		 std::cout << "\nPlaye heal range is : \n" << minheal << "-" << mxheal;

	}
	
	 int getHealth() {
		 return health;
	 }
	 void takeDamage(int dmg)
	 {
		 
			 std::cout << "you've taken damage oh no";
			 std::cout << "taken damage of " << dmg;
			 health = health - dmg;
		if (health > 0) {
			 std::cout << "\nyour current health young warrior is: \n" << health;
		 }
		 else
		 {
			 std::cout << "\nYour Adventurer HAVE died a terrible death only on their first adventure, we lose too many adventurers like this. \n";
				 
				 
			 std::cout << "/ \n                    -|-\n";
			 std::cout << "|  \n                 ___|____\n";
			 std::cout << "   \n              . | ~~~~~~| .\n";
			 std::cout << "| \n                |          |\n";
			 std::cout << "|\n                 |  R  I  P |\n";
			 std::cout << "|\n                 |          |\n";
			 std::cout << "|\n                 |          |\n";
			 std::cout << "\n                  |          |\n";
			 std::cout << " \n^ ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
		 }
	 }
	 int givedmg() {
		 srand(time(0));
		 int randomdmg = (rand() % (mxdmg - mindmg + 1) + mindmg);

		 std::cout << "\nPlayer is performing an attack of \n" << randomdmg << " to the player";
		 std::cout << "            / > _________________________________";
			 std::cout << "\n[########[]_________________________________ >\n";
			 std::cout << "        / >";
		 return randomdmg;
	 }

	 void heal() {
		 srand(time(0));
		 int randomheal = (rand() % (mxheal - minheal + 1) + minheal);

		 health = health + randomheal;

		 std::cout << "\n your HP is now : \n" << health;
	 }
	 void Buff() {
		 std::cout << "\nYou feel your Power Grow. \n";

		 mindmg = mindmg * 2;
		 mxdmg = mxdmg * 2;
	 }

	 int Smite() {
		 srand(time(0));
		 if (smitecounter >= 1) {
			 int smitedmg = (rand() % (mxsmitedmg - minsmitedmg) + minsmitedmg);

			 std::cout << "\nPlayer is performing an attack of the gods dealing : \n" << smitedmg << " to the Enemy";

			 smitecounter = smitecounter - 1;
			 return smitedmg;
		 }
		 else
		 {
			 int randomdmg = (rand() % (mxdmg - mindmg + 1) + mindmg);

			 std::cout << "\nPlayer is performing an attack of \n" << randomdmg << " to the player";
			 std::cout << "            / > _________________________________";
			 std::cout << "\n[########[]_________________________________ >\n";
			 std::cout << "        / >";
			 return randomdmg;
		 }
	 }

	 void Charge() {
		 std::cout << "\nYou pray to the highest being to bless your attacks.\n";

		 smitecounter = smitecounter + 1;
	 }
};

class enemy
{
private:
	int health = 100;

	int enemymxdmg = 20;
	int enemymindmg = 10;

	int enemymxsmitedmg = 60;
	int enemyminsmitedmg = 45;

	int mxheal = 12;
	int minheal = 6;

	int enemysmitecounter = 2;

public:
	enemy() {
		std::cout << "\nWelcome to my Lair little feeble one\n";
		std::cout << "\nI can't believe that they are now giving me first class meals prepped and running into my cave.\n";
		std::cout << "\nGet ready for combat little one.\n";

	}

	int getHealth() {
		return health;
	}
	void takeDamage(int dmg)
	{
		
			std::cout << "\nEnemy has been hit\n";
			std::cout << "\nThe enemy taken\n" << dmg;
			health = health - dmg;
		if (health > 0) {
			std::cout << "\nThe enemies health is:  \n" << health;
		}
		else
		{
			std::cout << "\nThe Enemy is slained \n";
			
		}
	}

	int givedmg() {
		srand(time(0));
		int enemyrandomdmg = (rand() % (enemymxdmg - enemymindmg ) + enemymindmg);

		std::cout << "\nEnemy is performing an attack of \n" << enemyrandomdmg << " to the player";

		return enemyrandomdmg;
	}
	void heal() {
		srand(time(0));
		int randomheal = (rand() % (mxheal - minheal + 1) + minheal);

		health = health + randomheal;

		std::cout << " your Enemies hp is now : " << health;
	}

	void Buff() {
		std::cout << "\nThe Enemy is Grows Stronger \n";
		enemymindmg = enemymindmg * 2;
		enemymxdmg = enemymxdmg * 2;
	}

	int Smite() {
		srand(time(0));
		if (enemysmitecounter >= 1) {
			int enemysmitedmg = (rand() % (enemymxsmitedmg - enemyminsmitedmg) + enemyminsmitedmg);

			std::cout << "\nEnemy is performing an attack of the gods dealing : \n" << enemysmitedmg << " to the player";
			enemysmitecounter = enemysmitecounter - 1;
			return enemysmitedmg;
		}
		else
		{
			int enemyrandomdmg = (rand() % (enemymxdmg - enemymindmg) + enemymindmg);

			std::cout << "\nEnemy is performing an attack of \n" << enemyrandomdmg << " to the player";

			return enemyrandomdmg;
		}
	}
};
