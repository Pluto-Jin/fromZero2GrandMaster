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

int tx[4][4]={{0,0,1,1},{0,1,1,0},{0,0,-1,-1},{0,-1,-1,0}};
int ty[4][4]={{0,1,1,0},{0,0,1,1},{0,-1,-1,0},{0,0,-1,-1}};
pll solve(int n,ll x,int cur=0) {
	if (n==1) return mp(tx[cur][x],ty[cur][x]);
	ll cnt=1ll<<n*2,tmp=x/(cnt>>2);	
	int res=cur;
	if (tmp==0) res^=1;
	if (tmp==3) res^=3;
	auto [a,b]=solve(n-1,x-tmp*(cnt>>2),res);
	pll m=mp((1ll<<n-1)*tx[cur][tmp],(1ll<<n-1)*ty[cur][tmp]);
	if (cur<=1 and res>=2) m.fi+=(1ll<<n-1)-1,m.se+=(1ll<<n-1)-1;
	if (cur>=2 and res<=1) m.fi-=(1ll<<n-1)-1,m.se-=(1ll<<n-1)-1;
	return mp(a+m.fi,b+m.se);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		ll n,a,b; cin>>n>>a>>b;
		pll x=solve(n,a-1);
		pll y=solve(n,b-1);
		cout<<(ll)floor(0.5+10*sqrt((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se)))<<endl;
	}
}
