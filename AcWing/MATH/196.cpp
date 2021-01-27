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

const int N=1e5+1,M=1e6+1;
int mip[N],npr[M];
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
	ll l,r;
	while (cin>>l>>r) {
		for (int i=0;i<=r-l;i++) npr[i]=0; 
		for (auto i:pr) {
			if (i>r) break;
			ll j=(i>=l?i+i:(l+i-1)/i*i);
			for (;j<=r;j+=i) npr[j-l]=1;
		}
		if (l==1) npr[0]=1;
		ll pi=-1e9,pa=1e9,mi=1e9,ma=0,a[4]={0};
		for (int i=0;i<=r-l;i++) if (!npr[i]) {
			if (chkmin(mi,i-pi)) a[0]=pi+l,a[1]=i+l;
			if (chkmax(ma,i-pa)) a[2]=pa+l,a[3]=i+l;
			pi=pa=i;
		}
		if (a[0]<l) cout<<"There are no adjacent primes."<<endl;
		else cout<<a[0]<<','<<a[1]<<" are closest, "<<a[2]<<','<<a[3]<<" are most distant."<<endl;
	}
	
	return 0;
}
