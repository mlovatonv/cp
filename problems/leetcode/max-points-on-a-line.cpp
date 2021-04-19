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
using pdi=pair<double,int>;
using pii=pair<int,int>;

double slope(pii a,pii b){
  return ((double)a.se-b.se)/((double)a.fi-b.fi); 
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& _points) {
        vector<pii> points;
        ret(i,_points)points.pb(mp(i[0],i[1]));
        sort(all(points));
        int pointsSize=len(points);
        vector<vector<pdi>> matrix(pointsSize,vector<pdi>(pointsSize));
        rep(i,0,pointsSize){
          rep(j,i+1,pointsSize){
            double s=slope(points[i],points[j]);
            int q=1;
            rep(k,0,pointsSize)if(matrix[k][i].fi==s)q=max(q,matrix[k][i].se);
            matrix[i][j]=mp(s,q+1);
          } 
        }
        int ans=1;
        rep(i,0,pointsSize)rep(j,0,pointsSize)ans=max(ans,matrix[i][j].se);
        return ans;
    }
};

int main(){
  fastio;
  Solution sol;
  vector<vector<int>> points = {
    {1,1},
    {2,2},
    {3,3}
  };
  cout<<sol.maxPoints(points)<<endl;
  return 0;
}

