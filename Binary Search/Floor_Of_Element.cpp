#include <bits/stdc++.h>

using namespace std;

int floor_of_element(vector<int>& nums, int k){
  int start = 0;
  int end = nums.size()-1;
  int res = -1;
  while(start<=end){
    int mid = start + (end-start)/2;
    if(nums[mid]==k){
      return nums[mid];
    }
    else if(nums[mid]>k){
      end = mid-1;
    }
    else {
      res= nums[mid];
      start = mid+1;
    }
  }
  return res;
}

int main(){
  vector<int> v = {1,2,3,4,8,10,10,12,19};
  int k = 5;
  int floor = floor_of_element(v,k);
  cout<<floor;
}