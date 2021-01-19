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

int solve(int k,vi x) {
	if (k<0) return 0;
	vi y,tmp;
	for (auto i:x) if (a[i]>>k&1) y.pb(i); else tmp.pb(i);
	if (y.size()<2) return solve(k-1,tmp);
	if (tmp.size()<2) return solve(k-1,y);
	return min(solve(k-1,y)+tmp.size()-1,solve(k-1,tmp)+y.size()-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	vi x;
	for (int i=1;i<=n;i++) cin>>a[i],x.pb(i);
	cout<<solve(30,x)<<endl;
	
	return 0;
}
