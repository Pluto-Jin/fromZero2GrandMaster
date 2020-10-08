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
		vector<ll> ar(n),br(n);
		for (int i=0;i<n;i++) cin>>ar[i]>>br[i];
		ll mi=ar[0],cur;
		for (int i=1;i<n;i++) mi+=max(0ll,ar[i]-br[i-1]);
		cur=mi;
		for (int i=1;i<n;i++) {
			cur+=min(br[i-1],ar[i])-min(br[(i+n-2)%n],ar[i-1]);
			mi=min(cur,mi);
		}
		cout<<mi<<endl;
	}
}

