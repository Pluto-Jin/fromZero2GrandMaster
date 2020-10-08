#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;

const int N=2000;
int n;
int x[N][N],y[N][N],ans[N][N];
char c[6]={'\0','U','L','R','D','X'};

bool check0(int r,int c,int tr,int tc)
{
	return x[r][c]==tr and y[r][c]==tc;

}
bool check(int r,int c,int tr,int tc)
{
	return !ans[r][c] and check0(r,c,tr,tc);
}
void dfs(int r,int c,int tr,int tc)
{
	if (r>1 and check(r-1,c,tr,tc)) 
		{ans[r-1][c]=4;dfs(r-1,c,tr,tc);}
	if (c>1 and check(r,c-1,tr,tc)) 	
		{ans[r][c-1]=3;dfs(r,c-1,tr,tc);}
	if (c<n and check(r,c+1,tr,tc)) 
		{ans[r][c+1]=2;dfs(r,c+1,tr,tc);}
	if (r<n and check(r+1,c,tr,tc))
		{ans[r+1][c]=1;dfs(r+1,c,tr,tc);}
}
bool dfs2(int r,int c)
{
	if (r>1 and check0(r-1,c,-1,-1)) {ans[r][c]=1;return true;}
	else if (c>1 and check0(r,c-1,-1,-1)) {ans[r][c]=2;return true;}
	else if (c<n and check0(r,c+1,-1,-1)) {ans[r][c]=3;return true;}
	else if (r<n and check0(r+1,c,-1,-1)) {ans[r][c]=4;return true;}
	else return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) cin>>x[i][j]>>y[i][j]; 
	int ok=1;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			if (check(i,j,-1,-1)) {if (!dfs2(i,j)) {ok=0;break;}continue;}
			if (ans[i][j] or !check0(i,j,i,j)) continue;
			ans[i][j]=5;
			dfs(i,j,i,j);
		}
		if (!ok) break;
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++)
			if (!ans[i][j]) {ok=0;break;}
		if (!ok) break;
	}
	if (!ok) cout<<"INVALID"<<endl;
	else {
		cout<<"VALID"<<endl;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) cout<<c[ans[i][j]];
			cout<<endl;
		}
	}

}
