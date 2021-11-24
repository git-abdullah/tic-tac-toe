#include <stdio.h>
#include <stdlib.h>


// function declaration
int show();
int add(int i, int j, int move);
int check(int player);

// Global
char mainArray [3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'},
};
int totalMoves = 0;

int main() {
    int i, j, x;

    int player;
    int end = 0;
    while (end == 0) {
        for (player = 1; player <= 2; player++) {
            int flag = 0;
            while (flag == 0) {
                show();
                printf("\n\t\t<player-%d: 1-9> ", player);
                scanf("%d", &x);

                switch(x) {
                case 1:
                    i = 0;
                    j = 0;
                    break;
                case 2:
                    i = 0;
                    j = 1;
                    break;
                case 3:
                    i = 0;
                    j = 2;
                    break;
                case 4:
                    i = 1;
                    j = 0;
                    break;
                case 5:
                    i = 1;
                    j = 1;
                    break;
                case 6:
                    i = 1;
                    j = 2;
                    break;
                case 7:
                    i = 2;
                    j = 0;
                    break;
                case 8:
                    i = 2;
                    j = 1;
                    break;
                case 9:
                    i = 2;
                    j = 2;
                    break;
                }
                int addStatus = add(i, j, player);
                if (addStatus == 1) {
                    flag = 1;
                }
                system("cls");
                if (addStatus == 0) printf("\n\t\t(Place is taken try again!)\a\n");
            }
            int status = check(player);
            if (status == 1) {
                end = 1;
                show();
                printf("\n\t\t(player %d has won XO!\a)", player);
                break;
            }
        }
    }
    return 0;
}

int show() {
    int i, j;
    printf("\n\n\n\t\t\tTIC-TAC-TOE\n");
    printf("\t\tplayer-1 <O>\tplayer-2 <X>\n\n\n");
    printf("\t\t\t %c | %c | %c \n", mainArray[0][0], mainArray[0][1], mainArray[0][2]);
    printf("\t\t\t---+---+---\n");
    printf("\t\t\t %c | %c | %c \n", mainArray[1][0], mainArray[1][1], mainArray[1][2]);
    printf("\t\t\t---+---+---\n");
    printf("\t\t\t %c | %c | %c \n", mainArray[2][0], mainArray[2][1], mainArray[2][2]);
    return 0;
}

int add(int i, int j, int move) {
    char sign = (move == 1)? 'O': 'X';

    if (mainArray[i][j] == '-') {
        mainArray[i][j] = sign;
        totalMoves += 1;
        return 1;
    } else return 0;
}

int check(int player) {
    int i;
    char move = (player == 1)? 'O': 'X';

    for (i = 0; i < 3; i++) {
        if (mainArray[i][0] == move && mainArray[i][1] == move && mainArray[i][2] == move) {
            return 1;
            break;
        } else if (mainArray[0][i] == move && mainArray[1][i] == move && mainArray[2][i] == move) {
            return 1;
            break;
        } else if (mainArray[0][0] == move && mainArray[1][1] == move && mainArray[2][2] == move) {
            return 1;
            break;
        } else if (mainArray[0][2] == move && mainArray[1][1] == move && mainArray[2][0] == move) {
            return 1;
            break;
        }
    }
}
