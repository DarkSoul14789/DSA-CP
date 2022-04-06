//input 1 3 2 4
//expected output -1 1 1 2
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cout<<"Enter array size:\n";
  cin>>n;
  int arr[n];
  vector<int> v;
  stack<int> s;
  //filling the input array
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  //start of the logic of the program
  for(int i=0;i<n;i++){
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
  //end of main logic of program

  //printing the output
  for (int i = 0; i < n; i++)
  {
    cout<<v[i]<<" ";
  }
  

  return 0;
}