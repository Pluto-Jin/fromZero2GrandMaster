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

int n,pos[4001],ma[4001];
bool vis[4001][4001],dp[4001][4001];

int solve(int a,int b) {
	if (vis[a][b]) return dp[a][b];
	vis[a][b]=1;
	int x=ma[a+b];
	if (!x and !a and !b) return dp[a][b]=1;
	int len=a+b+1-pos[x],res=0;
	if (a>=len) res|=solve(max(a-len,b),min(a-len,b));
	if (b>=len) res|=solve(a,b-len);
	return dp[a][b]=res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n;
		n*=2;
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) vis[i][j]=dp[i][j]=0;
		for (int i=1;i<=n;i++) {
			ma[i]=0;
			int x; cin>>x;
			pos[x]=i;
			ma[i]=max(x,ma[i-1]);
		}
		cout<<(solve(n/2,n/2)?"YES":"NO")<<endl;
	}
}

