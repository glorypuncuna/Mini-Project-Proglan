#include <stdio.h>
#include <windows.h>
#include "mechanics.h"
#include "myinv.h"
#include "Map.h"

int chance;
char name[100];

void event(int a[5][5], int parameter[], int x, int y)
{
	system("cls");
	if(y == 1){
		lost(a, parameter, x);
	}
	if(y == 2){
		merch(a, parameter, x);
	}
	if(y == 3){
		gob(a, parameter, x);
	}
	if(y == 4){
		branch(a, parameter, x);
	}
	if(y == 5){
		tem(a, parameter, x);
	}
	if(y == 6){
		shop(a, parameter, x);	
	}
	if(y == 7){
		upgrade(a, parameter, x);
	}
	if(y == 8){
		rest(a, parameter, x);
	}
	if(y == 9){
		boss(parameter, x);
	}
}

void lost(int a[5][5], int parameter[], int x)
{
	FILE *lost;
	char str9[MAXCHAR];
	
	lost = fopen("lost.txt", "r");
	while(fgets(str9, MAXCHAR, lost) != NULL)
		printf("%s", str9);
	fclose(lost);
	printf("\nYou are lost in the wood.");
	printf("\nConsidering how you're on a quest to save the world,'");
	printf("\nWould be quite embarassing if you die in a place like this.");
	printf("\nYou should probably find a way out soon...");
	getch();
	chance = (rand()%6 + 1) + 3;
	if(chance <= 5){
		printf("\n\n%d", chance);
		printf("\n\nYou actually stumbled?!");
		printf("\nWell that's quite embarassing.");
		parameter[3] = parameter[3] - (rand() % 6) + 5;
		printf("\n-------------");
		getch();
		awal(a, parameter, x);
	}
	if(chance > 5){
		printf("\n\n%d", chance);
		printf("\n\nWell, you finally managed to get out of the wood.");
		printf("\nBetter not wander too much again.");
		printf("\n-------------");
		getch();
		awal(a, parameter, x);
	}
}

