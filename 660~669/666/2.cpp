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

const int N=1e5;
ll a[N];
int ok;

ll fpow(ll a,ll b) {
	if (a==1) return 1;
	ll res=1;
	while (ok and b) {
		if (b&1) res*=a;
		if (res>1e14) {ok=0;break;}
		b>>=1; a*=a;
	}
	return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	ok=1;
	ll ans=1e18;
	for (int i=1;;i++) {
		if (i>1 and n>=50) break;
		ll cur=0;
		for (int j=0;ok and j<n;j++) {
			cur+=abs(fpow(i,j)-a[j]);
			if (cur>=1e14) break;
		}
		if (!ok or cur>=1e14 or cur>=ans) break;
		ans=cur;
	}
	cout<<ans<<endl;
}
