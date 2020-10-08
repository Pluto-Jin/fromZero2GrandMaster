#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;

const int N=2e5+5;

struct edge_t{vector<int> adj;int h;}edge[N];
vector<vector<int>> clr;
int q[N];
int dep[N];
int n;


pii bfs1(int rt) {
	int qh=0,qt=0;
	int m=0,ind=rt;
	dep[rt]=0;
	q[qh++]=rt;
	while (qt<qh) {
		int x=q[qt++];
		for (auto i:edge[x].adj) {
			if (dep[i]==-1) {
				q[qh++]=i;
				dep[i]=dep[x]+1;
				if (dep[i]>m) {
					m=dep[i];
					ind=i;
				}
			}
		}
	}
	return mp(m,ind);
}

int height(int node) {
	if (edge[node].adj.size()==1) {edge[node].h=0;return 0;}
	for (auto i:edge[node].adj) 
		if (dep[i]<dep[node]) continue;
		else edge[node].h=max(edge[node].h,height(i));
}
int diameter(int rt) {
	if (edge[node].adj.size()==1) return 0;
	int res=0,m1=0,m2=0;
	for (auto i:edge[node].adj) 
		if (dep[i]<dep[node]) continue;
		else {
			int tmp=edge[i].h;
			if (tmp>m1) {m2=m1;m1=tmp;}
			else if (tmp>m2) {m2=tmp;}
			res=max(res,diameter(i));
		}
	res=max(res,m1+m2+2);
	return res;
}

void clring(int rt,int a) {
	while (a!=rt) {
		int x=edge[a].par;
		clr[a][x]=1;
		clr[x][a]=1;
		a=x;
	}
} 

pii bfs2(int rt) {
	int qh=0,qt=0;
	int m=0,ind=edge[rt].adj[0];
	q[qh++]=rt;
	dep[rt]=0;
	while (qt<qh) {
		int x=q[qt++];
		for (auto i:edge[x].adj) {
			if (dep[i]==-1) {
				dep[i]=dep[x]+1;
				if (clr[i][x]) q[qh++]=i;
				else {
					pii tmp=bfs1(i);
					if (tmp.fi+1>m) {
						m=tmp.fi+1;
						ind=tmp.se;
					}
				}
			}
		}
	}
	return mp(m,ind);
}

int main()
{
	cin>>n;
	fill(dep,dep+n+1,-1);
	clr.resize(n+1);
	for (auto &i:clr) i.resize(n+1);
	for (int i=1;i<n;i++) {
		int x,y;
		cin>>x>>y;
		edge[x].adj.pb(y);
		edge[y].adj.pb(x);
	}
	int rt,ans=0;
	int a[3];
	for (rt=1;rt<=n;rt++) if (edge[rt].adj.size()==1) break;
	a[0]=rt;
	pii tmp=bfs1(rt);
	ans+=tmp.fi;
	a[1]=tmp.se;
	clring(rt,tmp.se);
	fill(dep,dep+n+1,-1);
	tmp=bfs2(rt);
	ans+=tmp.fi;
	a[2]=tmp.se;

	cout<<ans<<endl<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
}

