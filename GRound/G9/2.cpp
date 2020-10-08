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
		vvi ar(n,vi(m)),br(n,vi(m));
		int ok=1;
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
			cin>>ar[i][j];
			if (i==0 or j==0 or i==n-1 or j==m-1) br[i][j]=3;
			else br[i][j]=4;
		}
		br[0][0]=br[0][m-1]=br[n-1][0]=br[n-1][m-1]=2;
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (ar[i][j]>br[i][j]) ok=0;
		if (!ok) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			for (auto i:br) {for (auto j:i) cout<<j<<' '; cout<<endl;}
		}
	}
}

