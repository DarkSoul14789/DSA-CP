#include <bits/stdc++.h>

using namespace std;
// Find min element
// If min element != required element
// Apply binary search in both the subarrays for required element

int findMinEle(vector<int>& nums){
  int n = nums.size();
  int start = 0;
  int end = nums.size()-1;
  while(start<=end){
    int mid = start + (end-start)/2;
    int next = (mid+1)%n;
    int prev = (mid-1+n)%n;
    if(nums[prev]>nums[mid] && nums[next]>=nums[mid]){
      return mid;
    }
    if(nums[0]<=nums[mid]){
      start = mid+1;
    }
    else if(nums[end]>nums[mid]){
      end = mid-1;
    }
  }
  return -1;
}

int binarySearch(vector<int>& nums, int k){
  int start = 0;
  int end = nums.size()-1;
  while(start<=end){
    int mid = start + (end-start)/2;
    if(nums[mid]==k){
      return mid;
    }
    else if(nums[mid]>=k){
      end = mid-1;
    }
    else{
      start = mid+1;
    }
  }
  return -1;
}

int main(){
  vector<int> rotatedArray = { 11,12,15,18,2,5,6,8 };
  int k = 15;
  int minEle = findMinEle(rotatedArray);
  vector<int> sub1;
  vector<int> sub2;
  copy(rotatedArray.begin(),rotatedArray.begin()+minEle,back_inserter(sub1));
  copy(rotatedArray.begin()+minEle,rotatedArray.end()+minEle,back_inserter(sub2));
  int res1 = binarySearch(sub1,k);
  int res2 = binarySearch(sub2,k);
  if(res2!=-1)
    res2 += minEle;
  cout<<max(res1,res2);
}