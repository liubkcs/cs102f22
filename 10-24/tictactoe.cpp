#include <iostream>
using namespace std;
// Tic-tac-toe is a 3×3 board with players
// X and O.
enum cell { EMPTY, X, O };
const unsigned SIZE = 3;

// Functions: because parameter is an array,
// this function is allowed to modify it.
void initializeBoard(cell board[SIZE][SIZE]) {
	for(unsigned row = 0; row < SIZE; ++row) {
		for(unsigned col = 0; col < SIZE; ++col) {
			board[row][col] = EMPTY;
		}
	}	
}

unsigned convertRowColToUserIndex(unsigned row, unsigned col) {
	return row * SIZE + col + 1;
}

cell getCellAtUserIndex(unsigned index, cell board[SIZE][SIZE]) {
	index--; // Convert to zero-based
	return board[index/SIZE][index%SIZE];
}

void setCellAtUserIndex(unsigned index, cell board[SIZE][SIZE], cell newValue)
{
	index--;
	board[index/SIZE][index%SIZE] = newValue;
}

void printBoard(cell board[SIZE][SIZE]) {
	for(unsigned row = 0; row < SIZE; ++row) {
		for(unsigned col = 0; col < SIZE; ++col) {
			switch(board[row][col]) {
				case EMPTY: 
					// Print index for UI.
					cout << convertRowColToUserIndex(row, col); 
					break;
				case X: cout << 'X'; break;
				case O: cout << 'O';
			}
		}
		cout << endl;
	}	
}

bool isValidMove(unsigned move,
								cell board[SIZE][SIZE]) {
	if(move < 1 || move > SIZE*SIZE) {
		cout << "Out of bounds\n";
		return false; // out of bounds
	}
	if(getCellAtUserIndex(move, board) != EMPTY) {
		cout << "Already occupied\n";
		return false; // already occupied
	}
	return true;
}


int main()
{
	cell board[SIZE][SIZE];
	cell player = X;
	initializeBoard(board);
	// Initialize board to empty
	// Place an X in center.
	// board[1][1] = X;
	while(true) {
		printBoard(board);
		unsigned move;
		do {
			cout << (player == X? 'X' : 'O') << "'s move? ";
			cin >> move;		
		}	while(!isValidMove(move, board));
		setCellAtUserIndex(move, board, player);
		player = (player == X)? O : X;
	}	
	return 0;
}