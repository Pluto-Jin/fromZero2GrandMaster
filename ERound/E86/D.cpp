#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,k; cin>>n>>k;
	vi num(k+1),ma(k+1);
	for (int i=0;i<n;i++) {
		int tmp; cin>>tmp;
		num[tmp]++;
	}
	for (int i=1;i<=k;i++) cin>>ma[i]; 

	int len=0;
	vvi ans(200000);
	for (int i=k;i>=1;i--) {
		if (!num[i]) continue;
		int lo=0,hi=len,p;
		while (lo<hi) {
			int mid=(hi+lo)/2;
			if (ans[mid].size()<ma[i]) hi=mid;
			else lo=mid+1;
		}
		p=hi;
		while (1) {
			while (num[i] and ans[p].size()<ma[i]) ans[p].pb(i),num[i]--;
			p++;
			if (num[i]) len=max(len,p);
			else break;
		}
	}
	cout<<len+1<<endl;
	for (int i=0;i<len+1;i++) {
		cout<<ans[i].size()<<' ';
		for (auto j:ans[i]) cout<<j<<' ';
		cout<<endl;
	} 
}

