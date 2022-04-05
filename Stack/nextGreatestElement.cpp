
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<int>::iterator p;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> v;
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size()>0 && s.top()>arr[i]){
            v.push_back(s.top());
        }
        else if (s.top()<=arr[i] && s.size()>0){
            while(s.top()<=arr[i] && s.size()>0){
               s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }
            else {
                v.push_back(s.top());
            }
        }
        
        s.push(arr[i]);
        
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    for(p=v.begin();p<v.end();p++){
        cout<<*p<<endl;
    }
    return 0;
}
