#ifndef ROBOT_GRID_H_
#define ROBOT_GRID_H_

#include <stdint.h>
struct Grid {
	size_t rows, cols;
	int* cells;
};

extern int FindPaths(const struct Grid* g);
extern void PrintGrid(const struct Grid* g);
#endif // !ROBOT_GRID_H_
