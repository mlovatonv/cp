/*
 * Time complexity: O(n^2)
 * Explanation: We need to calculate the number of funny sub-divisions for each position
 * in the target string. This calculation takes at maximum n steps, the length of the
 * string.
 *
 * Space complexity: O(m*alp+n+m)
 * Explanation: We need a matrix of size mxalp to store the trie states. Also, we need
 * an array of n for the dp and an array m to store the number of ocurrences of the nodes
 * in the trie.
 *
 * Idea: The input substrings are inserted in the trie backwards to access their suffixes
 * directly. Using this, we form dp[i] = the number of ways to build a funny sub-division
 * for the prefix of size i of the target string. dp[0] = 1 because the empty string is a
 * funny sub-division. To fill dp[i], we need to sum the previous dp values multiplied by
 * the ocurrences of its complementary substring in the prefix. Having the suffixes is
 * useful to get all the possibilities.
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define rrep(i,s,e) for(int i=s;i>=e;--i)
#define rep2(i,s,e) for(int i=s;i<e;i+=2)
#define ret(i,c) for(auto i=c.rbegin();i!=c.rend();++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
using namespace std;
using ll=long long;

const ll mod=1e9+7;
const int nmax=1e4,mmax=2e6,alp=30;
ll dp[nmax],num[mmax];
int tam,trie[mmax][alp];
int n,l;
string s,ss;
 
void update(){
  int i=0,j=0;
  ret(c,ss){
    j=(*c)-'a';
    if(trie[i][j]==0)trie[i][j]=++tam;
    i=trie[i][j];
  }
  ++num[i];
}

int main(){
  fastio;
  cin>>s;
  n=len(s);
  if(n%2!=0){cout<<0<<endl;return 0;}
  cin>>l;
  rep(i,1,l){
    cin>>ss;
    if(len(ss)%2!=0)continue;
    if(len(ss)>n)continue;
    update();
  }
  dp[0]=1;
  int c,k;
  ll aux;
  rep(i,1,n){
    if(i%2!=0)continue;
    k=0;
    rrep(j,i-1,0){
      c=s[j]-'a';
      k=trie[k][c];
      if(k==0)break;
      aux=(num[k]*dp[j])%mod;
      dp[i]=(dp[i]+aux)%mod;
    }
  }
  cout<<dp[n]<<endl;
  return 0;
}

