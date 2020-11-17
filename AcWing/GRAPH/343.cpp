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

int n,m;
bool g[26][26];

bool floyd() {
	for (int k=0;k<n;k++) {
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				if (g[i][k] and g[k][j]) g[i][j]=1;
				if (g[i][j] and g[j][i]) return false;
			}
		}
	}
	return true;
}

void topo() {
	int ans[26];
	for (int i=0;i<n;i++) {
		int cnt=0; for (int j=0;j<n;j++) cnt+=g[i][j];
		ans[cnt]=i;
	}
	for (int i=n-1;~i;i--) cout<<(char)('A'+ans[i]);
	cout<<'.'<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	while (1) {
		memset(g,0,sizeof g);
		cin>>n>>m;
		if (!n and !m) break;
		bool ok=0;
		for (int i=0;i<m;i++) {
			string s; cin>>s;
			if (ok) continue;
			int x=s[0]-'A',y=s[2]-'A';
			g[x][y]=1;
			if (!floyd()) {
				cout<<"Inconsistency found after "<<i+1<<" relations."<<endl;
				ok=1;
			} else {
				int sum=0;
				for (int j=0;j<n;j++) for (int k=0;k<n;k++) sum+=g[j][k];
				if (sum==n*(n-1)/2) {
					cout<<"Sorted sequence determined after "<<i+1<<" relations: "; topo(); 
					ok=1;
				}
			}
		}
		if (!ok) cout<<"Sorted sequence cannot be determined."<<endl;
	}

	return 0;
}
