#include <bits/stdc++.h>

using namespace std;

// The tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs N. Initially, these discs are in the rod 1. You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.

void solve(int n, int source,int destination, int helper, int& count){
  count++;
  if(n==1){
    cout<<"Moving plate "<<n<<" from "<<source<<" to "<<destination<<endl;
    return;
  }
  solve(n-1,source,helper,destination,count);
  cout<<"Moving plate "<<n<<" from "<<source<<" to "<<destination<<endl;
  solve(n-1,helper,destination,source,count);
  return;
}

int main(){
  int n = 4;
  int count = 0;
  solve(n,1,3,2,count);
  cout<<"No of steps: "<<count;
}