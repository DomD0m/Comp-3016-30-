// Comp 3016 30-.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "classes.cpp"
  // Variables
bool wonfight = false;
bool wonfight1 = false;
bool wonfight2 = false;

void runcredits() {
    std::cout << "\n______________________________________________________\n";
    std::cout << "Well Done Adventurer you've slain the beasts";
    std::cout << "Now for your reward, Richies beyond your wildest dreams";
    std::cout << "\n______________________________________________________\n";
}

void Gamestory() {
    system("clear");
    std::cout << "\n_____________________________________\n";
    std::cout << "____Welcome to your__________________";
    std::cout << "____Adventure in this forgotten realm";
    std::cout << "\n______________________________________\n";
    std::cout << "\nYou my humble adventure, have been tasked with a mission only for the bravest\n";
    std::cout << "\nWait your a rookie, you say hmmm well best time to learn is the present they say\n";
    std::cout << "\nSo rookie you must adventure deep into the dungeon, why because i said so\n";
    std::cout << "\nAlso the undeniable presence of the demon king who just stole the royalty of this ream lurk underneath\n";
    std::cout << "\nSo your job stop anyone who tries to stop you and save the royalty, you can do this noble adventurer.\n";
    std::cout << "\n______________________________________\n";
}

void EasyBattle(Player player, enemy Enemy) {

    char playerchoice;
    do
    {
        std::cout << "\nPress A to Attack or H to Heal\n";
        std::cin >> playerchoice;
        
        if (playerchoice == 'a' || playerchoice == 'A') {

            Enemy.takeDamage(player.givedmg());

            if (Enemy.getHealth() > 0) {
                std::cout << "\nEnemy Turn is now\n";
                player.takeDamage(Enemy.givedmg());
            }
            
        }
        else if (playerchoice == 'h' || playerchoice == 'H') {
            player.heal();
            if (Enemy.getHealth() > 0) {
                std::cout << "\nEnemy Turn is now\n";
                player.takeDamage(Enemy.givedmg());
            }
        }
        else
        {
            std::cout << "invalid input";
        }

    } while (player.getHealth()> 0 && Enemy.getHealth()>0);
    wonfight = true;
}

void MediumBattle(Player player, enemy Enemy) {
    int enemychoice;
    char playerchoice;
    std::cout<<" \n   _____\n";
    std::cout<<"\n  /       \\n";
    std::cout<<"\n  | () () |\n";
    std::cout<<"\n  \   ^   /\n";
    std::cout<<"\n    |||||\n";
    std::cout<<"\n    |||||\n";
    do
    {
        std::cout << "\nPress A to Attack or H to Heal\n";
        std::cin >> playerchoice;

        if (playerchoice == 'a' || playerchoice == 'A') {

            Enemy.takeDamage(player.givedmg());

            if (Enemy.getHealth() > 0) {
                std::cout << "\nEnemy Turn is now\n";
                enemychoice = 1 + (rand() % 3);
                if (enemychoice == 1) {
                    player.takeDamage(Enemy.givedmg());
                }
                else
                {
                    
                    std::cout << "\nEnemy is Healing\n";
                    Enemy.heal();
                }
                
            }

        }
        else if (playerchoice == 'h' || playerchoice == 'H') {
            player.heal();
            if (Enemy.getHealth() > 0) {
                std::cout << "\nEnemy Turn is now\n";
                enemychoice = 1 + (rand() % 3);
                if (enemychoice == 1) {
                    player.takeDamage(Enemy.givedmg());
                }
                else
                {
                    
                    std::cout << "\nEnemy is Healing\n";
                    Enemy.heal();
                }
            }
        }
        else
        {
            std::cout << "invalid input";
        }

    } while (player.getHealth() > 0 && Enemy.getHealth() > 0);
    wonfight1 = true;
}

