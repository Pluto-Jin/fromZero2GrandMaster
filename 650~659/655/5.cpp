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

const int N=101;
int n,m,dp[N][N],lmst[N][N],rmst[N][N],vis[N][N];

int solve(int x, int y) {
	if (x>y or vis[x][y]) return dp[x][y];
	vis[x][y]=1;
	int ma=0;
	for (int k=x;k<=y;k++) {
		int cur=solve(x,k-1)+solve(k+1,y),cnt=0;
		for (int i=1;i<=n;i++) if (lmst[i][k]>=x and rmst[i][k]<=y) cnt++;
		ma=max(ma,cur+cnt*cnt);
	}
	return dp[x][y]=ma;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		int k; cin>>k;
		while (k--) {
			int l,r; cin>>l>>r;
			for (int j=l;j<=r;j++) lmst[i][j]=l,rmst[i][j]=r;  
		}
	}
	cout<<solve(1,m)<<endl;
}

