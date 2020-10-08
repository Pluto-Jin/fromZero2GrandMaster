#include "bits/stdc++.h"
using namespace std;

int n,m,i;
long long ans=1,tmp=1;
int mod=pow(10,9)+7;

int power(int a,int b,int mod)
{
	long long ans=1;
	long long tmp=a;
	while (b>0)
	{
		if (b%2)
		{
			ans*=tmp;
			ans%=mod;
		}
		tmp*=tmp;
		tmp%=mod;
		b/=2;
	}
	return ans;
}
	

int main()
{
	cin>>n>>m;
	for (i=1;i<2*m+1;i++)
	{
		ans*=n-1+i;
		ans%=mod;
		tmp*=i;
		tmp%=mod;
	}
	//cout<<ans<<tmp;
	ans*=power(tmp,mod-2,mod);
	ans%=mod;
	cout<<ans<<endl;
}
