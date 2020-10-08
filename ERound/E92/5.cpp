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
		ll m,d,w; cin>>m>>d>>w;
		ll ans=0,mi=min(d,m);
		w/=__gcd(w,d-1);
		ll tmp=mi/w;
		ans=tmp*(tmp+1)/2*(mi%w)+(tmp-1)*tmp/2*(w-mi%w);
		cout<<ans<<endl;
	}
}