void merch(int a[5][5], int parameter[], int x)
{
	FILE *merchant;
	char str10[MAXCHAR];
	int choice;
	
	fflush(stdin);
	system("cls");
	merchant = fopen("merchant.txt", "r");
	while(fgets(str10, MAXCHAR, merchant) != NULL)
		printf("%s", str10);
	fclose(merchant);
	printf("\nThat's...a merchant! Looks like he's got his hands full.");
	printf("\nTrying to push a cart twice his size isn't such a good idea.");
	printf("\nPerhaps you can try to help him, chosen one,");
	printf("\nand maybe he'll repay you too...");	
	getch();
	system("cls");
	merchant = fopen("merchant.txt", "r");
	while(fgets(str10, MAXCHAR, merchant) != NULL)
		printf("%s", str10);
	fclose(merchant);
	printf("\nHelp, help! My cartwheel is stuck!");
	printf("\nWill you help him, chosen one?\n1. Yes\n2. No\n~");
	scanf("%d", &choice);
	
	if(choice == 1 && x == 1){
		printf("Hello there sir, may i help you with my hocus pocus?");
		printf("\n--Oh please, adventurer. Help me get this wheel of the dirt!");
		printf("\nWith pleasure!");
		getch();
		chance = ((rand() % 6) + 1) + (parameter[1]/4);
		if(chance <= 6){
			system("cls");
			merchant = fopen("merchant.txt", "r");
			while(fgets(str10, MAXCHAR, merchant) != NULL)
				printf("%s", str10);
			fclose(merchant);
			printf("\n\n%d", chance);
			printf("\n\nThanks, adventurer! Been stuck for a whole 3 hours here.");
			printf("\nHere is a little something for you...");
			printf("\nObtained herbs...these should last you a lifetime long.");
			getch();
			inventory(4, 1);
			awal(a, parameter, x);
		}
		if(chance > 6){
			system("cls");
			merchant = fopen("merchant.txt", "r");
			while(fgets(str10, MAXCHAR, merchant) != NULL)
				printf("%s", str10);
			fclose(merchant);
			printf("\n\n%d", chance);
			printf("\n\n...my cart!!!!!");
			printf("---\n...ups, i guess the spell didn't work as expected...");
			printf("\nYOU. WILL. PAY.");
			parameter[3] = parameter[3] - (parameter[5] - 8);
			getch();
			awal(a, parameter, x);
		}
	}
	
	if(choice == 1 && x == 2){
		printf("---Hello there sir, any mo-i mean, can i help you?");
		printf("\nOh please, adventurer. Help me get this wheel of the dirt!");
		printf("\n---I expect a handsome reward for this!");
		getch();
		chance = ((rand() % 6) + 1) + (parameter[2]/4);
		if(chance <= 6){
			system("cls");
			merchant = fopen("merchant.txt", "r");
			while(fgets(str10, MAXCHAR, merchant) != NULL)
				printf("%s", str10);
			fclose(merchant);
			printf("\n\n%d", chance);
			printf("\n\nThanks, adventurer! Been stuck for a whole 3 hours here.");
			printf("\nHere is a little something for you...");
			printf("\nObtained herbs...these should last you a lifetime long.");
			getch();
			inventory(4, 2);
			awal(a, parameter, x);
		}
		if(chance > 6){
			system("cls");
			merchant = fopen("merchant.txt", "r");
			while(fgets(str10, MAXCHAR, merchant) != NULL)
				printf("%s", str10);
			fclose(merchant);
			printf("\n\n%d", chance);
			printf("\n\n...my cart!!!!!");
			printf("---\n...eh, all in a day's work...");
			printf("\nYOU. WILL. PAY.");
			parameter[3] = parameter[3] - (parameter[5] - 8);
			getch();
			awal(a, parameter, x);
		}
	}	
	
	if(choice == 1 && x == 3){
		printf("---I believe you are in need of help, merchant?");
		printf("\n--Oh please, adventurer. Help me get this wheel of the dirt!");
		printf("\n---Very well, please stand back sir.");
		getch();
		chance = ((rand() % 6) + 1) + (parameter[0]/4);
		if(chance <= 6){
			system("cls");
			merchant = fopen("merchant.txt", "r");
			while(fgets(str10, MAXCHAR, merchant) != NULL)
				printf("%s", str10);
			fclose(merchant);
			printf("\n\n%d", chance);
			printf("\n\nThanks, adventurer! Been stuck for a whole 3 hours here.");
			printf("\nHere is a little something for you...");
			printf("\nObtained herbs...these should last you a lifetime long.");
			getch();
			inventory(4, 3);
			awal(a, parameter, x);
		}
		if(chance > 6){
			system("cls");
			merchant = fopen("merchant.txt", "r");
			while(fgets(str10, MAXCHAR, merchant) != NULL)
				printf("%s", str10);
			fclose(merchant);
			printf("\n\n%d", chance);
			printf("\n\n...my cart!!!!!");
			printf("---\n...um...I'm sorry, that didn't work out too well...");
			printf("\nYOU. WILL. PAY.");
			parameter[3] = parameter[3] - (parameter[5] - 8);
			getch();
			awal(a, parameter, x);
		}
	}	
	
	if(choice == 2){
		printf("\nEh, i don't think it's worth it.");
		getch();
		awal(a, parameter, x);
	}
	
		
}

void gob(int a[5][5], int parameter[], int x)
{
	FILE *goblin;
	char str11[MAXCHAR];
	
	goblin = fopen("goblin.txt", "r");
	while(fgets(str11, MAXCHAR, goblin) != NULL)
		printf("%s", str11);
	fclose(goblin);
	
	printf("\nThis smell...goblins!");
	printf("\nChosen one, quickly! attack them before they surround you!");
	getch();
	
	if(x == 1){
		chance = ((rand() % 6) + 1) + (parameter[1]/4);
		if(chance <= 5){
			system("cls");
			goblin = fopen("goblin.txt", "r");
			while(fgets(str11, MAXCHAR, goblin) != NULL)
				printf("%s", str11);
			fclose(goblin);
			printf("\n\n%d", chance);
			printf("\n\nWell...that was a bit pathetic. I expect more from you chosen one.");
			parameter[3] = parameter[3] - (parameter[5] - 12);
			getch();
			awal(a, parameter, x);
		}
		if(chance > 5){
			system("cls");
			goblin = fopen("goblin.txt", "r");
			while(fgets(str11, MAXCHAR, goblin) != NULL)
				printf("%s", str11);
			fclose(goblin);
			printf("\n\n%d", chance);
			printf("\n\nWell done, chosen one! That pea-ball sure does the trick!");
			getch();
			awal(a, parameter, x);
		}
	}
	
	if(x == 2){
		chance = ((rand() % 6) + 1) + (parameter[2]/4);
		if(chance <= 5){
			system("cls");
			goblin = fopen("goblin.txt", "r");
			while(fgets(str11, MAXCHAR, goblin) != NULL)
				printf("%s", str11);
			fclose(goblin);
			printf("\n\n%d", chance);
			printf("\n\nAll that charisma and for nothing?! Really chosen one?!.");
			parameter[3] = parameter[3] - (parameter[5] - 12);
			getch();
			awal(a, parameter, x);
		}
		if(chance > 5){
			system("cls");
			goblin = fopen("goblin.txt", "r");
			while(fgets(str11, MAXCHAR, goblin) != NULL)
				printf("%s", str11);
			fclose(goblin);
			printf("\n\n%d", chance);
			printf("\n\nWell done, chosen one! I'm sure they fall head over heels for you!");
			getch();
			awal(a, parameter, x);
		}
	}

	if(x == 3){
		chance = ((rand() % 6) + 1) + (parameter[0]/4);
		if(chance <= 5){
			system("cls");
			goblin = fopen("goblin.txt", "r");
			while(fgets(str11, MAXCHAR, goblin) != NULL)
				printf("%s", str11);
			fclose(goblin);
			printf("\n\n%d", chance);
			printf("\n\nWhy do you wear rusty armor chosen one?!.");
			parameter[3] = parameter[3] - (parameter[5] - 12);
			getch();
			awal(a, parameter, x);
		}
		if(chance > 5){
			system("cls");
			goblin = fopen("goblin.txt", "r");
			while(fgets(str11, MAXCHAR, goblin) != NULL)
				printf("%s", str11);
			fclose(goblin);
			printf("\n\n%d", chance);
			printf("\n\nCor blimey! You really showed to those goblins, chosen one!");
			getch();
			awal(a, parameter, x);
		}
	}	
	
}

