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
		int a,b,q; cin>>a>>b>>q;
		vi ar(a*b);
		for (int i=1;i<a*b;i++) {
			ar[i]=ar[i-1];
			if (i%b%a!=i%a%b) ar[i]+=1;
		}
		while (q--) {
			ll l,r,ans; cin>>l>>r;
			ll cnt=(r-l+1)/(a*b),rem=(r-l+1)%(a*b),rl=l%(a*b),rr=r%(a*b);
			ans=cnt*ar[a*b-1];
			if (rem) {
				if (rl<=rr) ans+=ar[rr]-(!rl?0:ar[rl-1]); 
				else ans+=ar[rr]+(!rl?0:ar[a*b-1]-ar[rl-1]);
			}
			cout<<ans<<' ';
		}
		cout<<endl;
	}
}

