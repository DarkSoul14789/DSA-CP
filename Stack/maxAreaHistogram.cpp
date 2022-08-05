#include <bits/stdc++.h>

using namespace std;

// Find next smallest element
vector<int> nse(vector<int>& nums){
  stack<int> s;
  vector<int> result;

  for(int i=nums.size()-1;i>=0;i--){
    if(s.empty())
      result.push_back(nums.size());
    else if(nums[s.top()]<nums[i]){
      result.push_back(s.top());
    }
    else{
      while(!s.empty() && nums[s.top()]>=nums[i]){
        s.pop();
      }
      s.empty() ? result.push_back(nums.size()) : result.push_back(s.top());
    }
    s.push(i);
  }
  reverse(result.begin(),result.end());
  return result;
}

// Find prev smallest element
vector<int> pse(vector<int>& nums){
  stack<int> s;
  vector<int> result;

  for(int i=0;i<nums.size();i++){
    if(s.empty())
      result.push_back(-1);
      
    else if(nums[s.top()]<nums[i]){
      result.push_back(s.top());
    }
    else{
      while(!s.empty() && nums[s.top()]>=nums[i]){
        s.pop();
      }
      if(s.empty()){
        result.push_back(-1);
      }
      else{
        result.push_back(s.top());
      }
    }

    s.push(i);
  }

  return result;
}

// Find width, area and return max area
int mah(vector<int>& arr){
  vector<int> right = nse(arr);
  vector<int> left = pse(arr);
  vector<int> width;

  for(int i=0;i<arr.size();i++){
    width.push_back(right[i]-left[i]-1);
  }

  vector<int> area;
  for(int i=0;i<arr.size();i++){
    area.push_back(width[i]*arr[i]);
  }
  return *max_element(area.begin(),area.end());
}

void printVector(vector<int>& nums){
  for(int i=0; i<nums.size(); i++){
    cout<<nums[i]<<" ";
  }
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

  cout<<mah(arr);
  // vector<int> test = nse(arr);
  // printVector(test);
}