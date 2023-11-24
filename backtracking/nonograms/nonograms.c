#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "nonograms.h"

typedef struct {
	size_t rows, cols;
	bool* data;
}Grid;

enum RunStatus {
	kIn,
	kOut
};

static void PrintGrid(Grid* grid) {
	for (int r = 0; r < grid->rows; r++) {
		for (int c = 0; c < grid->cols; c++) {
			grid->data[r * grid->cols + c] ? printf("**") : printf("  ");
		}
		puts("");
	}
}

static bool VerifyRowColumn(const Constraints* constr, Grid* grid, int r, int c) {
	int id = 0;
	int curr_constr = constr->c_constr[c][id];
	enum RunStatus status = kOut;


	//DA FINIRE!!!!!!!!!!!


}

static void NonogramRec(const Constraints* constr, Grid* grid, int i) {
	int r = i / grid->cols;
	int c = i % grid->cols;

	if (r == constr->rows) {
		PrintGrid(grid);
		return;
	}

	grid->data[i] = 1;
	if (VerifyRowColumn(constr, grid, r, c)) {
		NonogramRec(constr, grid, i + 1);
	}

	g->data[i] = 0;
	if (VerifyRowColumn(constr, grid, r, c)) {
		NonogramRec(constr, grid, i + 1);
	}
}

void Nonogram(const Constraints* constr) {
	Grid g = {
		.rows = constr->rows,
		.cols = constr->cols,
		.data = calloc(constr->cols * constr->rows, sizeof(bool))
	};

	NonogramRec(constr, &g, 0);
}