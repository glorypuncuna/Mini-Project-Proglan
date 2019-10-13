#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "mechanics.h" 

int main()
{	
	system("cls");
	fseek(stdin, 0, SEEK_END);
	srand(time(NULL));
 	remove_scrollbar();
 	fullscreen();
 	splashscreen();
	titlescreen();
    return 0;
}


