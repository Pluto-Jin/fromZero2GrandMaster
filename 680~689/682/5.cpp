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

const int N=2e5+1;
int a[N];

int hbit(int x) {
	for (int i=0;i<5;i++) x|=x>>(1<<i);
	return x^(x>>1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	ll ans=0,rep=0;
	for (int k=0;k<2;k++) {
		for (int i=1;i<n-1;i++) {
			ll sum=a[i+1];
			int x=hbit(a[i]);
			for (int j=i+2;j<=n and sum<x<<1;sum+=a[j++]) {
				int y=hbit(a[j]);
				if (y>x or sum!=(a[i]^a[j])) continue;
				if (x==y) rep++;
				else ans++;
			}
		}
		reverse(a+1,a+n+1);
	}
	cout<<ans+rep/2<<endl;
	
	return 0;
}
