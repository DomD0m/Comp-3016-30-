// Comp 3016 30-.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "classes.cpp"
  // Variables
bool wonfight = false;

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

void gameloop(Player player, enemy Enemy) {

    char playerchoice;
    do
    {
        std::cout << "Press A to Attack or H to Heal";
        std::cin >> playerchoice;
        
        if (playerchoice == 'a' || playerchoice == 'A') {

            Enemy.takeDamage(player.givedmg());

            if (Enemy.getHealth() > 0) {
                std::cout << "Enemy Turn is now";
                player.takeDamage(Enemy.givedmg());
            }
            
        }
        else if (playerchoice == 'h' || playerchoice == 'H') {
            player.heal();
            if (Enemy.getHealth() > 0) {
                std::cout << "Enemy Turn is now";
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

int main()
{
    Gamestory();
    char userInput;
    do
    {
        std::cout << "press S to start the game";
        std::cin >> userInput;

        if (userInput == 'S' || userInput == 's')
        {
            Player playerObj;
            enemy enemyobj;
            gameloop(playerObj, enemyobj);
            if (wonfight == true) {
                std::cout << "u won the fight";
            }
        }
        else 
        {

          std::cout << "you have quit the game";

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


