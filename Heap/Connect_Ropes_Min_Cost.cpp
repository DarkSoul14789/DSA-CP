#include <bits/stdc++.h>
using namespace std;

int connect_ropes_min_cost(vector<int>& nums){
  int totalValue=0,temp1=0,temp2=0;
  priority_queue<int, vector<int>, greater<int>> heap;
  for(auto i:nums){
    heap.push(i);
  }
  while(heap.size()>1){
    temp1 = heap.top();
    heap.pop();
    temp2 = heap.top();
    heap.pop();
    heap.push(temp1+temp2);
    totalValue+=temp1+temp2;
  }
  return totalValue;
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
  int k = connect_ropes_min_cost(arr);
  cout<<k;
}