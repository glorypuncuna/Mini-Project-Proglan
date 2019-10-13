#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "events.h"
#include "Map.h"
#include "myinv.h"

char name[100];

void fullscreen()
{
	keybd_event(VK_MENU,
				0x38,
				0,
				0);
	keybd_event(VK_RETURN,
				0x1c,
				0,
				0);
	keybd_event(VK_RETURN,
				0x1c,
	KEYEVENTF_KEYUP,
				0);
	keybd_event(VK_MENU,
				0x38,
	KEYEVENTF_KEYUP,
				0);
}

void remove_scrollbar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}

void splashscreen()
{
	FILE *splash;
    char str[MAXCHAR];
    int dots[5] = {1, 2, 3, 4, 5};
 	int i;
 	
 	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t");
 	for(i = 0; i <= 4; i++)
	 {
		Sleep(100);
 		printf("%d ", dots[i]);
 		printf(". . .");
	 }
	 getch();
	 system("cls");
 	
    splash = fopen("splashscreen.txt", "r");
    while (fgets(str, MAXCHAR, splash) != NULL)
        printf("%s", str);
    fclose(splash);
    getch();
    system("cls");
}

void titlescreen()
{
	FILE *title;
	char str2[MAXCHAR];
	int choice;
	
	system("cls");
	fflush(stdin);
    title = fopen("titlescreen.txt", "r");
    while (fgets(str2, MAXCHAR, title) != NULL)
        printf("%s", str2);
    fclose(title);    
    printf("\n\n\n\t\t\t\t\t\t\t\t\t  ");
    printf("\t  1 >>New Game");
    printf("\n\t\t\t\t\t\t\t\t\t\t  2 >>Help");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t    What is it that you seek? ");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t   ~");
	scanf("%d", &choice);
    
	if(choice == 1){
		create_char();
	}
	if(choice == 2){
		help();
	}
}

void help(){
	FILE *backstory;
	char str2[MAXCHAR];
	system("cls");
	backstory = fopen("backstory.txt", "r");
	while(fgets(str2, MAXCHAR, backstory) != NULL)
		printf("%s", str2);
	printf("\n\nHow's it, chosen one? Capiche?");
	printf("\nGood. Let's go back now.");
	getch();
	titlescreen();
}

void create_char()
{	
	FILE *character;
	char str4[MAXCHAR];
	int choice;
	
	fflush(stdin);
	system("cls");
	character = fopen("character.txt", "r");
	while(fgets(str4, MAXCHAR, character) != NULL)
		printf("%s", str4);
	fclose(character);
	printf("\nWho are you, oh chosen one?");
	printf("\n1. Wizard");
	printf("\n2. Thief");
	printf("\n3. Warrior");
	printf("\n\n~");
	scanf("%d", &choice);
	if(choice == 1){
		wizzy();
	}
	if(choice == 2){
		theft();
	}
	if(choice == 3){
		warier();
	}
}

void wizzy()
{
	FILE *wizard;
	char str5[MAXCHAR];
	int choice, x = 1;
	
	fflush(stdin);
	system("cls");
	wizard = fopen("wizard.txt", "r");
	while(fgets(str5, MAXCHAR, wizard) != NULL)
		printf("%s", str5);
	fclose(wizard);	
	printf("\nIs this you?");
	printf("\n1. Indeed, mademoiselle.");
	printf("\n2. Who is this nerd?");
	printf("\n\n~");
	scanf("%d", &choice);
	if(choice == 1){
		printf("\n\nGreat! Proceed to the story then you slacker!");
		printf("\n...wait a minute, who are you calling mademoiselle again?");
		getch();
		stats(x);
	}
	if(choice == 2){
		printf("\n\nHm...so you are not a nerd after all.");
		getch();
		create_char();
	}
}

void theft()
{
	FILE *thief;
	char str6[MAXCHAR];
	int choice, x = 2;
	
	system("cls");
	thief = fopen("thief.txt", "r");
	while(fgets(str6, MAXCHAR, thief) != NULL)
		printf("%s", str6);
	fclose(thief);
	printf("\nQuite the handsome thief here. Wait...don't tell me THIS thief is you.");
	printf("\n1. Don't deny the reality here, narrator.");
	printf("\n2. Definitely not me...but hey, i'm more handsome than him anyway.");
	printf("\n\n~");
	scanf("%d", &choice);
	if(choice == 1){
		printf("\n\nFrankly, i'm quite sceptical about that...but i'll give you the benefit of doubt.");
		getch();
		stats(x);
	}
	if(choice == 2){
		printf("\n\nKeep on dreaming there, chosen one.");
		printf("\n...it's not like you have a better thing to do anyway.");
		getch();
		create_char();
	}
}

