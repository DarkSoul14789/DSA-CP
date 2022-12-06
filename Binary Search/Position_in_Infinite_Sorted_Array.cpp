#include <bits/stdc++.h>

using namespace std;

// Set low to 0 and high to 1
// if target greater than nums[high] then set low <- high and high = 2*high
// if target less than high apply binary search in the range low to high
int binarySearchInfiniteArray(vector<int>& nums, int k){
  int low = 0;
  int high = 1;
  while(k>nums[high]){
    low = high;
    high = 2*high;
  }
  if(k==nums[high]){
    return high;
  }
  // else if(k>nums[high]){
  //   low = high;
  //   high = 2*high;
  // }
  else{
    // binary search
    while(low<=high){
      int mid = low + (high-low)/2;
      if(nums[mid]==k){
        return mid;
      }
      else if(nums[mid]<k){
        low = mid+1;
      }
      else{
        high = mid-1;
      }
    }
    return -1;
  }
} 

int main(){
  vector<int> nums = {1,2,3,4,5,6,8,9,14,15,17};
  int k = 9;
  int i = binarySearchInfiniteArray(nums, k);
  cout<<i;
}