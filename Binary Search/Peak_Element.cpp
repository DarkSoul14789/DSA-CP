#include <bits/stdc++.h>

using namespace std;

// FIND PEAK ELEMENT IN AN ARRAY:

// A peak element is an element that is greater than its neighbors.

// Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

// You may imagine that nums[-1] = nums[n] = -∞.

// Given unsorted array

int peak_element(vector<int>& nums){
  int start = 0;
  int end = nums.size()-1;
  while(start<=end){
    int mid = start + (end-start)/2;
    cout<<nums[mid]<<"\n";
    if(mid>0 && mid<nums.size()-1){
      if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
        return nums[mid];
      }
      else if(nums[mid]<nums[mid+1]){
        start = mid+1;
      }
      else{
        end = mid-1;
      }
    }
    // else{
    //   cout<<"Here \n";
    //   return nums[mid];
    // }
    else if(mid==0){
      if(nums[mid]>nums[mid+1]){
        return nums[0];
      }
      else{
        return nums[1];
      }
    }
    else if(mid==nums.size()-1){
      if(nums[mid]>nums[mid-1]){
        return nums[nums.size()-1];
      }
      else{
        return nums[nums.size()-2];
      } 
    }
  }
  return -1;  
}

int main(){
  vector<int> nums = {1,7,4,6,8,2,5,9};
  int peakElement = peak_element(nums);
  cout<<peakElement;
}