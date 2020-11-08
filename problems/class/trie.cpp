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
const int N=2e6+1e5+10;
const int S=50;

int tam,num[N],trie[N][S];

int find(string s){
  int i=0;
  for(auto c:s){
    c-='a';
    i=trie[i][c];
    if(i==0)return 0;
  }
  return num[i];
}

void update(string s){
  int i=0;
  for(auto c:s){
    c-='a';
    if(trie[i][c]==0){
      trie[i][c]=++tam;
    }
    i=trie[i][c];
    num[i]++;
  }
}

int main(void){
  fastio;
  int n,t;
  cin>>t;
  while(t--){
    string op,s;
    if(op=="add"){
      update(s);
    }else{
      cout<<find(s)<<endl;
    }
  }
  return 0;
}
