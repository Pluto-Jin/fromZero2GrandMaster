#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
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

const int N=2e5+1,MOD=998244353;
ll pre[N];

ll fpow(ll a,ll b) {
	ll res=1;
	while (b) {
		if (b&1) res=res*a%MOD;
		b>>=1,a=a*a%MOD;
	}
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	vi a(n);
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i-1];
	for (int i=0;i<m;i++) {
		int x,y; cin>>x>>y;
		int lo=lower_bound(a.begin(),a.end(),y)-a.begin(),hi=n-lo;
		if (hi<x) {cout<<0<<endl;continue;}
		ll ans=pre[lo]%MOD*(hi+1-x)%MOD*fpow(hi+1,MOD-2)%MOD+(pre[n]-pre[lo])%MOD*(hi-x)%MOD*fpow(hi,MOD-2)%MOD;
		cout<<ans%MOD<<endl;
	}
}
