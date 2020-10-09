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

const int N=5002;
int pre[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,r; cin>>n>>r;
	for (int i=0;i<n;i++) {
		int x,y,w; cin>>x>>y>>w;
		pre[++x][++y]+=w;
	}
	for (int i=1;i<N;i++) for (int j=1;j<N;j++) pre[i][j]+=-pre[i-1][j-1]+pre[i-1][j]+pre[i][j-1];
	r=min(r,5001);
	int ans=0;
	for (int i=r;i<N;i++) for (int j=r;j<N;j++) ans=max(ans,pre[i][j]+pre[i-r][j-r]-pre[i-r][j]-pre[i][j-r]);
	cout<<ans<<endl;
}
