#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void run();
void board();
void change();
int checkWin();
void result(int,int);

int main() {
	board();
	return 0;
}

char array[3][3]={{'+','2','3'},{'4','5','6'},{'7','8','9'}};
char score[2]={'X','O'};
char cursor='1';
int x=0,y=0;
int turn=1;
int winner;

void change(char *score1, char *score2) {
	char temp=*score2;
	*score2=*score1;
	*score1=temp;
}

void board() {
	system("cls");
	printf("   TIC TAC TOE\n\n");
	printf("     |     |     \n  %c  |  %c  |  %c  \n", array[0][0], array[0][1], array[0][2]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n  %c  |  %c  |  %c  \n", array[1][0], array[1][1], array[1][2]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n  %c  |  %c  |  %c  \n", array[2][0], array[2][1], array[2][2]);
	printf("     |     |     \n");
	run();
}

void run() {
	char move = getch();
	change (&cursor, &array[y][x]);
	if (x+1 != 3 && move==77)
		x++;
	else if(x-1 != -1 && move==75)
		x--;
	else if (y+1 != 3 && move==80)
		y++;
	else if (y-1 != -1 && move==72)
		y--;
	else if(move==13)
	{
		if(turn==1 && array[y][x] != score[1] && array[y][x] != score[0]) {
			array[y][x]=score[0];
			winner=checkWin();
			if(winner==1) {
				printf("End Game\n");
				result(winner,turn);
			}
			else if(winner==2) {
				printf("End Game\n");
				result(winner,turn);
			}
			else 
				turn=2;
		}
		else if(turn==2 && array[y][x] != score[0] && array[y][x] != score[1]) {
			array[y][x]=score[1];
			winner=checkWin();
			if(winner==1) {
				printf("End Game\n");
				result(winner,turn);
			}
			else if(winner==2) {
				printf("End Game\n");
				result(winner,turn);
			}
			else 
				turn=1;
		}
	}
	if(move != 27) {
		change(&cursor, &array[y][x]);
	}
	if(move==27) {
		exit(EXIT_FAILURE);
	}
	board();
}

int checkWin() {
	//check horizontally
	 if(array[0][0] == array[0][1] && array[0][1] == array[0][2])
        return 1;
    else if(array[1][0] == array[1][1] && array[1][1] == array[1][2])
    	return 1;
    else if(array[2][0] == array[2][1] && array[2][1] == array[2][2])
    	return 1;

    //check vertically
    else if(array[0][0] == array[1][0] && array[1][0] == array[2][0])
    	return 1;
    else if(array[0][1] == array[1][1] && array[1][1] == array[2][1])
    	return 1;
    else if(array[0][2] == array[1][2] && array[1][2] == array[2][2])
    	return 1;

    //check diagonally
    else if(array[0][0] == array[1][1] && array[1][1] == array[2][2])
    	return 1;
    else if(array[0][2] == array[1][1] && array[1][1] == array[2][0])
    	return 1;
    else if(array[0][0] != '1' && array[0][1] != '2' && array[0][2] != '3' &&
    	array[1][0] != '4' && array[1][1] != '5' && array[1][2] != '6' && array[2][0] 
        != '7' && array[2][1] != '8' && array[2][2] != '9') 
        return 2;
    else 
    	return 0;
}

void result(int winner, int turn) {
	FILE *fp=fopen("Winner.txt","w");
	if(winner==1)
	fprintf(fp, "The winner is Player %d \n", turn);
	else if(winner==2)
	fprintf(fp, "Game Over in a Series \n");
	fclose(fp);
	exit(EXIT_SUCCESS);
}