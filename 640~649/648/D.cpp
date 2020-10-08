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

int ar[52][52],vis[52][52];
int mr[4]={1,-1,0,0},mc[4]={0,0,1,-1};
int n,m; 

void dfs(int r,int c) {
	vis[r][c]=1;
	for (int k=0;k<4;k++) {
		int nr=mr[k]+r,nc=mc[k]+c;
		if (ar[nr][nc]=='#' or vis[nr][nc]) continue;
		dfs(nr,nc);
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n>>m;
		for (int j=0;j<=m+1;j++) ar[0][j]='#',ar[n+1][j]='#';
		for (int i=0;i<=n+1;i++) ar[i][0]='#',ar[i][m+1]='#';
		int cnt=0;
		for (int i=1;i<=n;i++) {
			string s; cin>>s;
			for (int j=1;j<=m;j++) {
				ar[i][j]=s[j-1];
				vis[i][j]=0;
				if (s[j-1]=='G') cnt++;
			}
		}
		if (!cnt and ar[n][m]!='B') {
			cout<<"Yes"<<endl;
			continue;
		}
		if (ar[n][m]!='.' and ar[n][m]!='G') {
			cout<<"No"<<endl;
			continue;
		}
		ar[n][m]='G';
		int ok=1;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				if (ar[i][j]=='B') {
					for (int k=0;k<4;k++) {
						if (ar[i+mr[k]][j+mc[k]]=='G') {ok=0; break;}
						if (ar[i+mr[k]][j+mc[k]]!='B') ar[i+mr[k]][j+mc[k]]='#';
					}
				} 
				if (!ok) break;
			}
			if (!ok) break;
		}
		if (!ok) {
			cout<<"No"<<endl;
			continue;
		}
		dfs(n,m);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				if (ar[i][j]=='G' and !vis[i][j]) {ok=0; break;}
			}
			if (!ok) break;
		}
		if (!ok) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}

