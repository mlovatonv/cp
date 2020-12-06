/*
 * Time complexity: O(nm)
 * Explanation: We need to generate a matrix of size (n+1)x(m+1) to store the states for
 * the dp technique. To fill out the matrix, we need to iterate through all its elements.
 *
 * Space complexity: O(nm)
 * Explanation: 2 matrix of size nxm are needed to store the states and the parents of
 * each one.
 *
 * Idea: dp[i][j] = the minimum edit distance between s1[1...i] and s2[1...j].
 * dp[0][0] = 0 because two empty strings are the same and dp[0][i] and dp[i][0] for i > 0
 * are filled with i because we are comparing an empty string with a non-empty string of
 * size i. In every state of the matrix, the minimum value will be chosen. In this case,
 * we are considering operations from s1 to s2. So, adding costs dp[i-1][j]+1 (we are
 * adding s1[i]), deleting costs dp[i][j-1]+1 (we are removing s1[i]) and replacing costs
 * dp[i-1][j-1]+1 or dp[i-1][j-1], depending on the parity of the last characters (we are
 * replacing s1[i] with s2[j] or vice versa). If the last characters are the same, the
 * cost is dp[i-1][j-1]. The costs are compared and the minimum one is chosen. To get the
 * alignments, we use a parent matrix to store the parent for each state and then we go
 * from n,m to 0,0 to get them.
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll mod=1e9+7;
const int nmax=5e3+5;

string s1,s2,ans1,ans2;
int n,m;
int dp[nmax][nmax];
pii p[nmax][nmax];

int main(){
  fastio;
  cin>>s1>>s2;
  n=len(s1);
  m=len(s2);
  rep(i,1,n+1){
    dp[i][0]=i;
    p[i][0]={i-1,0};
  }
  rep(i,1,m+1){
    dp[0][i]=i;
    p[0][i]={0,i-1};
  }
  rep(i,1,n+1){
    rep(j,1,m+1){
      int add=dp[i-1][j]+1;
      int del=dp[i][j-1]+1;
      if(add<del){
        p[i][j]={i-1,j};
        dp[i][j]=add;
      }else{
        p[i][j]={i,j-1};
        dp[i][j]=del;
      }
      int mod;
      if(s1[i-1]%2==s2[j-1]%2) mod=dp[i-1][j-1];
      else mod=dp[i-1][j-1]+1;
      if(mod<dp[i][j]){
        p[i][j]={i-1,j-1};
        dp[i][j]=mod;
      }
    }
  }
  cout<<dp[n][m]<<endl;
  int i=n,j=m;
  pii x;
  while(i!=0||j!=0){
    x=p[i][j];
    if(x.fi==i-1&&x.se==j){
      ans1+=s1[x.fi];
      ans2+='-';
    }elif(x.fi==i&&x.se==j-1){
      ans1+='-';
      ans2+=s2[x.se];
    }elif(x.fi==i-1&&x.se==j-1){
      ans1+=s1[x.fi];
      ans2+=s2[x.se];
    }
    i=x.fi;
    j=x.se;
  }
  reverse(all(ans1));
  reverse(all(ans2));
  cout<<ans1<<endl;
  cout<<ans2<<endl;
  return 0;
}
