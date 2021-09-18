using vll=vector<pair<ll,ll>>;

vll prime_fact(ll n){
  vll pf;
  ll count=0;
  while (!(n%2LL)){ // count the number of times 2 divides 
    n>>=1LL; // equivalent to n=n/2;
    count++;
  }
  if (count)pf.pb({2,count}); // if 2 divides it
  for (ll i=3;i<=sqrtl(n);i+=2) { // check for all the possible numbers
    count=0;
    while(n%i==0){
      count++;
      n/=i;
    }
    if (count)pf.pb({i,count});
  }
  if(n>2)pf.pb({n,1}); // if n at the end is a prime number.
  return pf;
}
