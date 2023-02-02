#include <bits/stdc++.h>
using namespace std;

// Given a positive integer N, print all N bit binary numbers having more 1’s than or equal to 0’s for any prefix of the number.

// Input:
// 2
// 2
// 3
// Output:
// 11 10
// 111 110 101 

void solve(int n,int ones, int zeroes, string op){
  if(ones+zeroes==n){
    cout<<stoi(op)<<" ";
    return;
  }
  if(ones==zeroes){
    op.append("1");
    solve(n,ones+1,zeroes,op);
    return;
  }
  else{
    string op1 = op;
    string op2 = op;
    op1.append("1");
    solve(n,ones+1,zeroes,op1);
    op2.append("0");
    solve(n,ones,zeroes+1,op2);
    return;
  }
}

int main(){
  int n = 3;
  string op = "";
  solve(n,0,0,op);
}