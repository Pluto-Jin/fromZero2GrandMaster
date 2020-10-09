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

int MOD;
ll fpow(ll a,ll b) {
	ll res=1;
	while (b) {
		if (b&1) res=res*a%MOD;
		b>>=1; a=a*a%MOD;
	}
	return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int a,b; cin>>a>>b>>MOD;
	if (MOD==1) cout<<0<<endl;
	else cout<<fpow(a,b)<<endl;

	return 0;
}
