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
#include<ctime>
#include<iomanip>

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
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

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		priority_queue<int> pq;
		vii ans;
		for (int i=1;i<=n;i++) pq.push(i);
		while (pq.size()>1) {
			int x,y;
			x=pq.top(); pq.pop();
			y=pq.top(); pq.pop();
			ans.pb(mp(x,y));
			pq.push(x+y+1>>1);
		}
		cout<<pq.top()<<endl;
		for (auto [i,j]:ans) cout<<i<<' '<<j<<endl;
	}
	
	return 0;
}
