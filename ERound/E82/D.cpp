#include "bits/stdc++.h"
using namespace std;

#define ll long long
map<int,int> dic;
int ex[31];

int main()
{
	int x=1;
	dic[x]=0;
	ex[0]=x;
	for (int i=1;i<31;i++) {x*=2;ex[i]=x;dic[x]=i;}
	int t;
	cin>>t;
	while (t--) {
		ll n,m;
		cin>>n>>m;
		vector<int> ar;
		ar.resize(61);

		bitset<60> s(n);
		ll sum=0;
		for (int i=0;i<m;i++) {
			int tmp;
			cin>>tmp;
			ar[dic[tmp]]++;
			sum+=tmp;
		}	

		sum-=n;
		if (!sum) cout<<0<<endl;
		else if (sum<0) cout<<-1<<endl;
		else {
			int ans=0;
			for (int i=0;i<60;i++) {
				if (ar[i]) {
					if (s[i]) ar[i]--;
					ar[i+1]+=ar[i]/2;
				}
				else if (s[i]) {
					if (i==59) sum=0;
					for (int j=i+1;j<31;j++) {
						if (ar[j]) {
							ar[j]--;
							ans+=j-i;
							for (int k=i+1;k<j;k++) ar[k]++;
							break;
						}
						if (j==30) sum=0;
					}
					if (!sum) break;
				}
			}
			if (!sum) cout<<-1<<endl;
			else cout<<ans<<endl;
		}
	}
}
