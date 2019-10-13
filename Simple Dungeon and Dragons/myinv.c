#include <stdio.h>
#include "mechanics.h"

int arr[4] = {0,0,0,0};

int inventory(int x, int character){
	system("cls");
	int i;
	for(i=0; i<4; i++){
		if (arr[i]==0){
			arr[i] = x;
			break;
		}
		else{
			continue;
		}
	}
}

int check(int x){
	int i, y = 0;
	for(i=0; i<5; i++){
		if (arr[i]== x){
			y = 1;
			break;
		}else{
			y=0;
		}
	}
	return y;
}

int comb(){
	int i;
	if(check(1)== 1 && check(3)==1){
		for(i=0; i<5; i++){
			if(arr[i]==1){
				arr[i] = 2;
			}
			else if(arr[i]==3){
				arr[i] = 0;
			}
		}
	}
}

int one(int x, int y){
	check(x) == 1? charvent1(x,y) : printf(" ");
}

int charvent1(int x, int y){
	switch(y){
		case 1:
			wizin1(x);
			break;
		case 2:
			thiefin1(x);
			break;		
		case 3:
			warrin1(x);
			break;
	}
}

int wizin1(int x){

	switch(x){
		case 1:
			printf("Hocus Staff\t");
			break;
		case 2:
			printf("Hocus Pocus Staff\t");
			break;
		case 3:
			printf("Wizard Robe\t");
			break;
		case 4:
			printf("Herb\t");
			break;
		case 5:
			printf("Ether\t");
			break;
		default:
			printf(" ");
	}
}

int thiefin1(int x){
	switch(x){
		case 1:
			printf("Dagger\t");
			break;
		case 2:
			printf("Ancient Dagger\t");
			break;
		case 3:
			printf("Leather Mail\t");
			break;
		case 4:
			printf("Herb\t");
			break;
		case 5:
			printf("Ether\t");
			break;
		default:
			printf(" ");
	}
}

int warrin1(int x){
	switch(x){
		case 1:
			printf("Silver Axe\t");
			break;
		case 2:
			printf("Mythril Axe\t");
			break;
		case 3:
			printf("Chain Mail\t");
			break;
		case 4:
			printf("Herb\t");
			break;
		case 5:
			printf("Ether\t");
			break;
		default:
			printf(" ");
	}
}
