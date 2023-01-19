#include <bits/stdc++.h>

using namespace std;


// Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it. Otherwise, print “Not Found”. In the given matrix, every row and column is sorted in increasing order. The designed algorithm should have linear time complexity.
// Example :

// Input : mat[4][4] = { {10, 20, 30, 40},
//                       {15, 25, 35, 45},
//                       {27, 29, 37, 48},
//                       {32, 33, 39, 50}};
//               x = 29
// Output : Found at (2, 1)

vector<int> search_in_2d_array(vector<vector<int>>& nums, int key){
  vector<int> res = {};
  int start = 0;
  int end = nums[0].size()-1;
  while(start<=nums[0].size()-1 && end>=0){
    int mid = nums[start][end];
    if(key == mid){
      res.push_back(start);
      res.push_back(end);
      return res;
    }
    else if(key<mid){
      end--;
    }
    else{
      start++;
    }
  }
  res.push_back(-1);
  res.push_back(-1);
  return res;
}

int main(){
  vector<vector<int>> nums = {{10, 20, 30, 40},
                              {15, 25, 35, 45},
                              {27, 29, 37, 48},
                              {32, 33, 39, 50}};
  int key = 29;
  vector<int> res = search_in_2d_array(nums, key);
  cout<<res[0]<<", "<<res[1]<<"\n";
}