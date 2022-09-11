#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int>& nums){
  for(int i=0;i<nums.size();i++){
    cout<<nums.at(i)<<" ";
  }
}

vector<int> Top_K_Freq_Numbers(vector<int>& nums, int k){
  // Map to store frequency
  unordered_map<int,int> mp;
  for(int i=0;i<nums.size();i++){
    mp[nums[i]]++;
  }
  // Min heap
  priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > heap;
  for(auto i=mp.begin();i!=mp.end();i++){
    heap.push({i->second,i->first});
    if(heap.size()>k)
      heap.pop();
  }
  vector<int> result;
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

  vector<int> result = Top_K_Freq_Numbers(arr,k);
  printVector(result);
}