void HardBattle(Player player, enemy Enemy) {
    int enemychoice;
    char playerchoice;
    Enemy.Buff();
    std::cout << "\nIn this battle your player can smite, but only limited amounts so you must charge more to be able to smite again.\n";
    do
    {
        std::cout << "\nPress A to Attack or H to Heal or B to Buff yourself or S to Smite or C to charge a Smite.\n";
        std::cin >> playerchoice;

        if (playerchoice == 'a' || playerchoice == 'A') {

            Enemy.takeDamage(player.givedmg());

            if (Enemy.getHealth() > 0) {
                std::cout << "\nEnemy Turn is now\n";
                enemychoice = 1 + (rand() % 4);
                if (enemychoice == 1) {
                    player.takeDamage(Enemy.givedmg());
                }
                else if (enemychoice == 2)
                {
                   
                    std::cout << "\nEnemy is Healing\n";
                    Enemy.heal();
                }
                else
                {
                    
                    std::cout << "\nMy Move of the Gods Adventurer, Time to meet your doom\n";
                    player.takeDamage(Enemy.Smite());
                }

            }

        }
        else if (playerchoice == 'h' || playerchoice == 'H') {
            player.heal();
            if (Enemy.getHealth() > 0) {
                std::cout << "\nEnemy Turn is now\n";
                enemychoice = 1 + (rand() % 4);
                if (enemychoice == 1) {
                    player.takeDamage(Enemy.givedmg());
                }
                else if (enemychoice == 2)
                {
                    
                    std::cout << "\nEnemy is Healing\n";
                    Enemy.heal();
                }
                else
                {
                    
                    std::cout << "\nMy Move of the Gods Adventurer, Time to meet your doom\n";
                    player.takeDamage(Enemy.Smite());
                }
            }
        }
        else if (playerchoice == 'b' || playerchoice == 'B') {
            player.Buff();
            if (Enemy.getHealth() > 0) {
                std::cout << "\nEnemy Turn is now\n";
                enemychoice = 1 + (rand() % 4);
                if (enemychoice == 1) {
                    player.takeDamage(Enemy.givedmg());
                }
                else if (enemychoice == 2)
                {
                    
                    std::cout << "\nEnemy is Healing\n";
                    Enemy.heal();
                }
                else
                {
                   
                    std::cout << "\nMy Move of the Gods Adventurer, Time to meet your doom\n";
                    player.takeDamage(Enemy.Smite());
                }
            }
        }
        else if (playerchoice == 's' || playerchoice == 'S') {
            Enemy.takeDamage(player.Smite());
            if (Enemy.getHealth() > 0) {
                std::cout << "\nEnemy Turn is now\n";
                enemychoice = 1 + (rand() % 4);
                if (enemychoice == 1) {
                    player.takeDamage(Enemy.givedmg());
                }
                else if (enemychoice == 2)
                {

                    std::cout << "\nEnemy is Healing\n";
                    Enemy.heal();
                }
                else
                {

                    std::cout << "\nMy Move of the Gods Adventurer, Time to meet your doom\n";
                    player.takeDamage(Enemy.Smite());
                }
            }
        }
        else if (playerchoice == 'c' || playerchoice == 'C') {
            player.Charge();
            if (Enemy.getHealth() > 0) {
                std::cout << "\nEnemy Turn is now\n";
                enemychoice = 1 + (rand() % 4);
                if (enemychoice == 1) {
                    player.takeDamage(Enemy.givedmg());
                }
                else if (enemychoice == 2)
                {

                    std::cout << "\nEnemy is Healing\n";
                    Enemy.heal();
                }
                else
                {

                    std::cout << "\nMy Move of the Gods Adventurer, Time to meet your doom\n";
                    player.takeDamage(Enemy.Smite());
                }
            }
        }

        else
        {
            std::cout << "invalid input";
        }

    } while (player.getHealth() > 0 && Enemy.getHealth() > 0);
    wonfight2 = true;
}

int main()
{
    Gamestory();
    char userInput;
    do
    {
        std::cout << "\npress S to start the game\n";
        std::cin >> userInput;

        if (userInput == 'S' || userInput == 's')
        {
            Player playerObj;
            enemy enemyobj;
            EasyBattle(playerObj, enemyobj);
            if (wonfight == true) {
                std::cout << "\nu won the fight\n";
                std::cout << "\nWell done Adenturer.\n";
                std::cout << "\nAs you approach the royalty, a growing chill goes down your spine as you realise they are just mere corpses and before you can think a necromancer appears.\n";
                std::cout << "\nTHE BATTLE BEGINS!!!!\n";
                MediumBattle(playerObj, enemyobj);
                if (wonfight1 == true) {
                    std::cout << "\nu won the fight\n";
                    std::cout << "\nFrom around the corner the king appears almost half beaten to death\n";
                    std::cout << "\nYou stares you down and then up, to then point his sword at you\n";
                    std::cout << "\nHe screams at you: Another foul creature trying to take my precious little girl\n";
                    std::cout << "\nWith madness in his eyes he swings at you, now ready your blade for another battle.\n";
                    HardBattle(playerObj, enemyobj);
                    if (wonfight2 == true) {
                        runcredits();
                    }
                }
            }
        }
        else 
        {

          std::cout << "\nyou have quit the game\n";

        }
    


    } while (userInput == 'S' || userInput == 's');



}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


