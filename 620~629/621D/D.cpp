#include "bits/stdc++.h"
using namespace std;

#define mp make_pair
#define eb emplace_back

typedef pair<int,int> pii;

const int N=2e5+5;
int n,m,k;
int ar[N];

vector<int> edge[N];

int dist[2][N];
int q[N];

void bfs(int d[],int s) {
	fill(d,d+n,-1);
	int qh=0,qt=0;
	d[s]=0;
	q[qh++]=s;
	while (qt<qh) {
		int x=q[qt++];
		for (auto y:edge[x]) {
			if (d[y]==-1) {
				d[y]=d[x]+1;
				q[qh++]=y;
			}
		}
	}
}

int main()
{
	cin>>n>>m>>k;
	for (int i=0;i<k;i++) {
		cin>>ar[i];
		ar[i]--;
	}
	for (int i=0;i<m;i++) {
		int x,y;
		cin>>x>>y;
		edge[--x].eb(--y);
		edge[y].eb(x);
	}
	bfs(dist[0],0);
	bfs(dist[1],n-1);
	vector<pii> br;
	for (int i=0;i<k;i++) br.eb(mp(dist[0][ar[i]]-dist[1][ar[i]],ar[i]));
	sort(br.begin(),br.end());

	int ans=0,m=-1e9-7;
	for (int i=0;i<k;i++) {
		int x=br[i].second;
		ans=max(ans,m+dist[1][x]);
		m=max(m,dist[0][x]);
	}
	cout<<min(ans+1,dist[0][n-1])<<endl;


}

