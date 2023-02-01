#include <bits/stdc++.h>
using namespace std;

// Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. Output should be printed in sorted increasing order of strings.

// Input:  str[] = "ABC"
// Output: (A B C)(A BC)(AB C)(ABC).

void print_permutation_with_spaces(string ip, string op){
  if(ip.empty()){
    cout<<op<<endl;
    return;
  }
  string op1 = op;
  string op2 = op;
  op1.append("_");
  op1.push_back(ip[0]);
  op2.push_back(ip[0]);
  ip.erase(ip.begin()+0);
  print_permutation_with_spaces(ip,op1);
  print_permutation_with_spaces(ip,op2);
  return;
}

int main(){
  string ip = "abcd";
  string op = "";
  op.push_back(ip[0]);
  ip.erase(ip.begin()+0);
  print_permutation_with_spaces(ip,op);
}