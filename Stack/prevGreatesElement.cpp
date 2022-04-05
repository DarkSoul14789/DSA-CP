
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    stack<int> s;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if(s.empty()){
            v.push_back(-1);
        }
        else if(!s.empty() && s.top()>arr[i]){
            v.push_back(s.top());
        }
        else if(!s.empty() && s.top()<=arr[i]){
            while(!s.empty() && s.top()<=arr[i]){
                s.pop();
            }
            if(s.empty()){
                v.push_back(-1);
            }
            else if(!s.empty() && s.top()>arr[i]){
                v.push_back(s.top());
            }
        }
        
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        
        cout<<v[i]<<" ";
    }
    return 0;
}
