#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
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

const int N=1e5+1;
int n,ok;
vi edge[N];

int dfs(int at=1,int par=-1) {
	int res=1;
	for (auto to:edge[at]) if (to!=par) res+=dfs(to,at);
	if (res==n/2) {
		ok=1;
		for (auto to:edge[at]) if (to!=par) {
			cout<<at<<' '<<to<<endl;
			cout<<to<<' '<<par<<endl;
			break;
		}
	}
	return res;
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n; ok=0;
		int x,y;
		for (int i=1;i<n;i++) {
			cin>>x>>y;
			edge[x].pb(y);
			edge[y].pb(x);
		}
		if (n%2==0) dfs();
		if (!ok) cout<<x<<' '<<y<<endl<<x<<' '<<y<<endl;
		for (int i=1;i<=n;i++) edge[i].resize(0);
	}
}
