#include <stdio.h>
#include <stdlib.h>
static void BabboNataleRec(const int* pacchi, size_t pacchi_size, 
							int p, int p_curr, int* vcurr, int* vbest, size_t i, int cnt, int* cnt_best) {
	if (i == pacchi_size) {
		if (*cnt_best < cnt) {	//soluzione migliore
			*cnt_best = cnt;
			for (size_t j = 0; j < pacchi_size; j++) {	//riempio vbest
				vbest[j] = vcurr[j];
			}
		}
		return;
	}

	vcurr[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, p_curr, vcurr, vbest, i + 1, cnt, cnt_best);
	vcurr[i] = 1;
	p_curr += pacchi[i];
	if (p_curr > p)return;
	BabboNataleRec(pacchi, pacchi_size, p, p_curr, vcurr, vbest, i + 1, cnt + 1, cnt_best);
	p_curr -= pacchi[i];
	vcurr[i] = 0;
}


void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {
	int* vcurr = calloc(pacchi_size, sizeof(int));
	int* vbest = calloc(pacchi_size, sizeof(int));
	int cnt_best;

	BabboNataleRec(pacchi, pacchi_size, p, 0, vcurr, vbest, 0, 0, &cnt_best);
	for (size_t j = 0; j < pacchi_size - 1; j++) {
		printf("%d ", vbest[j]);
	}
	printf("%d\n", vbest[pacchi_size - 1]);

	free(vcurr);
	free(vbest);
}