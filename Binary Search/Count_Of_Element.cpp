#include <bits/stdc++.h>

using namespace std;

pair<int,int> first_last_occurence(vector<int>& nums, int k){
  pair<int,int> res;
  int start = 0;
  int end = nums.size()-1;
  int to_return_first = -1;
  int to_return_second = -1;
  while(end>=start){
    int mid = start + (end-start)/2;
    if(k==nums[mid]){
      to_return_first = mid;
      end = mid-1;
    }
    else if(k>nums[mid])
      start = mid+1;
    else
      end = mid-1;
  }
  res.first = to_return_first;
  start = 0;
  end = nums.size()-1;
  while(end>=start){
    int mid = start + (end-start)/2;
    if(k==nums[mid]){
      to_return_second = mid;
      start = mid+1;
    }
    else if(k>nums[mid])
      start = mid+1;
    else
      end = mid-1;
  }
  res.second = to_return_second;
  return res;
}

int count_element(vector<int>& nums, int k){
  pair<int,int> p = first_last_occurence(nums,k);
  cout<<p.first<<" "<<p.second<<'\n';
  if(p.first==-1)
    return 0;
  return p.second-p.first+1;
}

int main(){
  vector<int> v = {2,4,10,10,10,10,18,20};
  int k = 10;
  int count = count_element(v,k);
  cout<<count;
}