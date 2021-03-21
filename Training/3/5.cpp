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

ll n,k;

bool check(ll mid) {
	if (mid>n) return 0;
	ll cnt=0;
	for (int i=(mid%2==0);i<60;i++,mid<<=1) {
		ll ma=mid+(1ll<<i)-1;
		if (mid>n) break;
		if (ma>=n) {
			cnt+=n-mid+1;
			break;
		}
		cnt+=1ll<<i;
	}
	return cnt>=k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>k;
	ll lo=0,hi=6e17;
	while (lo<hi-1) {
		ll mid=lo+(hi-lo>>1);
		if (check(mid<<1)) lo=mid;
		else hi=mid;
	}
	if (check(lo*2+1)) cout<<lo*2+1<<endl;
	else cout<<lo*2<<endl;
	
	return 0;
}