void branch(int a[5][5], int parameter[], int x)
{
	FILE *tree;
	char str12[MAXCHAR];
	
	tree = fopen("tree.txt", "r");
	while(fgets(str12, MAXCHAR, tree) != NULL)
		printf("%s", str12);
	fclose(tree);
	printf("\nDid you seriously get lost in the woods again...?");
	printf("\n...wait a minute, isn't this tree quite a lil' too big for 'tis woods here?");
	printf("\nIf this is a fairy tale of some sort, there should be a weapon");
	printf("\nstuck on the root somewhere.");
	getch();
	chance = ((rand() % 6) + 2);
	system("cls");
	if(x == 1){
		if(chance <= 5){
			system("cls");
			tree = fopen("tree.txt", "r");
			while(fgets(str12, MAXCHAR, tree) != NULL)
				printf("%s", str12);
			fclose(tree);
			printf("\n\n%d", chance);
			printf("\n\nTold you there, did you expect a staff or something? Well, there IS branch.");
			getch();
			awal(a, parameter, x);
		}
		if(chance > 5){
			system("cls");
			tree = fopen("tree.txt", "r");
			while(fgets(str12, MAXCHAR, tree) != NULL)
				printf("%s", str12);
			fclose(tree);
			printf("\n\n%d", chance);
			printf("\n\nNo way, what is this? Disney movie?");
			printf("\nHow can there actually be a weapon, ESPECIALLY staff");
			printf("\nstuck on the root of the tree?");
			printf("\nAre you actually arthur?");
			printf("\nObtained hocus staff, this one is quite magical!");
			getch();
			inventory(1, 1);
			awal(a, parameter, x);
		}
	}
	
	if(x == 2){
		if(chance <= 5){
			system("cls");
			tree = fopen("tree.txt", "r");
			while(fgets(str12, MAXCHAR, tree) != NULL)
				printf("%s", str12);
			fclose(tree);
			printf("\n\n%d", chance);
			printf("\n\nTold you there, did you expect a knife or something? Well stop daydreaming.");
			getch();
			awal(a, parameter, x);
		}
		if(chance > 5){
			system("cls");
			tree = fopen("tree.txt", "r");
			while(fgets(str12, MAXCHAR, tree) != NULL)
				printf("%s", str12);
			fclose(tree);
			printf("\n\n%d", chance);
			printf("\n\nNo way, what is this? Disney movie?");
			printf("\nHow can there actually a KNIFE stuck on the root of the tree?");
			printf("\nEven arthur only found a SWORD stuck on a stone");
			printf("\nAre you actually arthur the 2nd?");
			printf("\nObtained silver knife, this one is kinda short.");
			getch();
			inventory(1, 2);
			awal(a, parameter, x);
		}
	}
	
	if(x == 3){
		if(chance <= 5){
			system("cls");
			tree = fopen("tree.txt", "r");
			while(fgets(str12, MAXCHAR, tree) != NULL)
				printf("%s", str12);
			fclose(tree);
			printf("\n\n%d", chance);
			printf("\n\nTold you there, did you expect a sword or something? There's no stone here.");
			getch();
			awal(a, parameter, x);
		}
		if(chance > 5){
			system("cls");
			tree = fopen("tree.txt", "r");
			while(fgets(str12, MAXCHAR, tree) != NULL)
				printf("%s", str12);
			fclose(tree);
			printf("\n\n%d", chance);
			printf("\n\nNo way, what is this? Disney movie?");
			printf("\nHow can there actually be a weapon on the root of the tree?");
			printf("\nAnd it's a SWORD!");
			printf("\nAre you actually arthur junior? Because i doubt this is a coincidence.");
			printf("\nObtained silver sword, isn't this really expensive?");
			getch();
			inventory(1, 3);
			awal(a, parameter, x);
		}
	}
		
}

