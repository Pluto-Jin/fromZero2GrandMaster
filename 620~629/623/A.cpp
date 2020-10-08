#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int a,b,x,y;
		cin>>a>>b>>x>>y;
		int tmp=max(0,a*max(y,b-y-1));
		tmp=max(tmp,b*max(x,a-x-1));
		cout<<tmp<<endl;
	}
}
