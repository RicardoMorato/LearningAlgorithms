#include <bits/stdc++.h>

using namespace std;

/*
  Given a NxN matrix representing a chess board and a pair of starting coordinates <x0, y0>.
  You must find (if it exists) a tour with n^2 - 1 movements, where every coordinate in the board is visited only once.
*/

class KnightsTour {
  private:
    int n; // Number of rows and columns of the board.
    int *a, *b, **board; // a and b will be all the possible moves of the knight.

  public:
    KnightsTour(int n) {
      this->n = n;
      this->board = new int*[n];
      for (int i = 0; i < n; i ++) this->board[i] = new int[n];
      this->a = new int[8];
      this->b = new int[8];
      a[0] = 2; a[1] = 1; a[2] = -1; a[3] = -2; a[4] = -2; a[5] = -1; a[6] = 1; a[7] = 2;
      b[0] = 1; b[1] = 2; b[2] = 2; b[3] = 1; b[4] = -1; b[5] = -2; b[6] = -2; b[7] = -1;
      for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j++) {
          board[i][j] = 0;
        }
      }
      board[0][0] = 1;
    };

    bool tryMove(int i, int x, int y) {
      int newX, newY, nextMove;
      bool success;
      nextMove = -1; // Initialize movements with a non-existing.

      do {
        nextMove += 1;
        success = false;
        newX = x + a[nextMove];
        newY = y + b[nextMove];

        // cout << "Chegou aqui" << endl;

        if ((newX >= 0) && (newX <= 7) && (newY >= 0) && (newY <= 7)) { // Test to check if the board limits are respected.
          if (board[newX][newY] == 0) {
            board[newX][newY] = i;
            if (i < n * n) { // Some coordinates in the board have not been visited yet.
              success = tryMove(i + 1, newX, newY);
              if (!success) board[newX][newY] = 0; // Not a success, undo register.
            } else {
              success = true;
            }
          }
        }
      } while (!success && ( nextMove != 7));
      return success;
    };

    void printTour() const {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << "\t" << board[i][j];
        }
        cout << endl;
      }
    };

    ~KnightsTour() {
      delete []a;
      delete []b;
      for (int i = 0; i < n; i ++) delete []this->board[i];
      delete []this->board;
    };
};

int main () {
  KnightsTour knightsTour(8);

  bool success = knightsTour.tryMove(2, 0, 0);

  if (success) {
    knightsTour.printTour();
  } else {
    cout << "No possible solution" << endl;
  }
  return 0;
}
