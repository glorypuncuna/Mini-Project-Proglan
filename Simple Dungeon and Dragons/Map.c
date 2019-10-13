#include <stdio.h>
#include <windows.h>
#include "events.h"
#include "myinv.h"
#include "mechanics.h"

int map(int parameter[], int y){
	int a[5][5] = {{11,2,11,7,11},{11,10,11,10,9},{1,11,3,6,10}, {11,10,11,5,11}, {0,11,4,10,8}};
	system("cls");
	awal(a, parameter, y);
}

int awal(int a[5][5], int parameter[], int y){
	int i,j,c;
	int x = 2;
	int h=233, g=178, k=219, l=176;
	system("cls");
	printf("\n\t");
	for(c=0; c<19; c++){
		printf("%c ", g);
	}
	printf("\tI N V E N T O R Y : \n\n");
	for(i=0; i<5; i++){
			printf("\t%c ", g);
			for(j=0; j<5; j++){
			if(a[i][j]==0 || a[i][j]==14){
				j==4? printf("%c   ", h):printf("%c\t", h);
			}else if(a[i][j]==13){
				j==4?printf("x   "):printf("x\t");
			}else if(a[i][j]==10){
				j==4?printf("%c   ", g):printf("%c\t", g);
			}else if(a[i][j] == 11){
				j==4?printf("    "):printf(" \t");
			}
			else{
				j==4?printf("    "):printf(" \t");
				
			}
		}
		printf("%c\t%c ", g, l);
		if(i==0){
			check(1) == 1? one(1,x) : printf("_______");
		}else if(i==1){
			check(2) == 1? one(2,x) : printf("_______");
		}else if(i==2){
			check(3) == 1? one(3,x) : printf("_______");
		}else if(i==3){
			check(4) == 1? one(4,x) : printf("_______");
		}else if(i==4){
			check(5) == 1? one(5,x) : printf("_______");
		}
		printf("\n\n");
	}
	printf("\t");
	for(c=0; c<19; c++){
		printf("%c ", g);
	}
	position(a, parameter, y);
}


int position(int a[5][5], int parameter[], int y){
	int k;
	int i = -1, j = -1;
	while(a[i][j] != 0 && a[i][j] != 14 && i<4){
		i++;
		for(j=0; j<4; j++){
			if((a[i][j] == 14) || (a[i][j]==0)){
				break;
			} 
		}

	}
	
	int ch;
	fflush(stdin);
    ch = getch ();
    system("cls");
	if (ch == 0 || ch == 224)
	{
    	switch (getch ())
    	{
        	case 72:
				up(a,i,j, parameter, y);
            	break;
        	case 80:
            	down(a,i,j, parameter, y);
            	break;
			case 77:
				right(a,i,j, parameter, y);
            	break;
            case 75:
				left(a,i,j, parameter, y);
            	break;
			default:
				printf("Game Over\n");      
    }
}
    
}
int up(int a[5][5], int i, int j, int parameter[], int y){
	int temp;
	if (a[i][j]==0){
		a[i][j] = 11;
		if(i-1>=0 && (i-1)<5 && a[i-1][j]!=10){
			i = i-1;
			if (a[i][j]>0 && a[i][j]<10 || a[i][j] == 13){
				if(a[i][j]!=13){
					temp = a[i][j];
					a[i][j] = 14;
					pev(a, temp, parameter, y);
				}else{
					a[i][j] = 14;
				}}else{
					a[i][j] = 0;
				}
		}else{
			system("cls");
			printf("Game Over!");
			getch();
			system("cls");
		}
	}else if(a[i][j]==14){
			a[i][j] = 13;
			if(i-1>=0 && (i-1)<5 && a[i-1][j]!=10){
				i = i-1;
				if (a[i][j]>0 && a[i][j]<10 || a[i][j] == 13){
				if(a[i][j]!=13){
					temp = a[i][j];
					a[i][j] = 14;
					pev(a, temp, parameter, y);
				}else{
					a[i][j] = 14;
				}}else{
					a[i][j] = 0;
				}
			}else{
				system("cls");
				printf("Game Over!");
				getch();
				system("cls");
			}
	}
	awal(a, parameter, y);
	
}

