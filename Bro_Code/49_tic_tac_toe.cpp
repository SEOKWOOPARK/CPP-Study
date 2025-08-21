#include <iostream>
#include <ctime>


void drawBoard(char *spaces) {

}

void playerMove(char *spaces, char player) {

}

void computerMove(char *spaces, char computer) {
    int number;
    srand(time(0));

    while (true) {
        number = rand() % 9;

        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer) {

    return 0;
}

int main() {
    return 0;
}
