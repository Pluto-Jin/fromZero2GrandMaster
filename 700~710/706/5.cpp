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

const int N=550;
int a[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,m; cin>>n>>m;
		for (int i=0;i<n;i++) {
			string s; cin>>s;
			for (int j=0;j<m;j++) {
				if (s[j]=='X') a[i][j]=1; else a[i][j]=0;
				if (i%3==0) a[i][j]++;
			}
		}
		for (int i=3;i<n;i+=3) {
			int ok=-1;
			for (int j=0;ok==-1 and j<m;j++) if (a[i-2][j]) ok=j;
			for (int j=0;ok==-1 and j<m;j++) if (a[i-1][j]) ok=j;
			if (ok==-1) ok=0;
			a[i-2][ok]=a[i-1][ok]=1;
		}
		if (n%3==0) for (int j=0;j<m;j++) if (a[n-1][j]) a[n-2][j]=1;
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) cout<<(a[i][j]?'X':'.');
			cout<<endl;
		}
	}
	
	return 0;
}
