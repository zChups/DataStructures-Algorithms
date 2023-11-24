#ifndef ROBOT_GRID_H_
#define ROBOT_GRID_H_

struct Grid {
	size_t rows, cols;
	int* cells;
};

extern int FindPaths(const struct Grid* g, int max_moves);
extern void PrintGrid(const struct Grid* g);

#endif // !ROBOT_GRID_H_
