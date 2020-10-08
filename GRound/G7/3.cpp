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
	int mi=n-k+1;
	vi pos;
	for (int i=0;i<n;i++) {
		int x; cin>>x;
		if (x>=mi) pos.pb(i);
	}
	ll ans=1;
	for (int i=0;i<pos.size()-1;i++) {
		ans*=pos[i+1]-pos[i];
		ans%=998244353;
	}
	cout<<1ll*(mi+n)*k/2<<' '<<ans<<endl;
}

