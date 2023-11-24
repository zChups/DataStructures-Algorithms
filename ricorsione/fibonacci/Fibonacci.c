
int FibonacciRec(int n) {
	if (n == 0 || n == 1)return n;
	else {
		return FibonacciRec(n - 1) + FibonacciRec(n - 2);
	}
}

int Fibonacci(int n) {
	if (n < 0)return -1;
	return FibonacciRec(n);
}

