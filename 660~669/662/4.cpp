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

int ar[2002][2002],cnt[4][2002][2002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	for (int i=1;i<=n;i++) {
		string s; cin>>s;
		for (int j=1;j<=m;j++) {
			ar[i][j]=s[j-1];
			for (int k=0;k<4;k++) cnt[k][i][j]=1;
		}
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (ar[i][j]==ar[i-1][j] and ar[i][j]==ar[i][j-1]) 
		cnt[0][i][j]=min(cnt[0][i-1][j],cnt[0][i][j-1])+1;
	for (int i=n;i>=1;i--) for (int j=m;j>=1;j--) if (ar[i][j]==ar[i+1][j] and ar[i][j]==ar[i][j+1])
		cnt[1][i][j]=min(cnt[1][i+1][j],cnt[1][i][j+1])+1;
	for (int i=1;i<=n;i++) for (int j=m;j>=1;j--) if (ar[i][j]==ar[i-1][j] and ar[i][j]==ar[i][j+1])
		cnt[2][i][j]=min(cnt[2][i-1][j],cnt[2][i][j+1])+1;
	for (int i=n;i>=1;i--) for (int j=1;j<=m;j++) if (ar[i][j]==ar[i+1][j] and ar[i][j]==ar[i][j-1])
		cnt[3][i][j]=min(cnt[3][i+1][j],cnt[3][i][j-1])+1;

	ll ans=0;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
		int cur=1e9;
		for (int k=0;k<4;k++) cur=min(cnt[k][i][j],cur);
		ans+=cur;
	} 
	cout<<ans<<endl;
}

