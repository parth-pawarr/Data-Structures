#include <iostream>
using namespace std;

const int N = 8;

int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y, int board[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

int countUnvisitedMoves(int x, int y, int board[N][N]) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];
        if (isValid(nextX, nextY, board)) {
            count++;
        }
    }
    return count;
}

bool nextMove(int &x, int &y, int board[N][N]) {
    int minDegree = 9, nextX = -1, nextY = -1;
    
    for (int i = 0; i < 8; i++) {
        int newX = x + moveX[i];
        int newY = y + moveY[i];
        
        if (isValid(newX, newY, board)) {
            int degree = countUnvisitedMoves(newX, newY, board);
            if (degree < minDegree) {
                minDegree = degree;
                nextX = newX;
                nextY = newY;
            }
        }
    }
    
    if (nextX == -1 || nextY == -1) return false;

    x = nextX;
    y = nextY;
    return true;
}

bool knightTour(int startX, int startY) {
    int board[N][N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = -1;
        }
    }
    
    int x = startX, y = startY;
    board[x][y] = 1;
    
    for (int i = 2; i <= N * N; i++) {
        if (!nextMove(x, y, board)) {
            cout << "No solution exists for starting position (" << startX << "," << startY << ")." << endl;
            return false;
        }
        board[x][y] = i;
    }
    
    cout << "Knight's Tour for starting position (" << startX << "," << startY << "):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
    return true;
}

int main() {
    int startX, startY;
    cout << "Enter the starting X (0-7) and Y (0-7) position for the Knight: ";
    cin >> startX >> startY;

    if (startX < 0 || startX >= N || startY < 0 || startY >= N) {
        cout << "Invalid starting position. Please enter values between 0 and 7." << endl;
        return 0;
    }

    knightTour(startX, startY);

    return 0;
}
