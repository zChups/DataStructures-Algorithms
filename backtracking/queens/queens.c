#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t side;
	bool* row;
	bool* col;
	bool* diag_p;
	bool* diag_s;
	int* placing;
}Chessboard;

static void PrintChessboard(Chessboard* board) {
	for (int r = 0; r < board->side; r++) {
		for (int c = 0; c < board->side; c++) {
			if (board->placing[c] != -1 && r == board->placing[c]) {
				printf("[Q]");
			}
			else {
				printf("[ ]");
			}
			puts("");
		}
		puts("");
	}
}

static void PlaceQueensRec(Chessboard* board, int n_queens, int* nsol, int placed_queens, int i) {
	if (n_queens == placed_queens) {
		(*nsol)++;
		printf("Sol %d:", *nsol);
		PrintChessboard(board);
		return;
	}

	for (int p = i; i < (int)board->side * board->side; p++) {

		int r = p / (int)board->side;
		int c = p % (int)board->side;

		if (!board->row[r] &&
			!board->col[c] &&
			!board->diag_s[r + c] &&
			!board->diag_p[r - c + board->side - 1]) {
			board->row[r] = board->col[c] = board->diag_s[r + c] = board->diag_p[r - c + board->side - 1] = true;
			board->placing[c] = r;

			PlaceQueensRec(board, n_queens, nsol, placed_queens + 1, p + 1);

			board->row[r] = board->col[c] = board->diag_s[r + c] = board->diag_p[r - c + board->side - 1] = false;
			board->placing[c] = -1;
		}

	}
}

int PlaceQueens(int chessboard_side, int n_queens) {
	if (chessboard_side <= 3)return 0;

	int nsol = 0;
	Chessboard board = {
		.side = chessboard_side,
		.row = calloc(board.side, sizeof(bool)),
		.col = calloc(board.side, sizeof(bool)),
		.diag_p = calloc(board.side * 2 - 1, sizeof(bool)),
		.diag_s = calloc(board.side * 2 - 1, sizeof(bool)),
		.placing = calloc(board.side, sizeof(int))
	};
	PlaceQueensRec(&board, n_queens, &nsol, 0, 0);

	return nsol;
}