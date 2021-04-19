#define MAX 892
int SPF[MAX];
void sieve(int n=MAX) {
    bool isPrime[n+1];
    for (int i=1; i<=n; i++) isPrime[i] = 1;
    isPrime[1] = 0;
    for (int i=2; i<=n; i++) {
        // assert isPrime == True
        if (!isPrime[i]) continue;
        /* j*(i-1) is a factor of (i-1) and was covered before
           Therefore start from i*i */
        SPF[i] = i;
        for (int j=i*i; j<=n; j+=i)
            if (isPrime[j]) isPrime[j] = 0, SPF[j] = i;
    }
}
vector<pair<int, int> > prime_fact(int n) {
    vector<pair<int, int> > pf;
    while (n!=1) {
        int p = SPF[n], count = 0;
        while (n%p==0) n/=p, ++count;
        pf.push_back({p, count});
    }
    return pf;
}
