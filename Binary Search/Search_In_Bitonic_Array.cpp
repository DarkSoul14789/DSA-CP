#include <bits/stdc++.h>

using namespace std;

// FIND AN ELEMENT IN BITONIC ARRAY:

// Given a bitonic sequence of n distinct elements, write a program to find a given element x in the bitonic sequence in O(log n) time. A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.

// Examples:

// Input :  arr[] = {-3, 9, 18, 20, 17, 5, 1};
//          key = 20
// Output : Found at index 3

int binary_search(vector<int>& nums, int k, int start, int end){
  while(start<=end){
    int mid = start + (end-start)/2;
    if(nums[mid]==k){
      return mid;
    }
    else if(nums[mid]<k){
      end = mid-1;
    }
    else{
      start = mid+1;
    }
  }
  return -1;
}

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
        return mid;
      }
    }
    else if(mid==0 && nums[mid]<nums[mid+1]){
      start = mid+1;
    }
    else if(mid==nums.size()-1 && nums[mid]<nums[mid-1]){
      end = mid-1;
    }
    else{
      return mid;
    }
  }
  return -1;
}

int find_element_in_bitonic_array(vector<int>& nums, int k){
  // Find peak element position
  int peak = max_element_bitonic_array(nums);
  cout<<"peak "<<peak<<"\n";
  // Divide the two arrays into monotonically increasing and monotonically decreasing
  // Perform binary search on both
  int k1 = binary_search(nums,k,0,peak-1);
  if(k1==-1){
    int k2 = binary_search(nums,k,peak,nums.size()-1);
    cout<<"k2 "<<k2<<"\n";
    return k2;
  }
  return k1;
}

int main(){
  vector<int> nums = {-3, 9, 18, 20, 17, 5, 1};
  int number = 9;
  int index = find_element_in_bitonic_array(nums,number);
  cout<<index;
}