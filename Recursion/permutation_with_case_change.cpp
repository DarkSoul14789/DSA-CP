#include <bits/stdc++.h>
using namespace std;

// Print all permutations of a string keeping the sequence but changing cases.

// Examples:

// Input : ab
// Output : AB Ab ab aB .

void print_permutation_with_case_change(string ip, string op){
  if(ip.empty()){
    cout<<op<<endl;
    return;
  }
  string op1 = op;
  string op2 = op;
  op1.push_back(ip[0]);
  op2.push_back(ip[0]-32);
  ip.erase(ip.begin()+0);
  print_permutation_with_case_change(ip,op1);
  print_permutation_with_case_change(ip,op2);
  return;
}

int main(){
  string ip = "abc";
  string op = "";
  print_permutation_with_case_change(ip,op);
}