/*
 * Time complexity: O(Nn)
 * Explanation: n is the length of the path. n elements are checked and if it
 * is an 'F' instruction, the corresponding DP is updated, by iterating through
 * all its N elements.
 *
 * Space complexity: O(N)
 * Explanation: two arrays of size N are stored for all possible coordinates
 * in each axis.
 *
 * Idea: Go over the path and depending on the letter, change the direction or
 * update the arrays contents. These arrays save how many steps are needed to
 * get to a coordinate in an axis.
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define rep(i,s,e) for(int i=s;i<e;++i)
#define fi first
#define se second
using namespace std;

const int N=16001;
string s;
int n,x,y;
bool dpx[N],dpy[N],aux[N];

int main(void){
  fastio;
  cin>>s;
  cin>>x>>y;
  x+=8000;
  y+=8000;
  n=s.size();
  dpx[8000]=true;
  dpy[8000]=true;
  int steps=0;
  /*R=RIGHT X=LEFT/RIGHT Y=UP/DOWN*/
  char dir='R';
  rep(i,0,n){
    if(s[i]=='T'){
      dir=dir=='R'||dir=='X'?'Y':'X';
    }else{
      steps=1;
      while(s[i+1]=='F'){++i;++steps;}
      memset(aux,0,N*sizeof(bool));
      if(dir=='R'){
        rep(j,0,N)
          if(dpx[j]){
            aux[j+steps]=true;
            aux[j]=false;
          }
        copy(aux,aux+N,dpx);
      }else if(dir=='X'){
        rep(j,0,N)
          if(dpx[j]){
            aux[j+steps]=true;
            aux[j-steps]=true;
            aux[j]=false;
          }
        copy(aux,aux+N,dpx);
      }else if(dir=='Y'){
        rep(j,0,N)
          if(dpy[j]){
            aux[j+steps]=true;
            aux[j-steps]=true;
            aux[j]=false;
          }
        copy(aux,aux+N,dpy);
      }
    }
  }
  if(dpx[x]&&dpy[y])cout<<"Si"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
