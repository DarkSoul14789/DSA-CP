#include <bits/stdc++.h>

using namespace std;

// Print all subsets of a String

void print_subsets(string ip, string op){
  if(ip.empty()){
    cout<<op<<" ";
    return;
  }
  string op1 = op;
  string op2 = op;
  op2.push_back(ip[0]);
  ip.erase(ip.begin()+0);
  print_subsets(ip,op1);
  print_subsets(ip,op2);
  return;
}

int main(){
  string ip;
  cin>>ip;
  string op = "";
  print_subsets(ip,op);
}