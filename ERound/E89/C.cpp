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
		int n,m; cin>>n>>m;
		int ar[70][2]={0};
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				int x; cin>>x;
				ar[i+j][x]++;
			}
		}
		int ans=0;
		for (int i=2;i<(m+n+2+1)/2;i++) {
			int j=m+n+2-i;
			ans+=min(ar[i][0]+ar[j][0],ar[i][1]+ar[j][1]);
		}
		cout<<ans<<endl;
	}
}

