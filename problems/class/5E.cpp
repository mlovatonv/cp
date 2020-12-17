/*
 * Time complexity: O(n)
 * Explanation: In the worst case, we would need to check the n nodes to get the ones
 * with an odd degree.
 *
 * Space complexity: O(n)
 * Explanation: An array is used to store the degree of the n nodes.
 *
 * Idea: Para que en cada vertice, el numero de aristas que entran sea igual al numero de
 * aristas que salen de este, se tiene que agregar aristas a los vertices con grado
 * impar porque en estas no es posible que se cumpla la condicion. Para hallar el minimo
 * costo, solo se tendrian que hallar los dos vertices con grado impar de menor valor y
 * anadir una arista entre estos. Dado que la funcion de costo es solo una multiplicacion 
 * con modulo (en este caso el modulo no afecta porque el mayor costo es 4e8), se pueden
 * hallar estos valores verificando los nodos desde 1 a n y multiplicandolos.
 * */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
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

const int nmax=2e4+10;
int n,m;
int g[nmax];

int main(){
  fastio;
  cin>>n>>m;
  rep(i,1,m){
    int u,v;
    cin>>u>>v;
    ++g[u];
    ++g[v];
  }
  int min1=0,min2=0;
  rep(i,1,n){
    if(g[i]%2){
      if(!min1)min1=i;
      elif(!min2){
        min2=i;
        break;
      }
    }
  }
  cout<<min1*min2<<endl;
  return 0;
}

