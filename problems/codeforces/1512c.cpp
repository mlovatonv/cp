#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
using ll=long long;
using vi=vector<int>;

int t;
int a,b,n,l,r;
string s;

bool can_be_palindrome(){
  if(a%2&&b%2){
    return false;
  }
  l=0,r=n-1;
  while(l<r){
    if(s[l]==s[r]||s[l]=='?'||s[r]=='?'){
      ++l;
      --r;
    }else{
      return false;
    }
  }
  return true;
}

void fill_one_char(){
  l=0,r=n-1;
  while(l<r){
    if(s[l]=='?'&&s[r]!='?')s[l]=s[r];
    elif(s[l]!='?'&&s[r]=='?')s[r]=s[l];
    if(s[l]=='1')a-=2;
    elif(s[l]=='0')b-=2;
    ++l;
    --r;
  }   
}

void fill_two_chars(){
  l=0,r=n-1;
  while(l<r){
    if(s[l]=='?'&&s[r]=='?'){
      if(a>1)s[l]=s[r]='1';
      else s[l]=s[r]='0';
      if(s[l]=='1')a-=2;
      else b-=2;
    }
    ++l;
    --r;
  } 
}

void fill_middle(){
  if(n%2){
    if(s[n/2]=='?'){
      if(a==1)s[n/2]='1';
      else s[n/2]='0';
    }
    if(s[n/2]=='1')--a;
    else --b;     
  }   
}

void solve(){
  cin>>b>>a;
  cin>>s;
  n=a+b;
  if(!can_be_palindrome()){
    cout<<-1<<endl;
    return; 
  }
  fill_one_char();
  fill_two_chars(); 
  fill_middle(); 
  if(a!=0||b!=0){
    cout<<-1<<endl;
    return;
  }
  cout<<s<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,0,t)solve();
  return 0;
}

