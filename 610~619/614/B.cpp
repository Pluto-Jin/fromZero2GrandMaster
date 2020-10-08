#include "bits/stdc++.h"
using namespace std;

int n;
double ans;
int i;

int main()
{
	cin>>n;
	for (i=n;i>0;i--)
		ans+=1.0/i;
	cout<<ans;
}
