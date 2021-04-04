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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	int x=1,y=n;
	while (x<y) {
		for (int i=1;i<=m;i++) cout<<x<<' '<<i<<endl<<y<<' '<<m-i+1<<endl;
		y--,x++;
	}
	if (x==y) {
		x=1,y=m;
		while (x<y) cout<<(n+1)/2<<' '<<x<<endl<<(n+1)/2<<' '<<y<<endl,x++,y--;
		if (x==y) cout<<(n+1)/2<<' '<<(m+1)/2<<endl;
	}
	
	return 0;
}
