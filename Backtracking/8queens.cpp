#include "board.h"
#include <chrono>
#include <thread>

void solveSingle(Board& b);
void solveAll(Board& b);
void solveHelperAllSolns(Board& b, int col);
bool solveHelperSingleSoln(Board& b, int col);

int main(int argc, char** argv)
{
	Board chess;

	if (argc > 1) {
		solveAll(chess);
		return 0;		
	}
	
    solveSingle(chess);
	return 0;
}

void solveAll(Board& b) {
	solveHelperAllSolns(b,0);
}

void solveSingle(Board& b) {
  solveHelperSingleSoln(b,0);
}

void solveHelperAllSolns(Board& b, int col) {
    if (col >= N) { // Base case
        b.printBoard();   
        cout << "\033[2J\033[1;1H";
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
    else {
        for (int row = 0; row < N; row++) {
            if (b.isSafe(row, col)) { //Choose
                b.place(row,col);
                solveHelperAllSolns(b, col+1); //Explore
                b.unplace(row,col);
            }
        }
    }
}

bool solveHelperSingleSoln(Board& b, int col) {
    if (col >= N) {// Base case
        b.printBoard();
        return true;    
    }
    else {
        for (int row = 0; row < N; row++) {
            if (b.isSafe(row, col)) { //Choose
                b.place(row,col);
                bool found = solveHelperSingleSoln(b, col+1); //Explore
                if (found) {
                    return true;
                }
                else {
                    b.unplace(row,col);
                }
            }
        }
        return false;
    }

}
