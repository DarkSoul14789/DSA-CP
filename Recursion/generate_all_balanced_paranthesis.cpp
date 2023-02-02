#include <bits/stdc++.h>
using namespace std;

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

// For example, given n = 3, a solution set is:

// "((()))", "(()())", "(())()", "()(())", "()()()" 

void print_vector(vector<string>& v){
  if(v.empty()){
    return;
  }
  string temp = v.back();
  v.pop_back();
  print_vector(v);
  cout<<temp<<" ";
  return;
}

vector<string> generate_balanced_paranthesis(int o,int c, string op, vector<string>& v){
  if(o==0 && c==0){
    v.push_back(op);
    return v;
  }
  if(o==c){
    op.append("(");
    generate_balanced_paranthesis(o-1,c,op,v);
    return v;
  }
  else if(o==0){
    op.append(")");
    generate_balanced_paranthesis(o,c-1,op,v);
    return v;
  }
  else{
    string op1 = op;
    string op2 = op;
    op1.append("(");
    generate_balanced_paranthesis(o-1,c,op1,v);
    op2.append(")");
    generate_balanced_paranthesis(o,c-1,op2,v);
    return v;
  }
}

int main(){
  int n = 3;
  vector<string> v;
  int o = n;
  int c = n;
  string op = "";
  vector<string> res = generate_balanced_paranthesis(o,c,op, v);
  print_vector(res);
}