void tem(int a[5][5], int parameter[], int x)
{
	FILE *temple;
	char str13[MAXCHAR];
	
	temple = fopen("temple.txt", "r");
	while(fgets(str13, MAXCHAR, temple) != NULL)
		printf("%s", str13);
	fclose(temple);
	printf("\n\nWelcome, oh chosen one.");
	printf("\nI have long been waiting for you.");
	printf("\nThe Narrator told me about your arrival far before you have started your journey.");
	printf("\nThis ether, has been stred ever since the end of the first calamity on Avalon.");
	printf("\nIt's peculiar, because this ether never runs out of it's water...");
	printf("\nNow, it is yours chosen one, take this and save Avalon from Lordus!");
	printf("\nObtained ether...well, a never-running-out one to boot!");
	getch();
	awal(a, parameter, x);
}

void shop(int a[5][5], int parameter[], int x)
{
	FILE *armor;
	char str14[MAXCHAR];
	int choice;
	
	fflush(stdin);
	system("cls");
	armor = fopen("armor.txt", "r");
	while(fgets(str14, MAXCHAR, armor) != NULL)	
		printf("%s", str14);
	fclose(armor);
	printf("\nHello there, wanderer.");
	printf("\nI'm a travelling merchant, and i sell armors");
	printf("\nWould you like to see my wares?");
	printf("\n\n---Well, chosen one. This seems like a great way to pimp you up.");
	printf("\n---Except...well, you don't have any money.");
	printf("\n---Maybe you can make a deal somehow?");
	printf("\n1. Yes\n2. No\n~");
	scanf("%d", &choice);
	if(choice == 1){
		system("cls");
		armor = fopen("armor.txt", "r");
		while(fgets(str14, MAXCHAR, armor) != NULL)	
			printf("%s", str14);
		fclose(armor);
		printf("\nMost splendid! But...i don't think you have any money, do you?");
		printf("\nFine, let's make a deal. If you manage to score 12 or higher");
		printf("\nusing this two dice, then you'll get an armor from me.");
		getch();
		if(x == 1){
			system("cls");
			armor = fopen("armor.txt", "r");
			while(fgets(str14, MAXCHAR, armor) != NULL)	
				printf("%s", str14);
			fclose(armor);
			chance = ((rand() % 6) + 1) + ((rand() % 6) + 1);
			getch();
			if(chance <= 12){
				system("cls");
				armor = fopen("armor.txt", "r");
				while(fgets(str14, MAXCHAR, armor) != NULL)	
					printf("%s", str14);
				fclose(armor);
				printf("\n\n%d", chance);
				printf("\n\nWell sorry there, wanderer, you weren't that lucky after all.");
				printf("\nBe on your way now.");
				getch();
				awal(a, parameter, x);	
			}
			if(chance > 12){
				system("cls");
				armor = fopen("armor.txt", "r");
				while(fgets(str14, MAXCHAR, armor) != NULL)
					printf("%s", str14);
				fclose(armor);
				printf("\n\n%d", chance);
				printf("\n\nREALLY?! HOW DID YOU PULL THAT OFF?!");
				printf("\nThat can't be...how's this possible?");
				printf("\n---Knowledge beats all, my friend.");
				printf("\n...fine, here's your out, now GIT!'");
				printf("\nObtained wizard robe! A little bit tattered and sweaty though.");
				getch();
				inventory(3, 1);
				awal(a, parameter, x);
			}
		}
		if(x == 2){
			system("cls");
			armor = fopen("armor.txt", "r");
			while(fgets(str14, MAXCHAR, armor) != NULL);
				printf("%s", str14);
			fclose(armor);
			chance = ((rand() % 6) + 1) + ((rand() % 6) + 1);
			getch();
			if(chance <= 12){
				system("cls");
				armor = fopen("armor.txt", "r");
				while(fgets(str14, MAXCHAR, armor) != NULL)
					printf("%s", str14);
				fclose(armor);
				printf("\n\n%d", chance);
				printf("\n\nWell sorry there, wanderer, you weren't that lucky after all.");
				printf("\nBe on your way now.");
				getch();	
				awal(a, parameter, x);
			}
			if(chance > 12){
				system("cls");
				armor = fopen("armor.txt", "r");
				while(fgets(str14, MAXCHAR, armor) != NULL)
					printf("%s", str14);
				fclose(armor);
				printf("\n\n%d", chance);
				printf("\n\nREALLY?! HOW DID YOU PULL THAT OFF?!");
				printf("\nThat can't be...how's this possible?");
				printf("\n---The dices are CHARMED by me.");
				printf("\n...fine, here's your out, now GIT!'");
				printf("\nObtained leather mail! Not...exactly the best reward, but hey.");
				getch();
				inventory(3, 1);
				awal(a, parameter, x);
			}
		}		
		if(x == 3){
			system("cls");
			armor = fopen("armor.txt", "r");
			while(fgets(str14, MAXCHAR, armor) != NULL)	
				printf("%s", str14);
			fclose(armor);
			chance = ((rand() % 6) + 1) + ((rand() % 6) + 1);
			getch();
			if(chance <= 12){
				system("cls");
				armor = fopen("armor.txt", "r");
				while(fgets(str14, MAXCHAR, armor) != NULL)	
					printf("%s", str14);
				fclose(armor);
				printf("\n\n%d", chance);
				printf("\n\nWell sorry there, wanderer, you weren't that lucky after all.");
				printf("\nBe on your way now.");
				getch();	
				awal(a, parameter, x);
			}
			if(chance > 12){
				system("cls");
				armor = fopen("armor.txt", "r");
				while(fgets(str14, MAXCHAR, armor) != NULL)
					printf("%s", str14);
				fclose(armor);
				printf("\n\n%d", chance);
				printf("\n\nREALLY?! HOW DID YOU PULL THAT OFF?!");
				printf("\nThat can't be...how's this possible?");
				printf("\n---Might before magic.");
				printf("\n...fine, here's your out, now GIT!'");
				printf("\nObtained chain mail! Heavy as hell.");
				getch();
				inventory(3, 1);
				awal(a, parameter, x);
			}
		}
	}
	if(choice == 2){
		system("cls");
		armor = fopen("armor.txt", "r");
		while(fgets(str14, MAXCHAR, armor) != NULL)	
			printf("%s", str14);
		fclose(armor);
		printf("\nOh...alright then.");
		printf("\nSuit yourself.");
		getch();
		awal(a, parameter, x);
	}
}

