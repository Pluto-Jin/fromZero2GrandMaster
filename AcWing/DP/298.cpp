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

const int N=16001,M=101;
int n,m,f[N],l[M],s[M],p[M];

struct node {
	int l,p,s;
	bool operator<(const node &tmp) const {
		return s<tmp.s;
	}
} a[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	for (int i=1;i<=m;i++) cin>>a[i].l>>a[i].p>>a[i].s;
	sort(a+1,a+m+1);
	for (int i=1;i<=m;i++) {
		deque<pii> q;
		for (int bg=max(0,a[i].s-a[i].l),j=0;bg+j<a[i].s;j++) {
			int cur=f[bg+j]-j*a[i].p;
			while (q.size() and cur>=q.back().se) q.ppb();
			q.pb(mp(bg+j,cur));
		}
		for (int j=a[i].s;j<=min(a[i].s+a[i].l-1,n);j++) {
			if (j-q.front().fi>a[i].l) q.ppf();
			int id=q.front().fi;
			chkmax(f[j],f[id]+(j-id)*a[i].p);
		}
		for (int j=1;j<=n;j++) chkmax(f[j],f[j-1]);
	}
	cout<<f[n]<<endl;

	
	return 0;
}
