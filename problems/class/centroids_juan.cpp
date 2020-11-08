#include<bits/stdc++.h>

#define PB push_back
#define F first
#define S second
#define FOR(i,a,b) for (int i=(a); i<=(b);i++)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int N=1e6+10;

vi adj[N];
int n, k, tam[N], dist[N], proc[N];
ll cnt;

void read () {
    cin >> n >> k;
    int u, v;
    FOR(i,1,n-1) {
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
}

void dfsTam(int x, int y) {
    int cont=1;
    for (auto u: adj[x]) {
        if (u==y || proc[u]) continue;
        dfsTam(u,x);
        cont+=tam[u];
    }
    tam[x]=cont;
}

void dfsDist(int x, int y, int d) {
    dist[d]++;
    for (auto u: adj[x]) {
        if (proc[u]|| u==y) continue;
        dfsDist(u,x,d+1);
    }
}

void dfsClearDist(int x, int y, int d) {
    dist[d]--;
    for (auto u: adj[x]) {
        if (proc[u]|| u==y) continue;
        dfsClearDist(u,x,d+1);
    }
}

pii getCentroid (int x, int y, int sz) {
    for (auto u: adj[x]) {
        if (proc[u] || u==y) continue;
        if (tam[u]>sz/2) {
            return getCentroid (u,x,sz);
        }
    }
    return {x,y};
}

void dfsU(int u, int p, int d) {
    if (d>=k) return;
    cnt+=dist[k-d];
    for (auto v: adj[u]) {
        if (proc[v] || v==p) continue;
        dfsU(v,u,d+1);
    }
}

void cantX(int x) {
    cnt+=2*dist[k];
    for (auto u:adj[x]) {
        if (proc[u]) continue;
        dfsClearDist(u,x,1);
        dfsU(u,x,1);
        dfsDist(u,x,1);
    }
}

void dfsMain (int x, int y, int sz) {
    FOR(i,0,k) dist[i]=0;
    dfsDist(x,0,0);

    cantX(x); //contar los caminos que contienen a x en O(n)
    proc[x]=1;

    for (auto u:adj[x]) {
        if (proc[u]) continue;
        int nsz = (u==y)?sz-tam[x]:tam[u];
        dfsTam(u,0);
        pii par = getCentroid (u,0,nsz);
        int xx = par.F; //centroide
        int yy = par.S; //padre del centroide
        dfsMain(xx,yy,nsz);
    }

}

int main () {
    read ();
    dfsTam(1,0);
    pii par =getCentroid (1,0,n);
    int x = par.F; //centroide
    int y = par.S; //padre del centroide en el dfs de getCentroid
    dfsMain (x, y, n);
    cout << cnt/2 << endl;
}