#include <bits/stdc++.h>

using namespace std;

void print_matrix(vector<vector<int>>& matrix){
  for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[i].size();j++){
      cout<<matrix[i][j]<<" ";
    }
    cout<<"\n";
  }
}

void printVector(vector<int>& nums){
  for(int i=0; i<nums.size(); i++){
    cout<<nums[i]<<" ";
  }
  cout<<'\n';
}

// Find next smallest element
vector<int> nse(vector<int>& nums){
  stack<int> s;
  vector<int> result;

  for(int i=nums.size()-1;i>=0;i--){
    if(s.empty())
      result.push_back(nums.size());
    else if(nums[s.top()]<nums[i]){
      result.push_back(s.top());
    }
    else{
      while(!s.empty() && nums[s.top()]>=nums[i]){
        s.pop();
      }
      s.empty() ? result.push_back(nums.size()) : result.push_back(s.top());
    }
    s.push(i);
  }
  reverse(result.begin(),result.end());
  return result;
}

// Find prev smallest element
vector<int> pse(vector<int>& nums){
  stack<int> s;
  vector<int> result;

  for(int i=0;i<nums.size();i++){
    if(s.empty())
      result.push_back(-1);
      
    else if(nums[s.top()]<nums[i]){
      result.push_back(s.top());
    }
    else{
      while(!s.empty() && nums[s.top()]>=nums[i]){
        s.pop();
      }
      if(s.empty()){
        result.push_back(-1);
      }
      else{
        result.push_back(s.top());
      }
    }

    s.push(i);
  }

  return result;
}

// Find width, area and return max area
int mah(vector<int>& arr){
  vector<int> right = nse(arr);
  vector<int> left = pse(arr);
  vector<int> width;

  for(int i=0;i<arr.size();i++){
    width.push_back(right[i]-left[i]-1);
  }

  vector<int> area;
  for(int i=0;i<arr.size();i++){
    area.push_back(width[i]*arr[i]);
  }
  return *max_element(area.begin(),area.end());
}


int marbm(vector<vector<int>>& mat){
  vector<int> v;
  int maxArea = 0;
  for(int i=0;i<mat.size();i++){
    for(int j=0;j<mat[i].size();j++){
      if(i==0){
        v.push_back(mat[i][j]);
      }
      else if(mat[i][j]==0){
        v[j] = 0;
      }
      else{
        v[j] = v[j] + mat[i][j];
      }
    }
    // printVector(v);
    if(mah(v)>maxArea)
      maxArea = mah(v);
  }
  return maxArea;
}



int main(){
  vector<vector<int>> matrix;
  // {
  //   {0,1,1,0},
  //   {1,1,1,1},
  //   {1,1,1,1},
  //   {1,1,0,0}
  // };
  int rows;
  cout<<"Enter no. of rows: ";
  cin>>rows;
  int columns;
  cout<<"Enter no. of columns: ";
  cin>>columns;
  for(int i=0;i<rows;i++){
    vector<int> row;
    int input_row;
    for(int j=0;j<columns;j++){
      cin>>input_row;
      row.push_back(input_row);
    }
    matrix.push_back(row);
  }

  cout<<marbm(matrix);
  // print_matrix(matrix);
}