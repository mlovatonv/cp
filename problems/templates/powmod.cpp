long long powmod(long long x, long long y) {
	long long res = 1;
	for (long long i = 0; i < y; i++) {
		res = res * x % MOD;
	}
	return res;
}
