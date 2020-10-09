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

const int MOD=9901;
ll fpow(ll a,ll b) {
	ll res=1;
	while (b) {
		if (b&1) res=res*a%MOD;
		b>>=1; a=a*a%MOD;
	}
	return res;
}
int sub(int a,int b) {return (a+MOD-b)%MOD;}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int a,b; cin>>a>>b;
	if (!b or a==1) {cout<<1<<endl;return 0;}
	if (!a) {cout<<0<<endl;return 0;}
	vii pf;
	for (ll i=2;i*i<=a;i++) if (a%i==0) {
		int cnt=0;
		while (a%i==0) cnt++,a/=i;
		pf.pb(mp(i,cnt));
	}
	if (a!=1) pf.pb(mp(a,1));
	ll res=1;
	for (auto [p,q]:pf) 
		if ((p-1)%MOD) res=res*sub(fpow(p,1ll*q*b+1),1)%MOD*fpow(p-1,MOD-2)%MOD;
		else res=res*(1ll*q*b+1);
	cout<<res<<endl;
}
