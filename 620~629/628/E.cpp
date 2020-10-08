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

const int N=1e6+1;
bool npr[N],vis[N]; //npr:not_prime, vis:repeting values
int ind[N],cnt,ma; //ind:index of a prime, ma:max index of prime<1000
int mark[N],d[N],fa[N]; //mark:start node of bfs
vi edge[N];

int solve() {
	fill(mark,mark+N,-1);
	int res=1e9;
	for (int i=0;i<ma;i++) {
		if (edge[i].size()<=1) continue;
		d[i]=0;
		mark[i]=i;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int at=q.front(); q.pop();
			for (auto to:edge[at]) {
				if (mark[to]!=i) mark[to]=i,fa[to]=at,q.push(to),d[to]=d[at]+1;
				else if (to!=fa[at]) res=min(res,d[at]+d[to]+1);
			}
		}
	}
	return res==1e9?-1:res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	vi pr;
	for (int i=2;i<N;i++) {
		if (!npr[i]) {
			pr.pb(i);
			ind[i]=++cnt;
			if (i>=1000 and !ma) ma=ind[i];
			for (int j=2*i;j<N;j+=i) npr[j]=true;
		}
	}
	int two=0;
	for (int t=0;t<n;t++) {
		int i; cin>>i;
		if (i==1) {
			cout<<1<<endl;
			return 0;
		}
		vi tmp;
		int ok=1;
		for (int j=0;j<cnt and pr[j]<=i;j++) {
			if (ind[i]) {
				tmp.pb(i);
				break;
			}
			int num=pr[j];
	 		while (num<=1000 and i%(num*num)==0) i/=num*num;
			if (i==1 and ok) {
				cout<<1<<endl;
				return 0;
			}
			if (i%num==0) tmp.pb(num),i/=num,ok=0;
		}
		if (tmp.size()==1) tmp.push_back(1);
		int x=tmp[0],y=tmp[1];
		if (vis[x*y]) {
			two=1;
			continue;
		}
		vis[x*y]=1;
		edge[ind[x]].pb(ind[y]);
		edge[ind[y]].pb(ind[x]);
	}
	if (two) cout<<2<<endl;
	else cout<<solve()<<endl;
}

