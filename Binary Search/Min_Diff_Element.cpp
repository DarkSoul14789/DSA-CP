#include <bits/stdc++.h>

using namespace std;

// Q) Given a sorted array, find the element in the array which has minimum difference with the given number.


// Find the floor and the ceil of the element then return the key with min difference

int ceilBinarySearch(vector<int>& nums, int k){
  int start = 0;
  int end = nums.size()-1;
  int ans = -1;
  while(start<=end){
    int mid = start + (end-start)/2;
    if(nums[mid]==k){
      return nums[mid];
    }
    else if(nums[mid]>k){
      end = mid-1;
      ans = nums[mid];
    }
    else{
      start = mid+1;
    }
  }
  return ans;
}

int floorBinarySearch(vector<int>& nums, int k){
  int start = 0;
  int end = nums.size()-1;
  int ans = -1;
  while(start<=end){
    int mid = start + (end-start)/2;
    if(nums[mid]==k){
      return nums[mid];
    }
    else if(nums[mid]>k){
      end = mid-1;
    }
    else{
      ans = nums[mid];
      start = mid+1;
    }
  }
  return ans;
}

int minDifference(vector<int>& nums, int k){
  int cl = ceilBinarySearch(nums,k);
  int flr = floorBinarySearch(nums,k);
  
  if(abs(k-cl)>=abs(k-flr)){
    return flr;
  }
  return cl;
}

int main(){
  vector<int> nums = {1,3,8,10,15,18,20};
  int k = 7;

  int diff = minDifference(nums, k);
  cout<<diff;  
}