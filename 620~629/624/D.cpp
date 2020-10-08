#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int a,b,c,aa,bb,cc;
		cin>>a>>b>>c;
		int ans=1e5;
		for (int i=2*b;i>=1;i--) {
			for (int j=i;j<=2*c;j+=i) {
				int x=max(c/j,1);
				int k;
				if (abs(c-x*j)>abs(c-(x+1)*j)) k=(x+1)*j;
				else k=x*j;
				int tmp=abs(a-i)+abs(b-j)+abs(c-k);
				if (tmp<ans) {ans=tmp;aa=i;bb=j;cc=k;if (!ans) break;}
			}
		}
		cout<<ans<<endl;
		cout<<aa<<" "<<bb<<" "<<cc<<endl;
	}
}
