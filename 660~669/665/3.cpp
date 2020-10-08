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
		int mi=1e9;
		for (int i=0;i<n;i++) {
			int x; cin>>x;
			ar[i]=br[i]=x;
			mi=min(mi,x);
		}
		sort(br.begin(),br.end());
		int ok=1;
		for (int i=0;ok and i<n;i++) {
			if (ar[i]%mi and ar[i]!=br[i]) ok=0;
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
}

