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

	int n; cin>>n;
	ll cur=0;
	vi ar(n+1),cnt(n+1);
	for (int i=1;i<=n;i++) cin>>ar[i],cur+=ar[i];
	int q; cin>>q;
	map<pii,int> dic;
	while (q--) {
		int s,t,u; cin>>s>>t>>u;
		int &tmp=dic[mp(s,t)];
		if (tmp) {
			if (--cnt[tmp]<ar[tmp]) cur++;
			tmp=0;
		}
		if (u) {
			tmp=u;
			if (++cnt[tmp]<=ar[tmp]) cur--;	
		}	
		cout<<cur<<endl;
	}
}

