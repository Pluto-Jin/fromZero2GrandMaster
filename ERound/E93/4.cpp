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

ll dp[205][205][205];
int r,g,b;
vi rr,gg,bb;
bool vis[205][205][205];

ll solve(int x,int y,int z) {
	if (vis[x][y][z]) return dp[x][y][z];
	vis[x][y][z]=1;
	ll res=0;
	if (x<r and y<g) res=max(res,rr[r-x-1]*1ll*gg[g-y-1]+solve(x+1,y+1,z));
	if (x<r and z<b) res=max(res,rr[r-x-1]*1ll*bb[b-z-1]+solve(x+1,y,z+1));
	if (z<b and y<g) res=max(res,bb[b-z-1]*1ll*gg[g-y-1]+solve(x,y+1,z+1));
	return dp[x][y][z]=res;
} 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>r>>g>>b;
	rr.resize(r);
	gg.resize(g);
	bb.resize(b);
	for (auto &i:rr) cin>>i;
	for (auto &i:gg) cin>>i;
	for (auto &i:bb) cin>>i;
	sort(rr.begin(),rr.end());
	sort(gg.begin(),gg.end());
	sort(bb.begin(),bb.end());

	cout<<solve(0,0,0)<<endl;
}

