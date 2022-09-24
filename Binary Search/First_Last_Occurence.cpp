#include <bits/stdc++.h>

using namespace std;
// Better naive approach
pair<int,int> first_last_occurence(vector<int>& nums, int k){
  pair<int,int> re;
  int start = 0;
  int end = nums.size()-1;
  int to_return = -1;
  while(end>=start){
    int mid = start + (end-start)/2;
    if(k==nums[mid]){
        to_return = mid;
        break;
    }
    else if(k>nums[mid])
      start = mid+1;
    else
      end = mid-1;
  }
  if(to_return==-1){
    re.first = to_return;
    re.second = to_return;
    return re;
  }
  else{
    int temp_first = to_return;
    int temp_second = to_return;
    while(nums[temp_first]==k){
      temp_first--;
    }
    re.first = ++temp_first;
    while(nums[temp_second]==k){
      temp_second++;
    }
    re.second = --temp_second;
    return re;
  }
}

// Better approach
int first_occurence(vector<int>& nums, int k){
  int start = 0;
  int end = nums.size()-1;
  int to_return = -1;
  while(end>=start){
    int mid = start + (end-start)/2;
    if(k==nums[mid]){
      to_return = mid;
      end = mid-1;
    }
    else if(k>nums[mid])
      start = mid+1;
    else
      end = mid-1;
  }
  return to_return;
}

int last_occurence(vector<int>& nums, int k){
  int start = 0;
  int end = nums.size()-1;
  int to_return = -1;
  while(end>=start){
    int mid = start + (end-start)/2;
    if(k==nums[mid]){
      to_return = mid;
      start = mid+1;
    }
    else if(k>nums[mid])
      start = mid+1;
    else
      end = mid-1;
  }
  return to_return;
}

int main(){
  vector<int> v1 = {1,3,3,3,4,4,4,4,6};
  int k = 4;
  // pair<int,int> p = first_last_occurence(v1,k);
  // cout<<p.first<<"\n"<<p.second;
  cout<<first_occurence(v1,k)<<"\n";
  cout<<last_occurence(v1,k)<<"\n";
}