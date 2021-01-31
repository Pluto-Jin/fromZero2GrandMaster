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

const int N=1e5+1;
int mip[N];
vi pr;

void sieve(int n) {
	for (int i=2;i<=n;i++) {
		if (!mip[i]) mip[i]=i,pr.pb(i);
		for (auto j:pr) {
			if (i*j>n) break;
			mip[i*j]=j;
			if (i%j==0) break;
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	sieve(100000);
	int t; cin>>t;
	while (t--) {
		map<int,int> mi,ma,a[4];
		for (int i=0;i<4;i++) {
			int x; cin>>x;
			for (auto tmp:pr) {
				while (x%tmp==0) x/=tmp,a[i][tmp]++;
				if (1ll*tmp*tmp>x) break;
			}
			if (x>1) a[i][x]++;
		}
		int ok=1;
		for (auto [i,j]:a[0]) mi[i]=0,ma[i]=100;
		for (auto [i,j]:a[3]) mi[i]=0,ma[i]=100;
		for (auto [i,j]:a[0]) {
			if (j==a[1][i]) mi[i]=j;
			else mi[i]=ma[i]=a[1][i];
		}
		for (auto [i,j]:a[3]) {
			if (j==a[2][i]) {
				if (mi[i]>j) {ok=0;break;}
				chkmin(ma[i],j);
			}
			else {
				if (j<mi[i] or j>ma[i]) {ok=0;break;}
				mi[i]=ma[i]=j;
			}
		}
		if (ok) {
			ll res=1;
			for (auto [i,j]:mi) res*=ma[i]-j+1;
			cout<<res<<endl;
		} else cout<<0<<endl;
	}
	
	return 0;
}