int down(int a[5][5], int i, int j, int parameter[], int y){
	int temp;
	if (a[i][j]==0){
		a[i][j] = 11;
		if(i+1>=0 && (i+1)<5 && a[i+1][j]!=10){
			i = i+1;
			if (a[i][j]>0 && a[i][j]<10 || a[i][j] == 13){
				if(a[i][j]!=13){
					temp = a[i][j];
					a[i][j] = 14;
					pev(a, temp, parameter, y);
				}else{
					a[i][j] = 14;
				}}else{
					a[i][j] = 0;
				}
		}else{
			system("cls");
			printf("Game Over!");
			getch();
			system("cls");
		}
	}else if(a[i][j]==14){
			a[i][j] = 13;
			if(i+1>=0 && (i+1)<5 && a[i+1][j]!=10){
				i = i+1;
				if (a[i][j]>0 && a[i][j]<10 || a[i][j] == 13){
				if(a[i][j]!=13){
					temp = a[i][j];
					a[i][j] = 14;
					pev(a, temp, parameter, y);
				}else{
					a[i][j] = 14;
				}}else{
					a[i][j] = 0;
				}
			}else{
				system("cls");
				printf("Game Over!");
				getch();
				system("cls");
			}
	}
	awal(a, parameter, y);
}

int right(int a[5][5], int i, int j, int parameter[], int y){
	int temp;
	if (a[i][j]==0){
		a[i][j] = 11;
		if(j+1>=0 && (j+1)<5 && a[i][j+1]!=10){
			j = j+1;
			if (a[i][j]>0 && a[i][j]<10 || a[i][j] == 13){
				if(a[i][j]!=13){
					temp = a[i][j];
					a[i][j] = 14;
					pev(a, temp, parameter, y);
				}else{
					a[i][j] = 14;
				}}else{
					a[i][j] = 0;
				}
		}else{
			system("cls");
			printf("Game Over!");
			getch();
			system("cls");
		}
	}else if(a[i][j]==14){
			a[i][j] = 13;
			if(j+1>=0 && (j+1)<5 && a[i][j+1]!=10){
				j = j+1;
				if (a[i][j]>0 && a[i][j]<10 || a[i][j] == 13){
				if(a[i][j]!=13){
					temp = a[i][j];
					a[i][j] = 14;
					pev(a, temp, parameter, y);
				}else{
					a[i][j] = 14;
				}}else{
					a[i][j] = 0;
				}
			}else{
				system("cls");
				printf("Game Over!");
				getch();
				system("cls");
			}
	}	
	awal(a, parameter, y);
}

int left(int a[5][5], int i, int j, int parameter[], int y){
	int temp;
	if (a[i][j]==0){
		a[i][j] = 11;
		if(j-1>=0 && (j-1)<5 && a[i][j-1]!=10){
			j = j-1;
			if (a[i][j]>0 && a[i][j]<10 || a[i][j] == 13){
				if(a[i][j]!=13){
					temp = a[i][j];
					a[i][j] = 14;
					pev(a, temp, parameter, y);
				}else{
					a[i][j] = 14;
				}}else{
					a[i][j] = 0;
				}
		}else{
			system("cls");
			printf("Game Over!");
			getch();
			system("cls");
		}
	}else if(a[i][j]==14){
			a[i][j] = 13;
			if(j-1>=0 && (j-1)<5 && a[i][j-1]!=10){
				j = j-1;
				if (a[i][j]>0 && a[i][j]<10 || a[i][j] == 13){
				if(a[i][j]!=13){
					temp = a[i][j];
					a[i][j] = 14;
					pev(a, temp, parameter, y);
				}else{
					a[i][j] = 14;
				}}else{
					a[i][j] = 0;
				}
			}else{
				system("cls");
				printf("Game Over!");
				getch();
				system("cls");
			}
	}
	awal(a, parameter, y);
}

void pev(int a[5][5], int temp, int parameter[], int y){
	switch(temp){
		case 1:
			event(a, parameter, y, 1);
			break;
		case 2:
			event(a, parameter, y, 2);
			break;
		case 3:
			event(a, parameter, y, 3);
			break;
		case 4:			
			event(a, parameter, y, 4);
			break;		
		case 5:
			event(a, parameter, y, 5);
			break;		
		case 6:
			event(a, parameter, y, 6);
			break;		
		case 7:
			event(a, parameter, y, 7);
			break;		
		case 8:
			event(a, parameter, y, 8);
			break;		
		case 9:
			event(a, parameter, y, 9);
			break;			
	}	
}


