#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

vector<string> mv,clr;
vvi vis;
int n,m;

void dfs1(int x, int y, int &cnt, int &blk, int ref=0) {
	if (vis[x][y]==2 or vis[x][y]==1) return;
	if (ref) vis[x][y]=1;
	else {
		if (!vis[x][y]) vis[x][y]=-1;
		else if (vis[x][y]==-1){
			vis[x][y]=2; cnt++;
			if (clr[x][y]=='0') blk++;
		}
	}
	switch(mv[x][y]) {
		case 'R': y++;break;
		case 'L': y--;break;
		case 'D': x++;break;
		case 'U': x--;break;
	}
	dfs1(x,y,cnt,blk,ref);
}
void dfs2(int cx,int cy, int px, int py, int &cnt) {
	if (clr[cx][cy]=='1' and clr[px][py]=='0') clr[cx][cy]='0',cnt++;

	if (cx>0 and mv[cx-1][cy]=='D' and vis[cx-1][cy]==2) cx--;
	else if (cx<n-1 and mv[cx+1][cy]=='U' and vis[cx+1][cy]==2) cx++;
	else if (cy>0 and mv[cx][cy-1]=='R' and vis[cx][cy-1]==2) cy--;
	else if (cy<m-1 and mv[cx][cy+1]=='L' and vis[cx][cy+1]==2) cy++;	
	
	if (px>0 and mv[px-1][py]=='D' and vis[px-1][py]==1) dfs2(cx,cy,px-1,py,cnt);
	if (px<n-1 and mv[px+1][py]=='U' and vis[px+1][py]==1) dfs2(cx,cy,px+1,py,cnt);
	if (py>0 and mv[px][py-1]=='R' and vis[px][py-1]==1) dfs2(cx,cy,px,py-1,cnt);
	if (py<m-1 and mv[px][py+1]=='L' and vis[px][py+1]==1) dfs2(cx,cy,px,py+1,cnt);	
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n>>m;
		mv.resize(n);
		clr.resize(n);
		vis.resize(n);
		for (int i=0;i<n;i++) vis[i].resize(m),cin>>clr[i];
		for (int i=0;i<n;i++) cin>>mv[i];
		int ans1=0,ans2=0,tmp=0;
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (!vis[i][j]) dfs1(i,j,ans1,ans2),dfs1(i,j,tmp,tmp,1);
		assert(tmp==0);
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (vis[i][j]==2) dfs2(i,j,i,j,ans2);
		cout<<ans1<<' '<<ans2<<endl;
		mv.resize(0);
		clr.resize(0);
		vis.resize(0);
	}
}

