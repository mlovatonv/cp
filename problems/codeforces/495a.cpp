#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;

int n;
int opt[10]={2,7,2,3,3,4,2,5,1,2};

int main(void){
  fastio;
  cin>>n;
  cout<<opt[n/10]*opt[n%10]<<endl;
  return 0;
}