void upgrade(int a[5][5], int parameter[], int x)
{
	FILE *newest;
	char str17[MAXCHAR];
	int choice;
	
	system("cls");
	newest = fopen("newest.txt", "r");
	while(fgets(str17, MAXCHAR, newest) != NULL)	
		printf("%s", str17);
	fclose(newest);
	printf("\n---What is this light...?");
	printf("\n---MY EYEESSSSSSS!!!!!!");
	comb();
	printf("\n\nYour weapon has been upgraded!");
	printf("\nShould be better now than before...hopefully.");
	printf("\nI mean, can't really upgrade a rusty weapon now.");
	getch();
	awal(a, parameter, x);
	
}

void rest(int a[5][5], int parameter[], int x)
{
	FILE *inn;
	char str15[MAXCHAR];
	int choice;
	
	inn = fopen("inn.txt", "r");
	while(fgets(str15, MAXCHAR, inn) != NULL)	
		printf("%s", str15);
	fclose(inn);
	printf("\nWell, it was a rough journey wasn't it, chosen one?");
	printf("\nTomorrow is finally the day we face Lordus.");
	printf("\nAnd by we, i mean You.");
	printf("\nRest well now, you probably had it rough.");
	getch();
	parameter[0] = parameter[0] + (rand () % 3) + 1;
	parameter[1] = parameter[1] + (rand () % 3) + 1;
	parameter[2] = parameter[2] + (rand () % 3) + 1;
	parameter[3] = parameter[3] + (rand () % 6) + 1;
	parameter[4] = parameter[4] + (rand () % 6) + 1;
	printf("\n\n---All stats raised slightly!");	
	getch();
	awal(a, parameter, x);
}

