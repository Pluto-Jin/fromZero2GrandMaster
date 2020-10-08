#include "bits/stdc++.h"
using namespace std;

#define pii pair<int,int>
#define fi first
#define se second
#define ll long long 

int comp(pii a,pii b)
{
	return a.se<b.se;
}
int main()
{
	int m;
	cin>>m;
	while (m--) {
		int n,T,t[2],cnt[2]={0};
		cin>>n>>T>>t[0]>>t[1];
		vector<pii> prob;
		prob.resize(n);
		for (auto &i:prob) {
			cin>>i.fi;
			cnt[i.fi]++;
		}
		for (auto &i:prob) cin>>i.se;

		sort(prob.begin(),prob.end(),comp);

		int ans=0,flag=0;
		ll sum=0;

		for (int i=0;i<n+1;i++) {
			ll tm;
			if (i==n or prob[i].se-1>T) {
				tm=T;
				flag=1;
			}
			else tm=prob[i].se-1;
			if (i) {
				sum+=t[prob[i-1].fi];
				cnt[prob[i-1].fi]--;
			}
			if (sum>tm) continue;
			int tmp=i;

			int x=min(cnt[0],int(tm-sum)/t[0]);
			tm-=x*t[0];
			tmp+=x;
			int y=min(cnt[1],int(tm-sum)/t[1]);
			tmp+=y;

			ans=max(ans,tmp);
			if (ans==n) break;
			if (flag) break;
		}
		cout<<ans<<endl;
	}
}
