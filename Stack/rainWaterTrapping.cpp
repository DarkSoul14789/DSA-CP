#include <bits/stdc++.h>

using namespace std;

int getSum(vector<int> v){
  int sum=0;
  for(int i=0;i<v.size();i++){
    if(v[i]<0)
      continue;
    else{
      sum+=v[i];
    }
  }
  return sum;
}

int getWaterHeight(vector<int>& v, int n){
  int height = min(*max_element(v.begin(),v.begin()+n),*max_element(v.begin()+n,v.end()))-v[n];
  // cout<<height<<'\n';
  return height;
}

int rainWaterTrapping(vector<int>& v){
  vector<int> height;
  for(int i=0;i<v.size();i++){
    height.push_back(getWaterHeight(v,i));
  }
  return getSum(height);
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
  cout<<rainWaterTrapping(arr);

}