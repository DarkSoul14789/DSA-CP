#include <bits/stdc++.h>
using namespace std;

// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

// Examples:
// Input: S = "a1b2"
// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

// Input: S = "3z4"
// Output: ["3z4", "3Z4"]

// Input: S = "12345"
// Output: ["12345"]

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

vector<string> letter_case_permutaion(string ip, string op, vector<string>& v){
  if(ip.empty()){
    v.push_back(op);
    return v;
  }
  if(int(ip[0]) <=57 && int(ip[0]) >= 48){
    op.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    letter_case_permutaion(ip,op,v);
    return v;
  }
  else{
    string op1 = op;
    string op2 = op;
    op1.push_back(tolower(ip[0]));
    op2.push_back(toupper(ip[0]));
    ip.erase(ip.begin()+0);
    letter_case_permutaion(ip,op1,v);
    letter_case_permutaion(ip,op2,v);
    return v;
  }
}

int main(){
  string ip = "a1B2";
  string op = "";
  vector<string> v;
  vector<string> res = letter_case_permutaion(ip,op,v);
  print_vector(res);
}