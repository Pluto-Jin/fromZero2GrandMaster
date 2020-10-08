#include "bits/stdc++.h"
using namespace std;

int t,n;
vector<int> input;

int main()
{
	cin>>t;
	while (t--)
	{
		cin>>n;
		input.push_back(n);	
	}
	for (auto i:input)
	{
		if (i%2)
		{
			cout<<7;
			i-=3;
			
		}
		while (i)
		{
			cout<<1;
			i-=2;
		}
		cout<<endl;
	}
}