void warier()
{
	FILE *warrior;
	char str7[MAXCHAR];
	int choice, x = 3;
	
	system("cls");
	warrior = fopen("warrior.txt", "r");
	while(fgets(str7, MAXCHAR, warrior) != NULL)
		printf("%s", str7);
	fclose(warrior);
	printf("\nMmhm, a tough guy here. He is really beefy to be you, really.");
	printf("\n1. Excuse me? I AM the great WARRIOR of seven seas.");
	printf("\n2. Not a warrior i am, but beefy i do.");
	printf("\n\n~");
	scanf("%d", &choice);
	if(choice == 1){
		printf("\n\nYeah, yeah. Wait, isn't that the line for a pirate?");
		getch();
		stats(x);
	}
	if(choice == 2){
		printf("\n\nI can't believe you say that with a straight face.");
		printf("\nEspecially with that pempek sized muscle you have there.");
		getch();
		create_char();
	}
}

void stats(int x)
{
	FILE *wiz, *thi, *war;
	int parameter[6];
	int input;
	char str8[MAXCHAR];
	
	fflush(stdin);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t    ");
	printf("I forgot to ask this, but...what is your name, oh chosen one?");
	printf("\n\t\t\t\t\t\t\t\t\t    (Insert your name, as ridiculous it may be.)");
	printf("\n\n\t\t\t\t\t\t\t\t\t   ->");
	gets(name);
	do{
		system("cls");
		if(x == 1){
			parameter[0] = (rand() % 4) + 1; //str
			parameter[1] = ((rand() % 11) + 1) + 2; //int
			parameter[2] = (rand() % 6) + 1; //dex
			parameter[3] = 2 * (1 * parameter[0]) + 50; //hp
			parameter[4] = 2 * parameter[1] + 100; //mp
			parameter[5] = 5; //ac
			wiz = fopen("wiz.txt", "r");
			while(fgets(str8, MAXCHAR, wiz) != NULL)
				printf("%s", str8);
			fclose(wiz);
			printf("\nName: %s", name);
			printf("\nHP: %d", parameter[3]);
			printf("\nMP: %d", parameter[4]);
			printf("\nSTR: %d", parameter[0]);
			printf("\nINT: %d", parameter[1]);
			printf("\nDEX: %d", parameter[2]);
			printf("\nAC: %d", parameter[5]);
			printf("\n\nIs this satisfactory, chosen one?");
			printf("\n1. Yes!");
			printf("\n2. No...");
			printf("\n\n~");
			scanf("%d", &input);
		}
		if(x == 2){
			parameter[0] = (rand() % 6) + 1;
			parameter[1] = (rand() % 8) + 1;
			parameter[2] = ((rand() % 9) + 1) + 2;
			parameter[3] = 2 * (1 * parameter[0]) + 50;
			parameter[4] = 1 * parameter[1] + 50;
			parameter[5] = 8;
			thi = fopen("thi.txt", "r");
			while(fgets(str8, MAXCHAR, thi) != NULL)
				printf("%s", str8);
			fclose(thi);
			printf("\nName: %s", name);
			printf("\nHP: %d", parameter[3]);
			printf("\nMP: %d", parameter[4]);
			printf("\nSTR: %d", parameter[0]);
			printf("\nINT: %d", parameter[1]);
			printf("\nDEX: %d", parameter[2]);
			printf("\nAC: %d", parameter[5]);
			printf("\n\nIs this satisfactory, chosen one?");
			printf("\n1. Yes!");
			printf("\n2. No...");
			printf("\n\n~");
			scanf("%d", &input);	
		}
		if(x == 3){
			parameter[0] = ((rand() % 11) + 1) + 2;
			parameter[1] = (rand() % 4) + 1;
			parameter[2] = (rand() % 6) + 1;
			parameter[3] = 2 * (2 * parameter[0]) + 100;
			parameter[4] = 2 * parameter[1] + 50;
			parameter[5] = 10;
			
			war = fopen("war.txt", "r");
			while(fgets(str8, MAXCHAR, war) != NULL)
				printf("%s", str8);
			fclose(war);
			printf("\nName: %s", name);
			printf("\nHP: %d", parameter[3]);
			printf("\nMP: %d", parameter[4]);
			printf("\nSTR: %d", parameter[0]);
			printf("\nINT: %d", parameter[1]);
			printf("\nDEX: %d", parameter[2]);
			printf("\nAC: %d", parameter[5]);
			printf("\n\nIs this satisfactory, chosen one?");
			printf("\n1. Yes!");
			printf("\n2. No...");
			printf("\n\n~");
			scanf("%d", &input);
		}
	}while(input != 1);
	
	map(parameter, x);
	
}
