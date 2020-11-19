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

int n,w,a[18],ans=18,cur[19];

void dfs(int tot=1,int cat=0) {
	if (tot-1>ans) return;
	if (cat==n) ans=min(ans,tot-1);
	else {
		for (int i=0;i<tot;i++) if (cur[i]>=a[cat]) {
			cur[i]-=a[cat];
			if (i<tot-1) dfs(tot,cat+1);
			else dfs(tot+1,cat+1);
			cur[i]+=a[cat];
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>w;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<=n;i++) cur[i]=w;
	sort(a,a+n,greater<>());
	dfs();
	cout<<ans<<endl;
	
	return 0;
}
