#include <bits/stdc++.h>

using namespace std;

// Given an infinite sorted array consisting 0s and 1s. The problem is to find the index of first ‘1’ in that array. As the array is infinite, therefore it is guaranteed that number ‘1’ will be present in the array.

int Search(vector<int>& nums){
  int low = 0;
  int high = 1;
  int res = -1;
  while(nums[high]!=1){
    low = high;
    high = 2*high;
  }
  res = high;
  // cout<<"res "<<res;
  // cout<<"\nlow "<<low;
  // cout<<"\nhigh "<<high;
  // Binary serach until 1st 1 is found
  while(low<=high){
    int mid = low + (high-low)/2;

    if(nums[mid]==1){
      res = mid;
      high = mid-1;
    }
    else if(nums[mid]<1){
      low = mid+1;
    }
  }
  return res;
}

int main(){
  vector<int> nums = {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1};
  int i = Search(nums);
  cout<<i;
}