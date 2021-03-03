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
int a[N],b[N],cnt[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		set<int> bb;
		int n,m; cin>>m>>n;
		for (int i=1;i<=m;i++) cin>>b[i],bb.insert(b[i]);
		int pp=lower_bound(b+1,b+m+1,0)-b;
		for (int i=1;i<=n;i++) cin>>a[i];
		int p=lower_bound(a+1,a+n+1,0)-a;


		for (int i=0;i<=n+1;i++) cnt[i]=0;
		for (int i=n;i>=p;i--) if (bb.count(a[i])) cnt[i]=1+cnt[i+1]; else cnt[i]=cnt[i+1];
		for (int i=1;i<p;i++) if (bb.count(a[i])) cnt[i]=1+cnt[i-1]; else cnt[i]=cnt[i-1];

		int ans=0,a1=0,a2=0;
		for (int i=1;i<p;i++) {
			int tmp=lower_bound(b+1,b+m+1,a[i])-b; if (tmp>=pp) chkmax(a1,cnt[i-1]);
			else chkmax(a1,cnt[i-1]+(upper_bound(a+1,a+n+1,min(0,a[i]+pp-tmp-1))-a-1)-i+1);
		}
		for (int i=n;i>=p;i--) {
			int tmp=upper_bound(b+1,b+m+1,a[i])-b-1; if (tmp<pp) chkmax(a2,cnt[i+1]);
			else chkmax(a2,cnt[i+1]+i+1-(lower_bound(a+1,a+n+1,max(0,a[i]+pp-tmp))-a));
		}
		cout<<a1+a2<<endl;
	}
	
	return 0;
}
