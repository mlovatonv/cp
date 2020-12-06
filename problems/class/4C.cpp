/*
 * Time complexity: O(n)
 * Explanation: An efficient implementation to compute the z-function costs O(n).
 *
 * Space complexity: O(n)
 * Explanation: We need an array of size 2n to store the values of the z-function.
 *
 * Idea: The z-function of a string s is an array where z[i] is the length of the longest
 * common prefix between s and the suffix of s starting at i. The problem is to compare
 * the characters of a prefix in odd positions to the characters of a suffix in odd or
 * even positions. The problem can be reduced to find the number of prefixes that are
 * equal to a suffix. If the size of the string is odd, we only use the characters of a
 * suffix that are in even positions. Otherwise, we only consider odd positions. The
 * z-function is used to calculate what suffixes are equal to a prefix, this happens when
 * the size of the longest common prefix is equal to its size. We need to concatenate the
 * characters in odd positions (prefixes) to the characters in odd/even (this depends on
 * the size of the string as we mentioned before) positions (suffixes). The new string is
 * the one used to compute the z-function. If its value in the position i is equal n-i,
 * the suffix and prefix are equal. Finally, the answer if the number of positions i in
 * the suffixes part that satisfy this condition.
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define rep2(i,s,e) for(int i=s;i<e;i+=2)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
using namespace std;
using ll=long long;

const int nmax=1e6;
string ss,s;
int nn,n,a,ans;
int z[nmax];

void build(){
  //https://cp-algorithms.com/string/z-function.html 
  for(int i=1,l=0,r=0;i<n;++i){
    if(i<=r)z[i]=min(r-i+1,z[i-l]);
    while(i+z[i]<n&&s[z[i]]==s[i+z[i]])++z[i];
    if(i+z[i]-1>r)l=i,r=i+z[i]-1;
  }
}

int main(){
  fastio;
  cin>>ss;
  nn=len(ss);
  rep2(i,0,nn)s+=ss[i];
  a=len(s);
  rep2(i,nn%2?0:1,nn)s+=ss[i];
  n=len(s);
  build();
  //rep(i,0,n)cout<<"z["<<i<<"]="<<z[i]<<endl;
  rep(i,a,n)if(z[i]==n-i)++ans;
  cout<<ans<<endl;
  return 0;
}

