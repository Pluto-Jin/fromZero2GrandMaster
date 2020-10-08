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
		vi ar(n+1);
		for (int i=1;i<=n;i++) cin>>ar[i];
		ll ans=0;
		for (int i=1;i<=n;i++) {
			vi cl(n+1),cr(n+1);
			for (int j=i+1;j<=n;j++) cr[ar[j]]++;
			ll cur=0;
			for (int j=i+1;j<=n;j++) {
				int c=ar[j];
				cur-=cl[c]++;
				if (c==ar[i]) ans+=cur;
				cur+=--cr[c];
			}
		}
		cout<<ans<<endl;
	}
}

