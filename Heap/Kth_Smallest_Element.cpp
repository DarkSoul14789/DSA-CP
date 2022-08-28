#include <bits/stdc++.h>
using namespace std;

int kth_smallest_element(vector<int>& nums, int k){
  // Creating a max heap
  priority_queue <int> heap;

  for(int i=0;i<nums.size();i++){
    heap.push(nums[i]);
    if(heap.size()>k){
      heap.pop();
    }
  }
  return heap.top();
}

int main(){
  int n;
  // cout<<"Enter number of elements: ";
  cin>>n;
  vector<int> arr;
  int input;
  // cout<<"Enter the elements: "<<"\n";
  for(int i=0;i<n;i++){
    cin>>input;
    arr.push_back(input);
  }
  // cout<<"Enter K value"<<"\n";
  int k;
  cin>>k;
  int kse = kth_smallest_element(arr,k);
  cout<<kse;
}