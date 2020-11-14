#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define itr(i,c) for(auto i:c)
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;

const ll mod=1e9+7;
const int hmax=205*4,wmax=55*4;
map<char,string> to2;
string g[wmax];
int h,w,n;
char tosol[6]={'W','A','K','J','S','D'};
vector<char> sol;
int cnt;

void build(){
  to2['0']="0000";
  to2['1']="0001";
  to2['2']="0010";
  to2['3']="0011";
  to2['4']="0100";
  to2['5']="0101";
  to2['6']="0110";
  to2['7']="0111";
  to2['8']="1000";
  to2['9']="1001";
  to2['a']="1010";
  to2['b']="1011";
  to2['c']="1100";
  to2['d']="1101";
  to2['e']="1110";
  to2['f']="1111";
}

void dfs1(int a,int b){
  if(a<0||h<=a||b<0||w<=b||g[a][b]=='1'||g[a][b]=='2')return;
  g[a][b]='2';
  dfs1(a-1,b);
  dfs1(a+1,b);
  dfs1(a,b-1);
  dfs1(a,b+1);
}

void dfs2(int a,int b){
  if(a<0||h<=a||b<0||w<=b||g[a][b]=='1'||g[a][b]=='2')return;
  g[a][b]='2';
  dfs2(a-1,b);
  dfs2(a+1,b);
  dfs2(a,b-1);
  dfs2(a,b+1);
}

void dfs3(int a,int b){
  if(a<0||h<=a||b<0||w<=b||g[a][b]=='2')return;
  if(g[a][b]=='0'){
    ++cnt;
    dfs2(a,b);
  }else{
    g[a][b]='2';
    dfs3(a-1,b);
    dfs3(a+1,b);
    dfs3(a,b-1);
    dfs3(a,b+1);
  }
}

void clear(){
  sol.clear();
  rep(i,0,h+2){
    g[i].clear();
  }
}

void solve(){
  clear();
  w*=4;
  w+=2;
  rep(i,0,w)g[0]+="0";
  rep(i,1,h+1){
    string s;
    cin>>s;
    g[i]+="0";
    itr(j,s)g[i]+=to2[j];
    g[i]+="0";
  }
  rep(i,0,w)g[h+1]+="0";
  h+=2;
  
  //cout<<"before dfs1"<<endl;
  //rep(i,0,h){
  //  cout<<g[i]<<endl;
  //}

  dfs1(0,0); //paint borders
  
  //cout<<"before dfs3"<<endl;
  //rep(i,0,h){
  //  cout<<g[i]<<endl;
  //}
  
  rep(i,0,h)
    rep(j,0,w)
      if(g[i][j]=='1'){
        cnt=0;
        dfs3(i,j); //count rings
        sol.pb(tosol[cnt]);
      }
  
  //cout<<"after dfs3"<<endl;
  //rep(i,0,h){
  //  cout<<g[i]<<endl;
  //}
  
  sort(all(sol));
  ++n;
  cout<<"Case "<<n<<": ";
  itr(i,sol){
    cout<<i;
  }
  cout<<endl;
}

int main(){
  fastio;
  build();
  while(cin>>h>>w&&h!=0){
    solve();     
  }
  return 0;
}
