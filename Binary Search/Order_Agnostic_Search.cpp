#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int>& nums, int k){
  int start = 0;
  int end = nums.size()-1;
  if(nums[start]>=nums[end]){
    while(end>=start){
      int mid = start + (end-start)/2;
      if(k==nums[mid])
        return mid;
      else if(k>nums[mid])
        end = mid-1;
      else
        start = mid+1;
    }
    return -1;
  }
  else{
    while(end>=start){
      int mid = start + (end-start)/2;
      if(k==nums[mid])
        return mid;
      else if(k>nums[mid])
        start = mid+1;
      else
        end = mid-1;
    }
    return -1;
  }

}

int main(){
  vector<int> v1 = {9,8,7,4,3,1};
  int k = 3;
  vector<int> v2 = {1,2,3,4,5,6};
  cout<<binary_search(v1,k)<<"\n";
  cout<<binary_search(v2,k);
}