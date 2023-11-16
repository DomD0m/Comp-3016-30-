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
		 std::cout << "Hi i'm the noble warrior and adventure Ogier only recently able to access my adventuring pass and now i have this grooling mission ahead of me";
		 std::cout << "\nthe stats of Ogier\n";
		 std::cout << "Ogier health is : " << health;
		 std::cout << "Ogier attack range is : " << mindmg << "-" << mxdmg;
		 std::cout << "Ogier heal range is : " << minheal << "-" << mxheal;

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
			 std::cout << "your current health young warrior is: " << health;
		 }
		 else
		 {
			 std::cout << "Ogier HAVE died a terrible death one his first adventure, we lose too many adventurers like this. ";
				 
				 
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

		 std::cout << "Player is performing an attack of" << randomdmg << "to the player";
		 std::cout << "            / > _________________________________";
			 std::cout << "\n[########[]_________________________________ >\n";
			 std::cout << "        / >";
		 return randomdmg;
	 }

	 void heal() {
		 srand(time(0));
		 int randomheal = (rand() % (mxheal - minheal + 1) + minheal);

		 health = health + randomheal;

		 std::cout << " your HP is now : " << health;
	 }
};

class enemy
{
private:
	int health = 100;

	int enemymxdmg = 20;
	int enemymindmg = 10;

	int mxheal = 12;
	int minheal = 6;

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

		std::cout << "\nEnemy is performing an attack of\n" << enemyrandomdmg << "to the player";

		return enemyrandomdmg;
	}
};
