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
		int n,k; cin>>n>>k;
		int ans=n;
		for (int i=1;i<=sqrt(n);i++) {
			if (n%i) continue;
			if (i<=k) ans=min(ans,n/i);
			if (n/i<=k) ans=min(ans,i);
		}
		cout<<ans<<endl;
	}
}


