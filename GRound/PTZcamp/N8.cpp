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
#include<numeric>
#include<cstdlib>
#include<ctime>
#include<iomanip>

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ppf pop_front
#define ppb pop_back
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
typedef std::vector<int> vi;
typedef std::vector<pii> vii;
typedef std::vector<std::vector<int>> vvi;

using namespace std;

template<class T,class T2>
inline bool chkmax(T &x,const T2 &y){return x<y?(x=y,1):0;}
template<class T,class T2>
inline bool chkmin(T &x,const T2 &y){return x>y?(x=y,1):0;}

const int N=1e6+1;
int n;
pii st[N][21];
vi ans;

void init() {
	for (int i=1;i<21;i++) 
		for (int j=1;j+(1<<i)-1<=n;j++) 
			st[j][i]=max(st[j][i-1],st[j+(1<<i-1)][i-1]);
}
pii query(int l,int r) {
	int len=r-l+1;
	for (int i=20;~i;i--) if (len>>i&1) return max(st[l][i],st[r-(1<<i)+1][i]);
}

void solve(int l,int r,int x) {
	auto [v,id]=query(l,r);
	if (v+r-l<x) return;
	ans.pb(id);
	if (id>l) solve(l,id-1,max(v,x-r+id-1));
	if (id<r) solve(id+1,r,max(v,x-id+l-1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	int ma=0;
	for (int i=1;i<=n;i++) cin>>st[i][0].fi,chkmax(ma,st[i][0].fi),st[i][0].se=i;
	init();
	solve(1,n,ma);
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for (auto i:ans) cout<<i<<' ';
	cout<<endl;
	
	return 0;
}
