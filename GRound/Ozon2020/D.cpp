#include "bits/stdc++.h"
using namespace std;

#define pb push_back
const int N=2000;
int used[N],edge[N][N];
vector<int> eg[N];
int n,done[2][N];

bool dfs(int x,int t,int tg) 
{
	if (x==tg) return true;
	for (auto i:eg[x]) {
		if (!used[i] and !done[i]) {
			done[t][i]=1;
			if (dfs(i,t,tg)) return true;
			done[t][i]=0;
		}
	}
	return false;
}
void dfs2(int a,int tg) 
{
	stack<int> s;
	s.push(a);
	while (!s.empty()) {
		int tmp=s.top();s.pop();
		for (auto i:eg[tmp]) if(!used[i] and i!=tg) {used[i]=1;s.push(i);}
	}
}
int solve(int &a,int &b,int ans) 
{
	used[a]=1;used[b]=1;
	if (ans==a or ans==b) used[ans]=0;
	int tr1=dfs(a,0,ans),tr2=dfs(b,1,ans);
	for (int i=1;i<=n;i++) {
		if (done[0][i]==1 or done[1][i]==1) used[i]=1;
		done[0][i]=0;
		done[1][i]=0;
	}
	if (ans!=a) dfs2(a,ans);
	if (ans!=b) dfs2(b,ans);
	int ok=0,cnt=0;
	for (int i=1;i<=n;i++) if (!used[i]) cnt++;
	if (cnt==1) for (int i=1;i<=n;i++) if (!used[i]) return i;
	if (cnt==2) {
		int tmp[2],p=0;
		for (int i=1;i<=n;i++) if (!used[i]) tmp[p++]=i;
		a=tmp[0],b=tmp[1];
		return 0;
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) if (!used[i] and !used[j] and i!=j and edge[i][j]==0) {ok=1;a=i;b=j;break;}
		if (ok) break;
	}
	return 0;
}
int main()
{
	cin>>n;
	for (int i=1;i<n;i++) {
		int x,y;
		cin>>x>>y;
		edge[x][y]=1;
		edge[y][x]=1;
		eg[x].pb(y);
		eg[y].pb(x);
	}
	int ok=1,a=-1,b,ans;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++)
		if (i!=j and edge[i][j]==0) {a=i;b=j;break;}
		if (a!=-1) break;
	}
	if (n==2) for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) if (edge[i][j]) {a=i;b=j;break;}
		if (a!=-1) break;
	}
	cout<<"? "<<a<<' '<<b<<endl;
	cout.flush();
	cin>>ans;
	while (ok) {
		int okk=solve(a,b,ans);	
		if (okk) {ans=okk;break;}
		cout<<"? "<<a<<' '<<b<<endl;
		cout.flush();
		cin>>ans;
	}
	cout<<"! "<<ans<<endl;

}
