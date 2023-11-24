#ifndef NONOGRAMS_H_
#define NONOGRAMS_H_

typedef struct {
	size_t rows, cols;
	int** r_constr, ** c_constr;
}Constraints;

extern void Nonogram(const Constraints* constr);
#endif // !NONOGRAMS_H_
