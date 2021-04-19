vector<pair<int, int> > prime_fact(int n) {
  vector<pair<int,int>> pf;
  int count = 0;
  while (!(n % 2)) { // count the number of times 2 divides 
    n >>= 1; // equivalent to n=n/2;
    count++;
  }
  if (count)pf.pb({2,count}); // if 2 divides it
  for (long long i = 3; i <= sqrt(n); i += 2) { // check for all the possible numbers
    count = 0;
    while (n % i == 0) {
      count++;
      n = n / i;
    }
    if (count)pf.pb({i,count});
  }
  if (n > 2)pf.pb({n,1}); // if n at the end is a prime number.
  return pf;
}
