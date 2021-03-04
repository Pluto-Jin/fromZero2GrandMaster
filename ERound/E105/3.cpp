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

const int N=2e5+5;
int aa[N],bb[N],a[N],b[N],cnt[N];

int solve(int n,int m) {
	reverse(a+1,a+n+1);
	reverse(b+1,b+m+1);
	set<int> s;
	for (int i=1;i<=n;i++) s.insert(a[i]);
	cnt[m+1]=0;
	for (int i=m;i;i--) cnt[i]=cnt[i+1]+s.count(b[i]);
	int ans=0;
	for (int i=1;i<=m;i++) {
		int tmp=upper_bound(a+1,a+n+1,b[i])-a-1,ttmp=lower_bound(b+1,b+m+1,b[i]-tmp+1)-b;
		chkmax(ans,i-ttmp+1+cnt[i+1]);
	}
	return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,m; cin>>n>>m;
		for (int i=1;i<=n;i++) cin>>aa[i];
		for (int i=1;i<=m;i++) cin>>bb[i];

		int nn=0,mm=0;
		for (int i=1;i<=n and aa[i]<0;i++) a[++nn]=-aa[i];
		for (int i=1;i<=m and bb[i]<0;i++) b[++mm]=-bb[i];
		int ans=solve(nn,mm);
		nn=mm=0;
		for (int i=n;i and aa[i]>0;i--) a[++nn]=aa[i];
		for (int i=m;i and bb[i]>0;i--) b[++mm]=bb[i];
		cout<<ans+solve(nn,mm)<<endl;
	}
	
	return 0;
}
