#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int>& nums){
  for(int i=0;i<nums.size();i++){
    cout<<nums.at(i)<<" ";
  }
}

vector<int> Frequency_Sort(vector<int>& nums){
  // Create unordered map
  unordered_map<int,int> mp;
  for(auto i : nums){
    mp[i]++;
  }
  // Create max heap
  priority_queue< pair<int,int> > heap;
  for(auto i=mp.begin(); i!=mp.end(); i++){
    heap.push({i->second,i->first});
  }
  
  vector<int> result;
  while(!heap.empty()){
    for(int i=0;i<heap.top().first;i++){
      result.push_back(heap.top().second);
    }
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
  vector<int> result = Frequency_Sort(arr);
  printVector(result);
}