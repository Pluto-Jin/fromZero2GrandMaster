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

int n,m;
vvi a;
vi b;

bool dfs(int cnt=2) {
	for (int i=2;i<=n;i++) {
		vi bad;
		for (int j=1;j<=m;j++) if (a[i][j]!=b[j]) bad.pb(j);
		if (bad.size()<=2) continue;
		if ((int)bad.size()-cnt>2 or !cnt) return false;
		else if (bad.size()==3) {
			for (auto pos:bad) {
				int tmp=b[pos];
				b[pos]=a[i][pos];
				if (dfs(cnt-1)) return true;
				b[pos]=tmp;
			}
		} else {
			for (auto x:bad) for (auto y:bad) if (x<y) {
				int t1=b[x],t2=b[y];
				b[x]=a[i][x],b[y]=a[i][y];
				if (dfs(cnt-2)) return true;
				b[x]=t1,b[y]=t2;
			}
		}
		return false;
	}
	return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	a=vvi(n+1,vi(m+1));
	b=vi(m+1);
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>a[i][j];
	for (int i=1;i<=m;i++) b[i]=a[1][i];
	if (!dfs()) cout<<"No"<<endl;
	else {
		cout<<"YES"<<endl;
		for (int i=1;i<=m;i++) cout<<b[i]<<' ';
		cout<<endl;
	}
	
	return 0;
}
