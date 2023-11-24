#ifndef COLORMAP_H_
#define COLORMAP_H_

#include <stdbool.h>

struct SquareMatrix {
	size_t side;
	bool* data;
};

extern int ColorMap(const struct SquareMatrix* m, const char* c);
#endif // !COLORMAP_H_
