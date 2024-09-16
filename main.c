#include <stdio.h>
#include <stdbool.h>

const int winConditions[8][3][2] = {{{0, 0}, {0, 1}, {0, 2}},
                                    {{1, 0}, {1, 1}, {1, 2}},
                                    {{2, 0}, {2, 1}, {2, 2}},
                                    {{0, 0}, {1, 0}, {2, 0}},
                                    {{0, 1}, {1, 1}, {2, 1}},
                                    {{0, 2}, {1, 2}, {2, 2}},
                                    {{0, 0}, {1, 1}, {2, 2}},
                                    {{0, 2}, {1, 1}, {2, 0}}};

char checkForWin(char board[3][3]){
    for (int i = 0; i < 8; ++i){
        char valCheck1 = board[winConditions[i][0][0]][winConditions[i][0][1]];
        char valCheck2 = board[winConditions[i][1][0]][winConditions[i][1][1]];
        char valCheck3 = board[winConditions[i][2][0]][winConditions[i][2][1]];

        if (valCheck1 == valCheck2 && valCheck2 == valCheck3){
            return valCheck1;
        }
    }

    return ' ';
}

void printBoard(char board[3][3]){
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            printf("[%c]", board[i][j]);
        }

        printf("\n");
    }
}

int main(){
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    printBoard(board);

    for (int turn = 0; turn < 9; ++turn){
        char player;
        bool acceptedInput = true;

        if (turn % 2 == 0){
            player = 'X';
        }
        else{
            player = 'O';
        }

        printf("Player %c turn...\n", player);

        int row;
        int column;

        do {
            printf("Row: ");
            scanf("%d", &row); 
            
            if (row > 3 || row < 1){
                printf("Invalid row. Try again...\n");
                continue;
            }

            printf("Column: ");
            scanf("%d", &column);

            if (column > 3 || column < 1){
                printf("Invalid column. Try again...\n");
                continue;
            }

            if (board[row - 1][column - 1] == ' '){
                break;
            }

            printf("Position is filled. Try again...\n");
        } while (acceptedInput);


        board[row - 1][column - 1] = player;

        printBoard(board);

        char winner = checkForWin(board);
        if (winner != ' '){
            printf("%c Wins!\n", winner);
            break;
        }
    }

    printf("Game Finished!\n");
    return 0;
}
