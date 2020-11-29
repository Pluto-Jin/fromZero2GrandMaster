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

int n,m,a[3][2001];

struct cmp {
	bool operator()(const pii &x,const pii &y) {
		return a[1][x.fi]+a[2][x.se]>a[1][y.fi]+a[2][y.se];
	}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n>>m;
		for (int j=1;j<=m;j++) cin>>a[1][j];
		sort(a[1]+1,a[1]+m+1);
		for (int i=2;i<=n;i++) {
			priority_queue<pii,vector<pii>,cmp> pq;
			for (int j=1;j<=m;j++) {
				cin>>a[2][j];
				pq.push(mp(1,j));
			}
			for (int j=1;j<=m;j++) {
				auto [x,y]=pq.top(); pq.pop();
				a[0][j]=a[1][x]+a[2][y];
				if (x<m) pq.push(mp(x+1,j));
			}
			for (int j=1;j<=m;j++) a[1][j]=a[0][j];
		}
		for (int j=1;j<=m;j++) cout<<a[1][j]<<' ';
		cout<<endl;
	}
	
	return 0;
}
