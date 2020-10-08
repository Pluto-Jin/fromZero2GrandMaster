#include "bits/stdc++.h"
using namespace std;

int a[127],p[127];
int main() 
{
	int t;
	cin>>t;
	while (t--) {
		fill(p,p+127,0);
		int n,m;
		cin>>n>>m;
		for (int i=0;i<n;i++) cin>>a[i+1];
		for (int i=0;i<m;i++) {
			int tmp;
			cin>>tmp;
			p[tmp]=1;
		}
		int ans=1;
		for (int i=1;i<n;i++) {
			for (int j=1;j<=n-i;j++) {
				if (a[j]>a[j+1]) {swap(a[j],a[j+1]);if (!p[j]) {ans=0;break;}}
			}
			if (!ans) break;
		}
		cout<<(ans?"YES":"NO")<<endl;
	}
}
