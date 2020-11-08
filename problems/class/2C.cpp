/*
 * Time complexity: O(n^2)
 * Explanation: n elements are checked n times
 *
 * Space complexity: O(n)
 * Explanation: n elements are stored
 *
 * Idea: The goal is to group N and H circularly. In other words, divide the
 * circle in two. This can be translated to an array divided in two equal parts.
 * To ensure that the minimum value is reached, all possible arrays must be
 * checked. So, n arrays are generated for different starting positions. The 
 * number of swaps is equal to the number of letters in the wrong partition. In
 * this case, the 'H's partition is considered as the first part.
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define rep(i,s,e) for(int i=s;i<e;++i)
#define fi first
#define se second
using namespace std;

const int N = 1005;
string s;
char c[N];
int n,nH,minSwaps=INT_MAX;

int getSwaps(){
  int swaps=0;
  rep(i,0,nH)if(c[i]=='T')++swaps;
  return swaps; 
}

int main(void){
  fastio;
  cin>>n;
  cin>>s;
  rep(i,0,n)if(s[i]=='H')++nH;
  if(nH==0||nH==n){cout<<'0'<<endl;return 0;}
  rep(i,0,n){
    int k=0;
    rep(j,i,n)c[k++]=s[j];
    rep(j,0,i)c[k++]=s[j];
    int m=getSwaps();
    //cout<<i<<' '<<m<<endl;
    minSwaps=min(minSwaps,m);
  }
  cout<<minSwaps<<endl;
  return 0;
}
