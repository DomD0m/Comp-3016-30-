# Comp 3016 30
 comp 3016 30% work
The Visual Studio version that was used for creation was visual studios 2019 and operating system was 64 bit windows 10, this was what was used to test and write the code of the solution.


How it Plays?:
The Game is a text based adventure, whilst going through this adventure you will be using turn based combat to defeat your foes.
To initially start up the game, is to press the Keys S or s, this will initally boot up the game and start the code.
After the game has started you will be given a prompt to pick a race, type out one of the races and then the game will show your stats of the race you've chosen and what will be stats of your player for the game.
After this you will initate you're first combat after the enemies has done his introduction, then you will be shown your choices within combat which is A to attack and H to heal.
If a is pressed you will do a randomised damage between two values and that damage will be subtracted away from your enemy.
and then the enemy will take you doing damage from it's stats to your HP value, if your HP value gets 0, you lose and game over will pop up.
If H is pressed you will do a heal to your HP between your heal stats and you're hp will be increased by that value.
after the attack or heal its the enemies turn and they will do just damage to you within the first battle.
IF after multiple turns you are successful within battle you will then recieve the next part of the story and encounter the Necromancer within the dungeon
This will start the next battle within the next battle somethings are changes and slight additions happen.
In this battle just like the last you will be doing a 1v1 vs an enemy but this time you can buff yourself in addition to being able to heal and attack
buffing yourself doubles your attack out put.
But also this time the Enemy can heal aswell and will make a decision on to either heal or attack
If you fail this fight you game over but if you are successful and slay your second enemy.
You will be brought to your third and final fight, a King driven with madness of his situation attacks you to protect his daughter
You are now in the final fight within the final fight you unlock more options but also the enemy has been buffed before the fight.
Within this fight you now have 5 options, 3 you already know but 2 more are added A smite function which only has limited use but puts out big damage, or the charge function which charges an extra slot of smite for the player.
But when it goes back to enemy they also get an upgrade stronger attacks and possiblity to smite the player back.
If Unsuccessful you gameover but if successful the credits roll and you completed the game.

How it works:
The game works by using a Do while loop which checks for the first input to boot up the game being the s, after this we are std::cout to output information and story tidbits to the player this allows for them to understand a lot better about the situation and story. The next part after boot up is the race selection so for this we have a .txt file with the races and their stats on so this file is opened and when the player picks the race, those stats from the .txt becomes theirs. After this we are outputing the data from the player class stats to the player so they know their stats before their first combat. We also then get the introduction from the enemy class as it's made. The player now enteres combat which is the first battle function within the code which is easy battle. Easy battle is simple to understand as it shows what moves the player has and waits for their input and if its a correct input they do that action if not they are told and have to reinput a correct input for a combat action. After the player combat action, its then the enemy action turn which is just them attacking as they don't currently do anything else within easy battle. IF the battle is lost by the player then we have their class within c++ print out the game over tombstone and a message saying they have died and the game closing but if they are successful the boolean function is turned to true and the check is then made to see if it's true to go on to the second part of the game. Before the second battle you are given more story and information about the next battle then you enter the second battle which being run within the function MediumBattle, with this we have a new player action called buff, now to explain the player actions we have attack which works by the opposition running their take damage function which reduces their health by an integer and that integer is then generated from the player givedmg function. this works the same for the enemy but opposite and then heal for the player just adds their random health between their minheal and mxheal integers equipped to their class. Buff works by doubling the mindmg and mxdmg integers within the player class. Also after the player action we have a random number between 1-2 so that the enemy either atks or heals aswell now. The game over works the same for this combat and then the next boolean is changed to true if the player is succesfful wihtin this battle. The game then puts out more story for the player, then it runs the final combat function being the hardbattle. Hardbattle gives the player 5 options for their turn within the combat, these 5 options are Attack, Heal, Buff, Smite and charge. The smite funciton is a new one where the player is able to put out big damage but this is limited by it needing to be charged by the player but they start off with 1 smite counter and then after using the smite the smite counter reduces by 1. The charge function is simple and allows the player to gain a smitecounter. Then when turning to the enemy within this they have 3 options now decided by random number but its 3 options is the enemies own smite and heal and attack. The smite damage is done by the maths as the givedmg of the classes so takedmg(player.smite()) does all of it that it needs.

Error handling:
The error handling within the game starts with the first thing, which shows the player being asked to input s to start the game but if they don't it quits and tells the player has quit the game. 
The second piece is with the reading the .txt file with if the game isn't able to find it then the player is given the basic stats and just being a human race instead of the game just crashsing and this is done if the solution knows the file is open and if not then it gives the basic stats.
The third piece is within the combat piece which tell the player they input a wrong choice and allows them to redecide their choice for their action.

