// Given an array of integers that might contain duplicates, return all possible subsets.

// Note:
// The solution set must not contain duplicate subsets.

#include<bits/stdc++.h>
using namespace std;

void subset(string ip,string op,map<string,int> &m)
{
	if((int)ip.size()==0)
	{
		m[op]++;  
		if(m[op]==1)
		cout<<op<<"\n";
		return;
	}
	string op1=op,op2=op;
	op2.push_back(ip[0]);
	ip.erase(ip.begin()+0);
	subset(ip,op1,m);
	subset(ip,op2,m);
}

int main()
{
	string ip;
	cout<<"\n String - \n";
	cin>>ip;
	string op=" ";
	cout<<"\n Subsets - \n";
	map<string,int> m;
	subset(ip,op,m);
}