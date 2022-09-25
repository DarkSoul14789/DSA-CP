#include <bits/stdc++.h>

using namespace std;

int times_array_is_rotated(vector<int>& nums){
  int start = 0;
  int end = nums.size()-1;
  if(nums[start]<=nums[end]){
    return 0;
  }
  int n = nums.size();
  while(start<=end){
    int mid = start + (end-start)/2;
    int next = (mid+1)%n;
    int prev = (mid+n-1)%n;
    // cout<<next<<" "<<prev<<'\n';
    if(nums[mid]<=nums[next] && nums[mid]<nums[prev])
      return n-mid;
    // Move towards unsorted array
    if(nums[0]<=nums[mid])
      start = mid+1;
    else if(nums[n-1]>nums[mid])
      end = mid-1;;
  }
  return 0;
}

int main(){
  vector<int> v = {6,8,11,12,15,18,2,5};
  int res = times_array_is_rotated(v);
  cout<<res;
}