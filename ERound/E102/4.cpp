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

const int N=2e5+5;
int pre[N],a[N],mi[N][2],ma[N][2];

int cal(int x,int y,int z,int w) {
	if (x>z) swap(x,z),swap(y,w);
	if (z>y) return y-x+1+w-z+1;
	else return max(w,y)-x+1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,m; cin>>n>>m;
		string s; cin>>s;
		for (int i=0;i<n;i++) a[i+1]=a[i]+(s[i]=='+'?1:-1);
		for (int i=1;i<=n;i++) mi[i][0]=min(a[i],mi[i-1][0]),ma[i][0]=max(a[i],ma[i-1][0]);
		mi[n+1][1]=ma[n+1][1]=a[n];
		for (int i=n;i;i--) mi[i][1]=min(a[i],mi[i+1][1]),ma[i][1]=max(a[i],ma[i+1][1]);
		while (m--) {
			int l,r; cin>>l>>r;
			int x=mi[l-1][0],y=ma[l-1][0],z=mi[r+1][1]-a[r]+(r==n?0:a[l-1]),w=ma[r+1][1]-a[r]+(r==n?0:a[l-1]);
			cout<<cal(x,y,z,w)<<endl;
		}
	}
	
	return 0;
}
