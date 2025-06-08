#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int rollDice() {
    return (rand() % 6) + 1;
}

void printBoard(int p1, int p2) {
    printf("\nSNAKE AND LADDER BOARD:\n");
    for (int i = 100; i > 0; i -= 10) {
        for (int j = 0; j < 10; j++) {
            int row = (i - 1) / 10;
            int pos;
            if (row % 2 == 0)
                pos = i - j;
            else
                pos = i - 9 + j;

            if (pos == p1 && pos == p2)
                printf("P1&P2\t");
            else if (pos == p1)
                printf("P1\t");
            else if (pos == p2)
                printf("P2\t");
            else
                printf("%d\t", pos);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));

    int player1 = 0, player2 = 0;
    char name1[50], name2[50];

    printf("Enter Player 1 name: ");
    fgets(name1, sizeof(name1), stdin);
    name1[strcspn(name1, "\n")] = 0;

    printf("Enter Player 2 name: ");
    fgets(name2, sizeof(name2), stdin);
    name2[strcspn(name2, "\n")] = 0;

    int board[101];
    for (int i = 0; i <= 100; i++) board[i] = i;

    board[2] = 38; board[7] = 14; board[8] = 31;
    board[15] = 26; board[21] = 42; board[28] = 84;
    board[36] = 44; board[51] = 67; board[71] = 91; board[78] = 98;

    board[16] = 6; board[46] = 25; board[49] = 11;
    board[62] = 19; board[64] = 60; board[74] = 53;
    board[89] = 68; board[92] = 88; board[95] = 75; board[99] = 78;

    printf("\n🎲 Welcome to Snake and Ladder Game!\n");
    printf("%s vs %s\n", name1, name2);

    while (1) {
        printf("\n%s's turn. Press Enter to roll the dice...", name1);
        getchar();
        int dice = rollDice();
        printf("%s rolled a %d\n", name1, dice);

        if (player1 + dice <= 100) {
            player1 += dice;
            player1 = board[player1];
        }
        printf("%s is now at position %d\n", name1, player1);
        printBoard(player1, player2);

        if (player1 == 100) {
            printf("\n🏆 %s wins the game!\n", name1);
            break;
        }

        printf("\n%s's turn. Press Enter to roll the dice...", name2);
        getchar();
        dice = rollDice();
        printf("%s rolled a %d\n", name2, dice);

        if (player2 + dice <= 100) {
            player2 += dice;
            player2 = board[player2];
        }
        printf("%s is now at position %d\n", name2, player2);
        printBoard(player1, player2);

        if (player2 == 100) {
            printf("\n🏆 %s wins the game!\n", name2);
            break;
        }
    }

    return 0;
}
