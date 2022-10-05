#include <bits/stdc++.h>

using namespace std;
// Check k with mid-1, mid, and mid+1 elements

int modifiedBinarySearch(vector<int>& nums, int k){
  int start = 0;
  int end = nums.size()-1;
  int n = nums.size();
  while(start<=end){
    int mid = start+(end-start)/2;
    if(nums[mid]==k)
      return mid;
    else if((mid-1)>=start && nums[mid-1]==k)
      return mid-1;
    else if((mid+1)<=end && nums[mid+1]==k)
      return mid+1;
    else if(nums[mid]>k)
      end = mid-2;
    else
      start = mid+2;
  }
  return -1;
}

int main(){
  vector<int> v = {10, 3, 40, 20, 50, 80, 70};
  int k = 3;
  cout<<modifiedBinarySearch(v,k);
}