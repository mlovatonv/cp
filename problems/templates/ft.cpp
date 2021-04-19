ll ft[nmax]; // The following implementation uses one-based indexing.
 
void add(int idx,ll val){
  for(++idx;idx<realn;idx+=idx&-idx){
    ft[idx]+=val;
  }
}
 
void range_add(int l,int r,ll val){
  add(l,val);
  add(r+1,-val);
}
 
ll point_query(int idx){
  ll ans=0;
  for(++idx;idx>0;idx-=idx&-idx){
    ans+=ft[idx];
  }
  return ans;
}
