#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int>& nums, int k){
  int start = 0;
  int end = nums.size()-1;
  while(end>=start){
    int mid = start + (end-start)/2;
    if(k==nums[mid])
      return mid;
    else if(k>nums[mid])
      end = mid-1;
    else
      start = mid+1;
  }
  return -1;
}

int main(){
  vector<int> v = {9,8,7,4,3,1};
  int k = 9;
  cout<<binary_search(v,k);
}