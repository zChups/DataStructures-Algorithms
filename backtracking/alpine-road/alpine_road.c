#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "alpine_road.h"

void FindPathRec(const Point* p, size_t p_size, int dh, int* vcurr, int* vbest, int i) {
	if (i == 2) {
		int best_dist = vbest[0] == -1 ? 0 : p[vbest[1]].s - p[vbest[0]].s;
		int curr_dist = p[vcurr[1]].s - p[vcurr[0]].s;
		if (curr_dist > best_dist)memcpy(vbest, vcurr, sizeof(int) * 2);
		return;
	}

	if (i == 0) {
		for (int j = 0; j < (int)p_size - 1; j++) {
			vcurr[0] = j;
			FindPathRec(p, p_size, dh, vcurr, vbest, i + 1);
		}
	}
	else {
		for (int j = vcurr[0]+1; j < (int)p_size; j++) {
			if (abs(p[vcurr[0]].h - p[j].h) > dh)break;
			vcurr[1] = j;
			FindPathRec(p, p_size, dh, vcurr, vbest, i + 1);
		}


	}
}

int FindPath(const Point* p, size_t p_size, int dh) {
	int vcurr[2], vbest[] = { -1,-1 };
	FindPathRec(p, p_size, dh, vcurr, vbest, 0);
	if (vbest[0] == -1)return -1;

	for (int i = vbest[0]; i < vbest[1]; i++) {
		printf("%c: ( %3d, %3d)\n", 'A' + i, p[i].s, p[i].h);
	}
	return p[vbest[1]].s - p[vbest[0]].s;
}