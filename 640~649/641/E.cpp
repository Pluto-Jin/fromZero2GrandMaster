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

const int N=1002;
int n,m,ar[N][N],tn[N][N],vis[N][N];
int mr[4]={1,-1,0,0},mc[4]={0,0,1,-1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>n>>m>>t;
	for (int i=1;i<=n;i++) {
		string s; cin>>s;
		for (int j=1;j<=m;j++) {
			if (s[j-1]=='0') ar[i][j]=-1;
			else ar[i][j]=1;
		}
	} 
	queue<pii> q;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			for (int k=0;k<4;k++) {
				if (ar[i][j]==ar[i+mr[k]][j+mc[k]]) 
					tn[i][j]=1,q.push(mp(i,j));
			}
			if (!tn[i][j]) tn[i][j]=-1;
		}
	}
	int cur=1;
	while (q.size()) {
		int x=q.front().fi, y=q.front().se; q.pop();
		if (tn[x][y]==cur+1) cur++;
		for (int k=0;k<4;k++) {
			int nx=x+mr[k],ny=y+mc[k];
			if (tn[nx][ny]==-1) tn[nx][ny]=cur+1,q.push(mp(nx,ny));
		}
	}
	while (t--) {
		int x,y,ok=1; 
		ll p; cin>>x>>y>>p;
		if (tn[x][y]==-1 or p<tn[x][y] or (p-tn[x][y])&1) ok=0; 
		cout<<(ok^ar[x][y]==1)<<endl;
	}
}

