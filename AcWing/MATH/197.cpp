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
int mip[N];
vi pr;

void sieve(int n) {
	for (int i=2;i<=n;i++) {
		if (!mip[i]) pr.pb(mip[i]=i);
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

	sieve(1000000);
	int n; cin>>n;
	for (auto i:pr) {
		if (i>n) break;
		int cnt=0;
		for (ll tmp=i;tmp<=n;tmp*=i) cnt+=n/tmp;
		cout<<i<<' '<<cnt<<endl;
	}
	
	return 0;
}
