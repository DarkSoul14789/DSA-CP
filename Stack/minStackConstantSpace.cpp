// Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must have O(1) space. To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc.

#include <bits/stdc++.h>

using namespace std;

class SpecialStack{
  int min_element;
  stack<int> s;
  public:
    void push(int a){
      if(s.empty()){
        s.push(a);
        min_element = a;
      }
      else{
        if(a<min_element){
          s.push(2*a-min_element);
          min_element = a;
        }
        else{
          s.push(a);
        }
      }
    }
    int pop(){
      if(s.empty())
        return -1;
      else{
        if(s.top()>=min_element){
          int temp = s.top();
          s.pop();
          return temp;
        }
        else{
          int temp = s.top();
          int min_element_temp = min_element;
          s.pop();
          min_element = 2*min_element - temp;
          return min_element_temp;
        }
      }
    }
    int getMin(){
      if(s.empty())
        return -1;
      else
        return min_element;
    }
    int top(){
      if(s.empty()){
        return -1;
      }
      else{
        if(s.top()>min_element){
          return s.top();
        }
        else{
          return min_element;
        }
      }
    }
};

int main(){
  SpecialStack s;
  s.push(5);
  s.push(3);
  cout<<s.getMin()<<"\n";
  cout<<s.pop()<<"\n";
  cout<<s.top()<<"\n";
  cout<<s.getMin()<<"\n";
}