//input 4
//input 1 3 2 4
//expected output -1 2 -1 -1

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cout<<"Enter size of array: ";
  cin>>n;
  int arr[n];
  //taking input array
  for (int i = 0; i < n; i++)
  {
    cin>>arr[n];
  }

  vector<int> v;
  stack<int> s;

  for(int i=n-1;i>=0;i--){
    if(s.empty()){
      v.push_back(-1);
    }
    else if(!s.empty() && s.top()<arr[i]){
      v.push_back(s.top());
    }
    else if(!s.empty() && s.top()>=arr[i]){
      while(!s.empty() && s.top()>=arr[i]){
        s.pop();
      }
      if(s.empty()){
        v.push_back(-1);
      }
      else if(s.top()<arr[i]){
        v.push_back(s.top());
      }
    }
    s.push(arr[i]);
  }

  reverse(v.begin(),v.end());

  for(int i=0;i<n;i++){
    cout<<v[i]<<" ";
  }
  return 0;
}


