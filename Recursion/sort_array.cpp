#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int>& v){
  // if(i==v.size()){
  //   return;
  // }
  // cout<<v[i]<<" ";
  // print_vector(v,i+1);
  if(v.size()==0){
    return;
  }
  int val = v[v.size()-1];
  v.pop_back();
  print_vector(v);
  cout<<val<<" ";
}

void swap(int& a, int& b){
  int temp = a;
  a = b;
  b = temp;
}

void insert(vector<int>& v, int n){
  if(v.size()==0 || v[v.size()-1]<=n){
    v.push_back(n);
    return;
  }
  // Store last element
  int temp = v[v.size()-1];
  // Remove last element
  v.pop_back();
  insert(v,n);
  // push back removed element as it is greater than n
  v.push_back(temp);
  return;
}

void sort_using_recursion(vector<int>& v){
  // if(i==v.size()){
  //   return;
  // }
  // if(v[i]<v[i+1]){
  //   swap(v[i],v[i+1]);
  // }
  // sort_using_recursion(v,i+1);
  if(v.size()==1){
    return;
  }
  // Store last element
  int temp = v[v.size()-1];
  // Removes last element
  v.pop_back();
  sort_using_recursion(v);
  insert(v,temp);
}

int main(){
  vector<int> v = {1,7,2,4,3,5,0,4};
  // int k = 5;
  // int l = 7;
  // swap(k,l);
  // cout<<k<<" "<<l;
  sort_using_recursion(v);
  print_vector(v);
}