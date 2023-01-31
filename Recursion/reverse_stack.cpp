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
  if(s.empty()){
    s.push(n);
    return;
  }
  int temp = s.top();
  s.pop();
  insert(s,n);
  s.push(temp);
  return;
}

void reverse_stack(stack<int>& s){
  if(s.empty()){
    return;
  }
  int temp = s.top();
  s.pop();
  reverse_stack(s);
  // s.push(temp);
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
  s.push(4);
  reverse_stack(s);
  print_stack(s);
}