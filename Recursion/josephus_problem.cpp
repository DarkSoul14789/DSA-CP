#include <bits/stdc++.h>
using namespace std;

// There are n people standing in a circle (numbered clockwise 1 to n) waiting to be executed. The counting begins at point 1 in the circle and proceeds around the circle in a fixed direction (clockwise). In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom.
// Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.
// Consider if n = 5 and k = 2, then the safe position is 3.
// Firstly, the person at position 2 is killed, then person at position 4 is killed, then person at position 1 is killed. Finally, the person at position 5 is killed. So the person at position 3 survives. 


void fill_array(vector<int>& v,int n){
  for(int i=0;i<n;i++){
    v.push_back(i+1);
  }
}

void josephus(int k,int& pos, vector<int>& v){
  if(v.size()==0){
    return;
  }
  cout<<"pos "<<v[pos]<<" ";
  // v.erase(v.begin()+(pos+k-1)%v.size());
  // pos = (pos+k-1)%v.size();
  pos = (pos+k-1)%v.size();
  v.erase(v.begin()+pos);
  josephus(k,pos,v);
  return;
}

int main(){
  int n = 7;
  int k = 3;
  int pos = 0;
  // int res = -1;
  vector<int> v;
  fill_array(v,n);
  josephus(k,pos,v);
  cout<<v[pos];
}