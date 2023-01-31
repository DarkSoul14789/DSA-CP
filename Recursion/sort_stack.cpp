#include <bits/stdc++.h>

using namespace std;

void print_stack(stack<int>& s){
  if(s.empty()){
    return;
  }
  int temp = s.top();
  s.pop();
  print_stack(s);
  cout<<temp<<" ";
}

void insert(stack<int>& s,int n){
  if(s.empty() || s.top()<=n){
    s.push(n);
    return;
  }
  int temp = s.top();
  s.pop();
  insert(s,n);
  s.push(temp);
  return;
}

void sort_using_recursion(stack<int>& s){
  if(s.size()==1){
    return;
  }
  int temp = s.top();
  s.pop();
  sort_using_recursion(s);
  insert(s,temp);
  return;
}

int main(){
  stack<int> s;
  s.push(3);
  s.push(1);
  s.push(5);
  s.push(7);
  s.push(2);
  sort_using_recursion(s);
  print_stack(s);
}