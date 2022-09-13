#include <bits/stdc++.h>
using namespace std;

int kth_smallest_element(vector<int>& nums, int k){
  // Max heap
  priority_queue<int> heap;
  for(int i=0;i<nums.size();i++){
    heap.push(nums[i]);
    if(heap.size()>k) heap.pop();
  }
  // cout<<heap.top().second<<" ";
  return heap.top();
}

int sum_of_elements(vector<int>& nums, int k1, int k2){
  int n1 = kth_smallest_element(nums,k1);
  int n2 = kth_smallest_element(nums,k2);
  int sum=0;
  for(int i=0; i<nums.size(); i++){
    if(nums[i]>n1 && nums[i]<n2){
      sum+=nums[i];
    }
  }
  return sum;
}

int main(){
  int n;
  cin>>n;
  vector<int> arr;
  int input;
  for(int i=0;i<n;i++){
    cin>>input;
    arr.push_back(input);
  }
  int k1;
  cin>>k1;
  int k2;
  cin>>k2;

  int res = sum_of_elements(arr, k1, k2);
  cout<<res;
}