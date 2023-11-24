#include <stdlib.h>
#include <stdio.h>

#include "robot.h"

int main(void) {
	{
		struct Grid g = {
			.rows = 3,
			.cols = 5,
			.cells = calloc(g.rows * g.cols, sizeof(int))
		};
		g.cells[1] = g.cells[8] = -1;
		PrintGrid(&g);
		puts("");
		FindPaths(&g);
	}
	return 0;
}