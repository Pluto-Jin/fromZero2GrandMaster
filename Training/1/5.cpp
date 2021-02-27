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

int exgcd(int a,int b,int &x,int &y) {
	if (!b) {
		x=1,y=0;
		return a;
	} else {
		int res=exgcd(b,a%b,x,y),tmp=x;
		x=y,y=tmp-a/b*y;
		return res;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,s,k; cin>>n>>s>>k;
		int t=n-s,g=gcd(k,n);
		if (t%g) cout<<-1<<endl;
		else {
			int x,y;
			exgcd(k,n,x,y);
			x=(1ll*x*t/g%(n/g)+n/g)%(n/g);
			cout<<x<<endl;
		}
	}
	
	return 0;
}
