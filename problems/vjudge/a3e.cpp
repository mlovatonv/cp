#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define rrep(i,s,e) for(int i=s;i>=e;--i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const ll mod=1e9+7;
const int nmax=2e5+10;

int n;
int a[nmax];
map<int,int> m;
int mxx;
int mx;
int aux1;
int aux2;
vi ans;

int main(){
  fastio;
  scanf("%d",&n);
  rep(i,0,n){
    scanf("%d",&a[i]);
    aux1=a[i];
    aux2=aux1-1;
    if(m.find(aux2)!=m.end())
      m[aux1]=max(m[aux1],m[aux2]+1);
    else
      m[aux1]=1;
    if(m[aux1]>mxx){
      mxx=m[aux1];
      mx=aux1;
    }
  }

  if(mxx==1){
    printf("1\n1\n");
    return 0;
  }

  rrep(i,n-1,0){
    if(a[i]==mx){
      ans.pb(i+1);
      --mx;
    }
  }
  reverse(all(ans));
  printf("%d\n",ans.size());
  ret(i,ans)printf("%d ",i);
  printf("\n");
  return 0;
}
