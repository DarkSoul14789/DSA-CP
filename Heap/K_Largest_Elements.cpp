#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& nums){
  for(int i=0;i<nums.size();i++){
    cout<<nums.at(i)<<" ";
  }
}

vector<int> K_Largest_Elements(vector<int>& nums, int K){
  priority_queue <int, vector<int>, greater<int> > heap;
  vector<int> returnArray;
  for(int i=0;i<nums.size();i++){
    heap.push(nums[i]);
    if(heap.size()>K){
      heap.pop();
    }
  }
  while(heap.size()){
    returnArray.push_back(heap.top());
    heap.pop();
  }
  return returnArray; 
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

  vector<int> result = K_Largest_Elements(arr,k);
  printVector(result);
}