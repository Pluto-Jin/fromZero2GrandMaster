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
		int n,x,m; cin>>n>>x>>m;
		int lo=x,hi=x;
		for (int i=0;i<m;i++) {
			int l,r; cin>>l>>r;
			if (l<=hi and r>=lo) lo=min(lo,l),hi=max(hi,r);
		}
		cout<<hi-lo+1<<endl;
	}
}

