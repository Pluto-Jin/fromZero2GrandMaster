#include "bits/stdc++.h"
using namespace std;

const int N=4e5+1;
int r[N];

int main()
{
	int q,x;
	cin>>q>>x;
	int ans=0,curr=0;
	while (q--) {
		int tmp;
		cin>>tmp;
		tmp%=x;
		r[tmp]++;
		if (tmp==curr) {
			ans++;
			for (int i=(curr+1)%x,j=0;j<x;i=(i+1)%x,j++) {
				if (i>curr and r[i]>=r[curr] or i<curr and r[i]>r[curr]) ans++;
				else {
					curr=i;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
}
