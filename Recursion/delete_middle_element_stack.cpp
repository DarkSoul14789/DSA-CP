#include <bits/stdc++.h>

using namespace std;

// Middle element is (size of stack)/2 +1
// Delete middle element and print the elements

void print_stack(stack<int>& s){
  if(s.empty()){
    return;
  }
  int temp = s.top();
  s.pop();
  print_stack(s);
  cout<<temp<<" ";
}

void delete_middle_element(stack<int>& s, int size){
  if(size==0){
    s.pop();
    return;
  }
  int temp = s.top();
  s.pop(); 
  delete_middle_element(s,--size);
  s.push(temp);
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
  s.push(4);
  
  int size;
  if(s.size()%2==0){
    size = s.size()/2 - 1;
  }
  else{
    size = ceil(s.size()/2);
  }
  cout<<size<<endl;
  delete_middle_element(s,size);
  print_stack(s);
}