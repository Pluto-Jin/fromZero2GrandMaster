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
		for (auto &i:ar) cin>>i;
		sort(ar.begin(),ar.end());
		for (int p=n-1,i=0;p>=0;p--) {
			br[p]=ar[i];
			if (i<n/2) i=n-1-i;
			else i=n-i;
		}
		for (auto i:br) cout<<i<<' '; cout<<endl;
	}
}

