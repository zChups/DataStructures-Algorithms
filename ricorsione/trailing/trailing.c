unsigned int TrailingZeros(unsigned int n) {
	if (n == 0) {
		return 0;
	}
	unsigned int tmp = n;
	unsigned int count = 0;
	while (tmp % 2 == 0) {
		count++;
		tmp /= 2;
	}
	return count + TrailingZeros(n - 1);
}