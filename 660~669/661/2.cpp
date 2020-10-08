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

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		vi ar(n),br(n);
		int m1=1e9,m2=1e9;
		for (auto &i:ar) cin>>i,m1=min(m1,i);
		for (auto &i:br) cin>>i,m2=min(m2,i);
		ll ans=0;
		for (int i=0;i<n;i++) {
			int tmp1=ar[i]-m1,tmp2=br[i]-m2;
			ans+=tmp1+tmp2-min(tmp1,tmp2);
		}
		cout<<ans<<endl;
	}
}

