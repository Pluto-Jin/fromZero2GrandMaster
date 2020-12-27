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

int ans[501][501],a[501],id[250001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,m; cin>>n>>m;
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>a[j];
		for (int i=1;i<=m;i++) id[a[i]]=i;
		for (int j=1;j<=m;j++) {
			int pos;
			for (int i=1;i<=n;i++) {
				cin>>a[i];
				if (id[a[i]]) pos=id[a[i]],id[a[i]]=0;
			}
			for (int i=1;i<=n;i++) ans[i][pos]=a[i];
		}
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) cout<<ans[i][j]<<' ';
			cout<<endl;
		}
	}
	
	return 0;
}
