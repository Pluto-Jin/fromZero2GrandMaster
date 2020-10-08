#include "bits/stdc++.h"
using namespace std;

#define N 1000000
long long a[N],p[N],q[N],s,c,t;

int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>i;	

	for (int i=0;i<n;i++) {
		s=a[i];
		c=1;
		cout<<"i,c,s="<<i<<","<<c<<","<<s<<endl;
		cout<<"t,pt,qt="<<t<<","<<p[t]<<","<<q[t]<<endl;
		while (t and p[t]*c>=s*q[t]) {
			s+=p[t];
			c+=q[t];
			t--;
		}
		cout<<"c,s,t="<<c<<","<<s<<","<<t<<endl;
		t++;
		p[t]=s;
		q[t]=c;
	}
}
