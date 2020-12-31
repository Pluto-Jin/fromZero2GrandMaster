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

const int N=1e5+1;
int a[N];
pii cnt[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		ll sum=0;
		for (int i=1;i<=n;i++) cin>>a[i],cnt[i]={a[i],0},sum+=a[i];
		for (int i=1;i<n;i++) {
			int x,y; cin>>x>>y;
			cnt[x].se++;
			cnt[y].se++;
		}
		sort(cnt+1,cnt+1+n,greater<>());
		cout<<sum<<' ';
		int cc=0;
		for (int i=1;i<=n and cc<n-2;i++) {
			while (cc<n-2 and --cnt[i].se) cout<<(sum+=cnt[i].fi)<<' ',cc++;
		}
		cout<<endl;
	}
	
	return 0;
}
