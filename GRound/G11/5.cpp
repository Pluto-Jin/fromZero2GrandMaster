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

struct out{
	ll a; char c; ll b;
};
vector<out> ans;

int hbit(int x) {
	for (int i=0;i<5;i++) x|=x>>(1<<i);
	return x^(x>>1);
} 

ll mul(ll x,ll a) {
	for (int i=0;(1ll<<i)<=a;i++) 
		ans.pb({x*(1ll<<i),'+',x*(1ll<<i)});
	ll res=x;
	for (int i=0;i<64;i++) {
		if (a>>i&1) {
			for (i=i+1;i<64;i++) if (a>>i&1) 
				ans.pb({res,'+',x*(1ll<<i)}),res+=x*(1ll<<i);
			break;
		} else res<<=1;
	}
	return res;
}

ll exgcd(ll a,ll b,ll &x,ll &y) {
	if (!b) {
		x=1,y=0;
		return a;
	} else {
		ll res=exgcd(b,a%b,x,y),tmp=x;
		x=y,y=tmp-a/b*y;
		return res;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	ll x; cin>>x;
	int tmp=hbit(x);
	mul(x,tmp);
	ans.pb({x,'^',x*tmp});
	ll y=x^x*tmp;
	ll a,b;
	exgcd(y,x,a,b);
	y=mul(y,abs(a));
	x=mul(x,abs(b));
	if (y>x) swap(x,y);
	if (y&1) ans.pb({y,'+',y}),ans.pb({x,'+',y}),x+=y,y+=y;
	ans.pb({y,'^',x});
	cout<<ans.size()<<endl;
	for (auto [a,c,b]:ans) cout<<a<<' '<<c<<' '<<b<<endl;

	return 0;
}
