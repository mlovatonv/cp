#include<iostream>
using namespace std;
int main(){
  int arr1[3]={1,2,3};
  int arr2[3]={4,5,6};
  copy(arr1,arr1+3,arr2);
  for(int i=0;i<3;++i)cout<<arr2[i]<<endl;
}
