#include <bits/stdc++.h>

using namespace std;

// We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.
// For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
// Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.

int kth_symbol_grammar(int n, int k){
  if(n==1 && k==1){
    return 0;
  }
  int mid = pow(2,n-1)/2;
  int res;
  if(k<=mid){
    res = kth_symbol_grammar(n-1,k);
  }
  else{
    res = abs(kth_symbol_grammar(n-1,k-mid)-1);
  }
  return res;
}

int main(){
  int n = 4;
  int k = 5;
  int res = kth_symbol_grammar(n,k);
  cout<<res;
}