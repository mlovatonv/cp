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

string s1,s2;
int q;
int trie[nmax][abc];
bool isword[nmax];
int triesize;
int num[nmax];

void add(string a){
  int curr=0,next,i;
  for(auto c:a){
    ++num[curr];
    i=c-'a';
    //cout<<"curr="<<curr<<" c="<<c<<endl;
    if(trie[curr][i]==0){
      trie[curr][i]=++triesize;
    }
    curr=trie[curr][i];
  }
  isword[curr]=true;
  ++num[curr];
}

int find(string a){
  int curr=0,next,i;
  for(auto c:a){
    i=c-'a';
    next=trie[curr][i];
    if(next==0){
      return 0;
    }
    curr=next;
  }
  return num[curr];
}

int main(void){
  fastio;
  cin>>q;
  while(q--){
    cin>>s1>>s2;
    if(s1=="add"){
      add(s2);
    }else{
      cout<<find(s2)<<endl;     
    }
    //cout<<s1<<' '<<s2<<endl;
    //rep(i,0,11)cout<<num[i]<<' ';
    //cout<<endl;
    //cout<<"trie[2][c]="<<trie[2]['c']<<endl;
    //cout<<endl;
  }
  return 0;
}
