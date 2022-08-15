// Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc.

#include <bits/stdc++.h>

using namespace std;

class SpecialStack{
  stack<int> s;
  stack<int> ss;
  public:
    void push(int a){
      if(ss.empty()){
        ss.push(a);
      }
      s.push(a);
      if(ss.top()>=s.top()){
        ss.push(a);
      }
    }
    int pop(){
      if(s.empty())
        return -1;
      if(s.top()==ss.top()){
        ss.pop();
      }
      int ans = s.top();
      s.pop();
      return ans;
    }

    int getMin(){
      if(ss.empty())
        return -1;
      return ss.top();
    }
};

int main(){
  SpecialStack sp;
  sp.push(18);
  sp.push(19);
  cout<<sp.getMin()<<'\n';
  sp.pop();
  cout<<sp.getMin()<<'\n';

}