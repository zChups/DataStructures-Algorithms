#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "robot_mod.h"

void FindPathsRec(const struct Grid* gcurr, int max_moves, size_t r, size_t c, int nstep, int* nsol) {
	if (r == gcurr->rows - 1 && c == gcurr->cols - 1) {
		(*nsol)++;
		printf("Sol %d:\n", *nsol);
		PrintGrid(gcurr);
		puts("");
		return;
	}

	if (nstep > max_moves)return;

	//mi provo a spostare in basso
	int next_index = (r + 1) * gcurr->cols + c;
	if (r < gcurr->rows - 1 && gcurr->cells[next_index] != -1 && gcurr->cells[next_index] == 0) {
		gcurr->cells[next_index] = nstep;
		FindPathsRec(gcurr, max_moves, r + 1, c, nstep + 1, nsol);
		gcurr->cells[next_index] = 0;
	}
	//provo a spostarmi a dx
	next_index = r * gcurr->cols + c + 1;
	if (c < gcurr->cols - 1 && gcurr->cells[next_index] != -1 && gcurr->cells[next_index] == 0) {
		gcurr->cells[next_index] = nstep;
		FindPathsRec(gcurr, max_moves, r, c + 1, nstep + 1, nsol);
		gcurr->cells[next_index] = 0;
	}

	//provo a spostarmi in alto
	next_index = (r - 1) * gcurr->cols + c;
	if (r > 0 && gcurr->cells[next_index] != -1 && gcurr->cells[next_index] == 0) {
		gcurr->cells[next_index] = nstep;
		FindPathsRec(gcurr, max_moves, r - 1, c, nstep + 1, nsol);
		gcurr->cells[next_index] = 0;
	}

}

int FindPaths(const struct Grid* g, int max_moves) {
	int nsol = 0;
	struct Grid gcurr = {
		.rows = g->rows,
		.cols = g->cols,
		.cells = malloc(g->rows * g->cols * sizeof(int))
	};
	memcpy(gcurr.cells, g->cells, g->rows * g->cols * sizeof(int));
	gcurr.cells[0] = 1;
	FindPathsRec(&gcurr, max_moves, 0, 0, 2, &nsol);
	return nsol;
}

void PrintGrid(const struct Grid* g) {
	char* line = malloc(g->cols * 4 + 2);
	for (int c = 0; c < (int)g->cols; c++) {
		strcpy(line + c * 4, "+---");
	}
	line[g->cols * 4] = '+';
	line[g->cols * 4 + 1] = 0;

	for (int r = 0; r < g->rows; r++) {
		printf("%s\n", line);
		for (int c = 0; c < g->cols; c++) {
			int curr_cell = g->cells[r * g->cols + c];
			curr_cell == -1 ? printf("| B ") : printf("|%2d ", curr_cell);
		}
		putchar('|');
		puts("");
	}
	printf("%s\n", line);
}

