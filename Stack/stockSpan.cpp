#include <bits/stdc++.h>

using namespace std;

vector<int> stockSpan(vector<int>& nums){
  stack<int> s;
  vector<int> result;

  for(int i=0;i<nums.size();i++){
    if(s.empty())
      result.push_back(1);

    else if(nums[s.top()]>nums[i])
      result.push_back(i-s.top());
    
    else{
      while( !s.empty() && nums[s.top()]<=nums[i] )
        s.pop();

      s.empty() ? result.push_back(i+1) : result.push_back(i-s.top());

    }

    s.push(i);
  }
  return result;
}

void printVector(vector<int>& nums){
  for(int i=0; i<nums.size(); i++){
    cout<<nums[i]<<" ";
  }
}

int main(){
  int n;
  cin>>n;
  vector<int> v;
  int input;
  for(int i=0;i<n;i++){
    cin>>input;
    v.push_back(input);
  }

  vector<int> result = stockSpan(v);
  printVector(result);
}