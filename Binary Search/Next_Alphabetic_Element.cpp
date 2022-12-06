#include <bits/stdc++.h>

using namespace std;

int binarySearchChar(vector<char>& v, char k){
  int start = 0;
  int end = v.size()-1;
  int res = -1;
  while(start<=end){
    int mid = start + (end-start)/2;
    if(v[mid]==k){
      start = mid+1;
    }
    else if(v[mid]<k){
      start = mid+1;
    }
    else{
      res = mid;
      end = mid-1;
    }
  }
  return res;
}

int main(){
  vector<char> v = {'a','c','f','h'};
  char k = 'd';
  int i = binarySearchChar(v,k);
  cout<<v[i];
}