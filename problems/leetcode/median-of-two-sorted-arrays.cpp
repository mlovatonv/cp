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

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int nums1Size=len(nums1);
      int nums2Size=len(nums2);
      int numsSize=nums1Size+nums2Size;
      vi nums(numsSize);
      int idx1=0,idx2=0;
      rep(idx,0,numsSize){
        if(idx1<nums1Size&&idx2<nums2Size){
          if(nums1[idx1]<nums2[idx2]){
            nums[idx]=nums1[idx1];
            ++idx1;  
          }else{
            nums[idx]=nums2[idx2];
            ++idx2;    
          }
        }else if(idx1<nums1Size){
          nums[idx]=nums1[idx1];
          ++idx1;
        }else if(idx2<nums2Size){
          nums[idx]=nums2[idx2];
          ++idx2;
        }
      }
      double ans=numsSize%2?
        nums[numsSize/2]:
        (nums[numsSize/2]+nums[numsSize/2-1])/2.0;
      return ans;
    }
};

int main(){
  fastio;
  Solution sol;
  vi v1{1,2};
  vi v2{3,4};
  cout<<sol.findMedianSortedArrays(v1,v2)<<endl;
  return 0;
}