void boss(int parameter[], int x)
{
	FILE *dragon, *attack1, *attack2, *attack3, *breath;
	char str16[MAXCHAR];
	int dragonStats[6];
	int choice, dmg, heal;
	int attack, dmgDragon;
	
	dragon = fopen("dragon.txt", "r");
	while(fgets(str16, MAXCHAR, dragon) != NULL)	
		printf("%s", str16);
	fclose(dragon);
	printf("\nA wild Lordus has appeared!");
	getch();
	printf("\n---Uh oh, that is definitely not good.");
	getch();
	printf("\n---Alright...hopefully what i have gathered will suffice in this battle!");
	getch();
	
	dragonStats[0] = 12;
	dragonStats[1] = 12;
	dragonStats[2] = 12;
	dragonStats[3] = 250;
	dragonStats[4] = 500;
	dragonStats[5] = 6;
	
	while(dragonStats[3] >= 0 || parameter[3] >= 0){
			system("cls");
			fflush(stdin);
			dragon = fopen("dragon.txt", "r");
			while(fgets(str16, MAXCHAR, dragon) != NULL)
				printf("%s", str16);
			fclose(dragon);
			printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
			printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
			getch();
			if(parameter[3] <= 0){
				end2();
			}
			if(dragonStats[3] <= 0){
				end1();
			}
			if(x == 1){
				printf("\n\n1. Fireball (5)");
				printf("\n2. Weak smash (1)");
				printf("\n3. Rest");
				printf("\nHmm...quite the predicament here...");
				printf("\n>>>");
				scanf("%d", &choice);
				if(choice == 1){
					system("cls");
					dragon = fopen("dragon.txt", "r");
					while(fgets(str16, MAXCHAR, dragon) != NULL)
						printf("%s", str16);
					fclose(dragon);
					printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
					printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
					dmg = (rand() % 20) + 1 + ((parameter[1] / 2) * 10) - dragonStats[5];
					dragonStats[3] = dragonStats[3] - dmg;
					parameter[4] = parameter[4] - 5;
					Sleep(500);
					system("cls");
					attack1 = fopen("attack1.txt", "r");
					while(fgets(str16, MAXCHAR, attack1) != NULL)
						printf("%s", str16);
					fclose(attack1);
					Sleep(500);
					system("cls");
					dragon = fopen("dragon.txt", "r");
					while(fgets(str16, MAXCHAR, dragon) != NULL)
						printf("%s", str16);
					fclose(dragon);
					printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
					printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
					printf("\n\nYou conjured a pea-fire-ball!");
					printf("\n\nHit Lordus for %d damage!", dmg);
					printf("\n\nQuite the graze i must say!");
					getch();
				}
				if(choice == 2){
					system("cls");
					dragon = fopen("dragon.txt", "r");
					while(fgets(str16, MAXCHAR, dragon) != NULL)
						printf("%s", str16);
					fclose(dragon);
					printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
					printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
					dmg = (rand() % 6) + 1  - (dragonStats[5] + 2);
					dragonStats[3] = dragonStats[3] - dmg;
					parameter[4] = parameter[4] - 1;
					Sleep(500);
					system("cls");
					attack3 = fopen("attack3.txt", "r");
					while(fgets(str16, MAXCHAR, attack3) != NULL)
						printf("%s", str16);
					fclose(attack3);
					Sleep(500);
					system("cls");
					dragon = fopen("dragon.txt", "r");
					while(fgets(str16, MAXCHAR, dragon) != NULL)
						printf("%s", str16);
					fclose(dragon);
					printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
					printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
					printf("\n\nYou...actually hit the dragon with your short stick!");
					printf("\n\nHit Lordus for %d damage!", dmg);
					printf("\n\nI must say...i'm impressed the stick didn't break!");
					getch();
				}
				if(choice == 3){
					system("cls");
					dragon = fopen("dragon.txt", "r");
					while(fgets(str16, MAXCHAR, dragon) != NULL)
						printf("%s", str16);
					fclose(dragon);
					printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
					printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
					heal = (rand() % 15) + 5;
					parameter[4] = parameter[4] + heal;
					printf("\n\nZzz...");
					printf("\nAh, i didn't think i would be able to take a rest...");
					printf("\nEspecially with Lordus in front of me...");
					printf("\nThanks, Lordus! No one dares to attack me with you looking after me!");
					printf("\n\nHealed by %d", heal);
				}
			}
			if(x == 2){
				printf("\n\n1. Slash (0)");
				printf("\n2. Super slash (3)");
				printf("\n3. Rest");
				printf("\nWhat to do...");
				printf("\n>>>");
				scanf("%d", &choice);
				if(choice == 1){
					system("cls");
					dragon = fopen("dragon.txt", "r");
					while(fgets(str16, MAXCHAR, dragon) != NULL)
						printf("%s", str16);
					fclose(dragon);
					printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
					printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
					dmg = (rand() % 7) + 1 + ((parameter[2] / 2) * 10) - dragonStats[5];
					dragonStats[3] = dragonStats[3] - dmg;
					Sleep(500);
					system("cls");
					attack2 = fopen("attack2.txt", "r");
					while(fgets(str16, MAXCHAR, attack2) != NULL)
						printf("%s", str16);
					fclose(attack2);
					Sleep(500);
					system("cls");
					dragon = fopen("dragon.txt", "r");
					while(fgets(str16, MAXCHAR, dragon) != NULL)
						printf("%s", str16);
					fclose(dragon);
					printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
					printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
					printf("\n\nYou slashed and slashed against the dragons's skin!");
					printf("\n\nHit Lordus for %d damage!", dmg);
					printf("\n\n...well that didn't do THAT much damage, but hey.");
					getch();
				}
				if(choice == 2){
					system("cls");
					dragon = fopen("dragon.txt", "r");
					while(fgets(str16, MAXCHAR, dragon) != NULL)
						printf("%s", str16);
					fclose(dragon);
					printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
					printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
					dmg = (rand() % 11) + 1 + ((parameter[2] / 2) * 10) - dragonStats[5];
					dragonStats[3] = dragonStats[3] - dmg;
					parameter[4] = parameter[4] - 1;
					Sleep(500);
					system("cls");
					attack2 = fopen("attack2.txt", "r");
					while(fgets(str16, MAXCHAR, attack2) != NULL)
						printf("%s", str16);
					fclose(attack2);
					Sleep(500);
					system("cls");
					dragon = fopen("dragon.txt", "r");
					while(fgets(str16, MAXCHAR, dragon) != NULL)
						printf("%s", str16);
					fclose(dragon);
					printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
					printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
					printf("\n\nSLAAAAAAAAASH!");
					printf("\n\nHit Lordus for %d damage!", dmg);
					printf("\n\nTHAT should leave a scar to the dragon!");
					getch();
				}
				if(choice == 3){
					system("cls");
					dragon = fopen("dragon.txt", "r");
					while(fgets(str16, MAXCHAR, dragon) != NULL)
						printf("%s", str16);
					fclose(dragon);
					printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
					printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
					heal = (rand() % 15) + 5;
					parameter[4] = parameter[4] + heal;
					printf("\n\nZzz...");
					printf("\nAh, i didn't think i would be able to take a rest...");
					printf("\nEspecially with Lordus in front of me...");
					printf("\nThanks, Lordus! No one dares to attack me with you looking after me!");
					printf("\n\nHealed by %d", heal);
				}
			}
			if(x == 3){
				printf("\n\n1. Cleave (0)");
				printf("\n2. Behead (5)");
				printf("\n3. Rest");
				printf("\nI need to defend Avalon!");
				printf("\n>>>");
				scanf("%d", &choice);
				if(choice == 1){
					system("cls");
					dragon = fopen("dragon.txt", "r");
					while(fgets(str16, MAXCHAR, dragon) != NULL)
						printf("%s", str16);
					fclose(dragon);
					printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
					printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
					dmg = (rand() % 8) + 1 + ((parameter[0] / 2) * 10) - dragonStats[5];
					dragonStats[3] = dragonStats[3] - dmg;
					Sleep(500);
					system("cls");
					attack2 = fopen("attack2.txt", "r");
					while(fgets(str16, MAXCHAR, attack2) != NULL)
						printf("%s", str16);
					fclose(attack2);
					Sleep(500);
					system("cls");
					dragon = fopen("dragon.txt", "r");
					while(fgets(str16, MAXCHAR, dragon) != NULL)
						printf("%s", str16);
					fclose(dragon);
					printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
					printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
					printf("\n\nYou cleaved the head of the dragon!");
					printf("\n\nHit Lordus for %d damage!", dmg);
					printf("\n\n...what, you thought you can do that?");
					printf("\nBrain before brawn, chosen one!");
					getch();
				}
				if(choice == 2){
					system("cls");
					dragon = fopen("dragon.txt", "r");
					while(fgets(str16, MAXCHAR, dragon) != NULL)
						printf("%s", str16);
					fclose(dragon);
					printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
					printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
					dmg = (rand() % 15) + 1 + ((parameter[0] / 2) * 10) - dragonStats[5];
					dragonStats[3] = dragonStats[3] - dmg;
					parameter[4] = parameter[4] - 5;
					Sleep(500);
					system("cls");
					attack2 = fopen("attack2.txt", "r");
					while(fgets(str16, MAXCHAR, attack2) != NULL)
						printf("%s", str16);
					fclose(attack2);
					Sleep(500);
					system("cls");
					dragon = fopen("dragon.txt", "r");
					while(fgets(str16, MAXCHAR, dragon) != NULL)
						printf("%s", str16);
					fclose(dragon);
					printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
					printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
					printf("\n\nOVERHEAD SLASH!");
					printf("\n\nHit Lordus for %d damage!", dmg);
					printf("\nWait, what do you mean that wasn't it?");
					printf("\nThat was beautiful...");
					getch();
				}
				if(choice == 3){
					system("cls");
					dragon = fopen("dragon.txt", "r");
					while(fgets(str16, MAXCHAR, dragon) != NULL)
						printf("%s", str16);
					fclose(dragon);
					printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
					printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
					heal = (rand() % 15) + 5;
					parameter[4] = parameter[4] + heal;
					printf("\n\nZzz...");
					printf("\nAh, i didn't think i would be able to take a rest...");
					printf("\nEspecially with Lordus in front of me...");
					printf("\nThanks, Lordus! No one dares to attack me with you looking after me!");
					printf("\n\nHealed by %d", heal);
				}
			}
		
		attack = rand() % 2;
		
		if(attack == 0){
			system("cls");
			dragon = fopen("dragon.txt", "r");
			while(fgets(str16, MAXCHAR, dragon) != NULL)
				printf("%s", str16);
			fclose(dragon);
			printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
			printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
			dmgDragon = (rand() % 20) + 3 + (dragonStats[1]/2) - (parameter[5] + (parameter[1] / 3));
			dragonStats[4] = dragonStats[4] - 15;
			parameter[3] = parameter[3] - dmgDragon;
			Sleep(500);
			system("cls");
			breath = fopen("breath.txt", "r");
			while(fgets(str16, MAXCHAR, breath) != NULL)
				printf("%s", str16);
			fclose(breath);
			Sleep(500);
			system("cls");
			dragon = fopen("dragon.txt", "r");
			while(fgets(str16, MAXCHAR, dragon) != NULL)
				printf("%s", str16);
			fclose(dragon);
			printf("\n\nFace my wrath, human!");
			printf("\nLordus roasted you!");
			printf("\nYou're on fire! %d damage.", dmgDragon);
			printf("\n---HOT HOT HOT!");
			printf("\n---Ugh...how's my body still intact after that...");
			getch();
		}
		if(attack == 1){
			system("cls");
			dragon = fopen("dragon.txt", "r");
			while(fgets(str16, MAXCHAR, dragon) != NULL)
				printf("%s", str16);
			fclose(dragon);
			printf("\nLordus HP|%d|\t\t|%d|HP %s", dragonStats[3], parameter[3], name);
			printf("\nLordus MP|%d|\t\t|%d|MP %s", dragonStats[4], parameter[4], name);
			dmgDragon = (rand() % 16) + 3 + (dragonStats[0]/2) - (parameter[5] + (parameter[1] / 3));
			dragonStats[4] = dragonStats[4] - 10;
			parameter[3] = parameter[3] - dmgDragon;
			Sleep(500);
			system("cls");
			attack2 = fopen("attack2.txt", "r");
			while(fgets(str16, MAXCHAR, attack2) != NULL)
				printf("%s", str16);
			fclose(attack2);
			Sleep(500);
			system("cls");
			dragon = fopen("dragon.txt", "r");
			while(fgets(str16, MAXCHAR, dragon) != NULL)
				printf("%s", str16);
			fclose(dragon);
			printf("\n\nDon't stand in our way, mortal!");
			printf("\nLordus brought up it's claws!");
			printf("\nSLASH");
			printf("\n\nThat claw almost shred you to pieces! %d damage.", dmgDragon);
			printf("\n\n---GAH!");
			printf("\n---...that...hurts...a lot...");
			getch();
		}
	}
}

void end1()
{
	FILE *victory;
	char str19[MAXCHAR];
	int choice;
	
	system("cls");
	victory = fopen("victory.txt", "r");
	while(fgets(str19, MAXCHAR, victory) != NULL)
		printf("%s", str19);
	fclose(victory);
	exit(0);
}

void end2()
{
	FILE *gameover;
	char str18[MAXCHAR];
	int choice;
	
	system("cls");
	gameover = fopen("gameover.txt", "r");
	while(fgets(str18, MAXCHAR, gameover) != NULL)	
		printf("%s", str18);
	fclose(gameover);
	exit(0);
}
