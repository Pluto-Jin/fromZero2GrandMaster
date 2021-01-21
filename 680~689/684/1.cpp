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

const int N=101;
int n,m;
bool a[N][N];

struct node {
	int v[6];
};
vector<node> ans;

void emp(int a1,int a2,int a3,int a4,int a5,int a6) {
	ans.pb({a1,a2,a3,a4,a5,a6});
	a[a1][a2]^=1,a[a3][a4]^=1,a[a5][a6]^=1;
}
int cnt() {
	return a[n-1][m-1]+a[n-1][m]+a[n][m-1]+a[n][m];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		ans.resize(0);
		cin>>n>>m;
		for (int i=1;i<=n;i++) {
			string s; cin>>s;
			for (int j=0;j<m;j++) a[i][j+1]=s[j]=='1';
		}
		for (int i=1;i<n-1;i++) for (int j=1;j<=m;j++) if (a[i][j]) {
			if (j==m) emp(i,j,i+1,j,i+1,j-1);
			else emp(i,j,i+1,j,i+1,j+1);
		}
		for (int j=1;j<m-1;j++) if (a[n-1][j] or a[n][j]) {
			if (a[n-1][j] and a[n][j]) emp(n-1,j,n,j,n-1,j+1);
			else if (a[n-1][j]) emp(n-1,j,n-1,j+1,n,j+1);
			else emp(n,j,n-1,j+1,n,j+1);
		} 
		if (cnt()==4) emp(n-1,m-1,n-1,m,n,m-1);
		if (cnt()==2) {
			if (a[n-1][m-1] and !a[n][m]) emp(n-1,m-1,n-1,m,n,m-1);
			else if (!a[n-1][m-1] and a[n][m]) emp(n-1,m,n,m-1,n,m);
		}
		if (cnt()==1) {
			if (a[n-1][m-1]) emp(n-1,m-1,n-1,m,n,m-1);
			else if (a[n-1][m]) emp(n-1,m-1,n-1,m,n,m);
			else if (a[n][m-1]) emp(n-1,m-1,n,m-1,n,m);
			else emp(n-1,m,n,m-1,n,m);
		}
		if (cnt()==2) {
			if (a[n-1][m-1] and a[n][m]) emp(n-1,m-1,n-1,m,n,m-1);
			else if (a[n-1][m] and a[n][m-1]) emp(n-1,m-1,n-1,m,n,m);
		}
		if (cnt()==3) {
			if (!a[n-1][m-1]) emp(n-1,m,n,m-1,n,m);
			else if (!a[n-1][m]) emp(n-1,m-1,n,m-1,n,m);
			else if (!a[n][m-1]) emp(n-1,m-1,n-1,m,n,m);
			else emp(n-1,m-1,n-1,m,n,m-1);
		}
		cout<<ans.size()<<endl;
		for (auto i:ans) {
			for (auto j:i.v) cout<<j<<' ';
			cout<<endl;
		}
	}
	
	return 0;
}
