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
#include<iomanip>

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
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

const int N=1e5+2;
int n,a[N];
ll f1[N],f2[N];

void update(int x,int v) {
	ll tmp=1ll*x*v;
	for (;x<=n+1;x+=x&-x) f1[x]+=v,f2[x]+=tmp;
}

ll query(int x) {
	ll a=0,b=0,tmp=x;
	for (;x;x-=x&-x) a+=f1[x],b+=f2[x];
	return a*(tmp+1)-b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int q; cin>>n>>q;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		update(i,a[i]-a[i-1]);
	}
	while (q--) {
		char c; cin>>c;
		if (c=='C') {
			int l,r,x; cin>>l>>r>>x;
			update(l,x), update(r+1,-x);
		} else {
			int l,r; cin>>l>>r;
			cout<<query(r)-query(l-1)<<endl;
		}
	}
	
	return 0;
}
