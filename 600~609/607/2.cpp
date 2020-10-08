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
		int ans=4;
		vector<string> ar(n);
		for (auto &i:ar) cin>>i;
		for (int i=0;i<n;i++) {
			int ok=1;
			for (int j=0;j<m;j++) if (ar[i][j]=='P') ok=0;
			if (ok) {
				if (i==0 or i==n-1) ans=1;
				else ans=min(ans,2);
			}
		}
		for (int i=0;i<m;i++) {
			int ok=1;
			for (int j=0;j<n;j++) if (ar[j][i]=='P') ok=0;
			if (ok) {
				if (i==0 or i==m-1) ans=1;
				else ans=min(ans,2);
			}
		}
		if (ar[0][0]=='A' or ar[0][m-1]=='A' or ar[n-1][0]=='A' or ar[n-1][m-1]=='A') ans=min(ans,2);
		for (int i=0;i<m;i++) if (ar[0][i]=='A' or ar[n-1][i]=='A') ans=min(ans,3);
		for (int i=0;i<n;i++) if (ar[i][0]=='A' or ar[i][m-1]=='A') ans=min(ans,3);
		int ok=0,okk=1;
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (ar[i][j]=='A') ok=1; else okk=0;
		if (okk) ans=0;
		cout<<(ok?to_string(ans):"MORTAL")<<endl;
	}
}

