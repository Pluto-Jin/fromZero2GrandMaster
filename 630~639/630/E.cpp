#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

const ll mod=998244353;
ll fpow(ll a,ll b)
{
	if (!a) return 0;
	ll res=1;
	while (b) {
		if (b%2) res=res*a%mod;
		b/=2,a=a*a%mod;
	}
	return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	ll n,m,l,r; cin>>n>>m>>l>>r;
	if (l==r) {
		cout<<1<<endl;
		return 0;
	}
	ll a[2]={(r-l+1)/2,r-l+1-(r-l+1)/2};
	if (n%2 and m%2) cout<<fpow(r-l+1,n*m)<<endl;
	else cout<<(fpow(a[0]+a[1],n*m)+fpow(abs(a[0]-a[1]),n*m))*fpow(2,mod-2)%mod<<endl;

}

