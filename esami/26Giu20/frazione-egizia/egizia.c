#include <stdio.h>
#include <math.h>

static void FrazioneEgiziaRec(int n, int d, int i) {
	int d_n = ceil((double)d / (double)n);
	if (i == 0) {
		printf("1/%d", d_n);
	}
	else {
		printf(" + 1/%d", d_n);
	}
	if (d % n == 0)return;
	FrazioneEgiziaRec(n * d_n - d, d * d_n, i+1);
}

void FrazioneEgizia(int n, int d) {
	if (n <= 0 || d <= 0 || n >= d) {
		printf("Impossibile convertire la frazione data in frazione egizia\n");
	}
	else {
		FrazioneEgiziaRec(n, d, 0);
	}
}