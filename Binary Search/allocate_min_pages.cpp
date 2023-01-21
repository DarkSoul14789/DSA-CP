#include <bits/stdc++.h>

using namespace std;


// Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

// Example :

// Input : pages[] = {12, 34, 67, 90}
//         m = 2
// Output : 113
// Explanation:
// There are 2 number of students. Books can be distributed 
// in following fashion : 
//   1) [12] and [34, 67, 90]
//       Max number of pages is allocated to student 
//       2 with 34 + 67 + 90 = 191 pages
//   2) [12, 34] and [67, 90]
//       Max number of pages is allocated to student
//       2 with 67 + 90 = 157 pages 
//   3) [12, 34, 67] and [90]
//       Max number of pages is allocated to student 
//       1 with 12 + 34 + 67 = 113 pages

// Of the 3 cases, Option 3 has the minimum pages = 113.

bool isValid(vector<int>& nums, int n, int k, int max_pages){
  int student = 1;
  int sum = 0;
  for(int i=0;i<n;i++){
    sum+=nums[i];
    if(sum>max_pages){
      student++;
      sum = nums[i];
    }
    if(student>k){
      return false;
    }
  }
  return true;
}

int allocate_min_pages(vector<int>& nums, int m){
  int start = *max_element(nums.begin(),nums.end());
  int end = accumulate(nums.begin(),nums.end(),0);
  int res = -1;
  if(m>nums.size()){
    return res;
  }
  while(start<=end){
    int mid = start + (end-start)/2;
    if(isValid(nums,nums.size(),m,mid)){
      res = mid;
      end = mid-1;
    }
    else{
      start = mid+1;
    }
  }
  if(res==-1){
    return res;
  }
  return res;
}

int main(){
  vector<int> nums = {12, 34, 67, 90};
  int m = 2;
  int res = allocate_min_pages(nums,m);
  cout<<res;
}