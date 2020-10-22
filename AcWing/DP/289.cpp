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

const int N=1e6+1;
int a[N<<1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int x,i=1;i<=n;i++) cin>>x,a[i]=a[i+n]=x;
	int ans=0;
	deque<pii> q; q.pb(mp(a[1],1));
	for (int i=2;i<=n+n/2;i++) {
		while (q.size() and i-q.front().se>n/2) q.ppf();
		ans=max(ans,a[i]+q.front().fi+i-1);
		int cur=a[i]-i+1;
		while (q.size() and cur>=q.back().fi) q.ppb();
		q.pb(mp(cur,i));	
	}
	cout<<ans<<endl;
	
	return 0;
}
