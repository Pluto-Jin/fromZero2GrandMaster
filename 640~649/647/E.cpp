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

const int N=1e6+2,MOD=1e9+7;
int cnt[N],ok;

ll fpow(ll a, ll b) {
	ll res=1;
	while (b) {
		if (b&1) {
			res=res*a;
			if (res>1e6) ok=0;
			res%=MOD;
		}
		b>>=1;
		a=a*a;
		if (a>1e6) ok=0;
		a%=MOD;
	}
	return res;
}

ll n,p;
vi ar;
ll solve(int cur,ll need) {
	ll res=0;
	if (cur==ar.size()) {
		if (!need) return 0;
		return fpow(p,ar[cur-1])*need%MOD;
	}
	if (!need) {
		need=cnt[ar[cur]]%2;
	} else {
		need*=fpow(p,ar[cur-1]-ar[cur]);
		if (!ok or need>1e6) {
			return -1;
		} else if (cnt[ar[cur]]>=need) {
			need=(cnt[ar[cur]]-need)%2;
		} else {
			need-=cnt[ar[cur]];
		}
	}
	res=solve(cur+1,need);
	if (res==-1) {
		res=fpow(p,ar[cur])*need%MOD;
		for (int i=cur+1;i<ar.size();i++) {
			res=res+MOD-fpow(p,ar[i])*cnt[ar[i]]%MOD;
			res%=MOD;
		}
	}
	return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n>>p;
		ok=1;
		for (int i=0;i<n;i++) {
			int x; cin>>x;
			if (!cnt[x]) ar.pb(x);
			cnt[x]++;
		}
		sort(ar.begin(),ar.end());
		reverse(ar.begin(),ar.end());

		cout<<solve(0,0)<<endl;

		for (auto i:ar) cnt[i]=0;
		ar.resize(0);
	}
}

