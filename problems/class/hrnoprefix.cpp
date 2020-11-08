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
const int nmax=2e6;
const int abc=27;

string s1,s2="";
int n;
int trie[nmax][abc];
bool isword[nmax];
int triesize;
int num[nmax];

//return true if two words have the same prefix
bool add(string a){
  int curr=0,next,i;
  for(auto c:a){
    ++num[curr];
    if(curr!=0&&num[curr]>1&&isword[curr]){
      return true;
    }
    i=c-'a';
    if(trie[curr][i]==0){
      trie[curr][i]=++triesize;
    }
    curr=trie[curr][i];
  }
  ++num[curr];
  isword[curr]=true;
  return num[curr]>1;
}

int main(void){
  fastio;
  cin>>n;
  rep(i,0,n){
    cin>>s1;
    if(s2==""){
      if(add(s1)){
        s2=s1;
      }
    }
  }
  if(s2==""){
    cout<<"GOOD SET"<<endl;
  }else{
    cout<<"BAD SET"<<endl<<s2<<endl;
  }
  return 0;
}
