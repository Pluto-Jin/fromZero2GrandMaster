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
		vi ar(n);
		for (auto &i:ar) cin>>i;
		int ans=-1;
		for (int i=2;i<n;i++) if (ar[i]<ar[i-1] and ar[i-1]>ar[i-2]) ans=i;
		ans++;
		if (!ans) cout<<"NO"<<endl;
		else cout<<"YES"<<endl<<ans-2<<' '<<ans-1<<' '<<ans<<endl;
	}
}

