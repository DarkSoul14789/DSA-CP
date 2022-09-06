#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int>& nums){
  for(int i=0;i<nums.size();i++){
    cout<<nums.at(i)<<" ";
  }
}

vector<int> K_Closest_Numbers(vector<int>& nums, int k, int x){
  vector<int> result;
  priority_queue<pair<int,int>> heap;
  for(int i=0;i<nums.size();i++){
    heap.push({abs(nums[i] - x),nums[i]});
    if(heap.size()>k){
      heap.pop();
    }
  }

  while(!heap.empty()){
    result.push_back(heap.top().second);
    heap.pop();
  }
  return result;
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
  int k;
  cin>>k;
  int x;
  cin>>x;
  vector<int> result = K_Closest_Numbers(arr,k,x);
  printVector(result);
}