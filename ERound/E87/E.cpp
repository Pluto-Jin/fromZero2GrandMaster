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

const int N=5001;
int n,m,n1,n2,n3,cnt,mark[N],cneg[N],cpos[N];
bool dp[N][N],xuan[N];
vi edge[N];

bool bfs(int rt) {
	cnt++;
	mark[rt]=cnt;
	cpos[cnt]++;
	queue<int> q;
	q.push(rt);
	while (q.size()) {
		int at=q.front(); q.pop();
		for (auto to:edge[at]) {
			if (mark[to]) {
				if (mark[to]==mark[at]) return false;
				else continue;
			} else {
				mark[to]=-mark[at];
				if (mark[to]>0) cpos[cnt]++;
				else cneg[cnt]++;
				q.push(to);
			}
		}
	}
	return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m>>n1>>n2>>n3;
	for (int i=0;i<m;i++) {
		int x,y; cin>>x>>y;
		edge[x].pb(y);
		edge[y].pb(x);
	}
	int ok=1;
	for (int i=1;i<=n;i++) {
		if (!mark[i]) ok=bfs(i);
		if (!ok) break;
	}
	if (!ok) cout<<"NO"<<endl;
	else {
		dp[0][0]=1;
		for (int i=1;i<=cnt;i++) {
			int a=cpos[i],b=cneg[i];
			for (int j=0;j<=n2;j++) {
				if (j>=a) dp[i][j]|=dp[i-1][j-a];
				if (j>=b) dp[i][j]|=dp[i-1][j-b];
			}
		}
		if (!dp[cnt][n2]) cout<<"NO"<<endl;
		else {
			int cur=n2;
			for (int i=cnt;i>=1;i--) {
				int a=cpos[i],b=cneg[i];
				if (cur>=a and dp[i-1][cur-a]) xuan[i]=1,cur-=a;
				else cur-=b;
			}
			cout<<"YES"<<endl;
			cur=n1;
			for (int i=1;i<=n;i++) {
				int id=mark[i];
				if (!xuan[abs(id)]) id=-id;
				if (id>0) cout<<2;
				else if (cur) cout<<1,cur--;
				else cout<<3;
			}
			cout<<endl;
		}
	}
}

