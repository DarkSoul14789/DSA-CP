#include <bits/stdc++.h>

using namespace std;

// FIND MAXIMUM ELEMENT IN AN BITONIC ARRAY:

// Problem statement:
// Given a bitonic array find the maximum value of the array. An array is said to be bitonic if it has an increasing sequence of integers followed immediately by a decreasing sequence of integers.

// Example:

// Input:
// 1 4 8 3 2

// Output:
// 8

int max_element_bitonic_array(vector<int>& nums){
  int start = 0;
  int end = nums.size()-1;
  while(start<=end){
    int mid = start+(end-start)/2;
    if(mid!=0 || mid!=nums.size()-1){
      if(nums[mid]<nums[mid-1]){
        end = mid-1;
      }
      else if(nums[mid]<nums[mid+1]){
        start = mid+1;
      }
      else{
        return nums[mid];
      }
    }
    else if(mid==0 && nums[mid]<nums[mid+1]){
      start = mid+1;
    }
    else if(mid==nums.size()-1 && nums[mid]<nums[mid-1]){
      end = mid-1;
    }
    else{
      return nums[mid];
    }
  }
  return -1;
}

int main(){
  vector<int> nums = {1,4,8,10,15,3,2};
  int k = max_element_bitonic_array(nums);
  cout<<k;
}