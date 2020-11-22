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

int n,m,mx[]={1,0,-1,0,1,1,-1,-1},my[]={0,1,0,-1,1,-1,1,-1};
vvi g,pre,tmp,cur;

void add(int a,int b,int c,int d) {
	cur[a][b]++;
	cur[c+1][d+1]++;
	cur[c+1][b]--;
	cur[a][d+1]--;
}
bool check(int a) {
	for (auto &i:tmp) fill(i.begin(),i.end(),0);
	for (auto &i:cur) fill(i.begin(),i.end(),0);
	for (int i=a+1;i+a<=n;i++) for (int j=a+1;j+a<=m;j++) if (g[i][j])
		if (pre[i+a][j+a]+pre[i-a-1][j-a-1]-pre[i+a][j-a-1]-pre[i-a-1][j+a]==1ll*(2*a+1)*(2*a+1)) {
			tmp[i][j]=1;
			add(i-a,j-a,i+a,j+a);
		}
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cur[i][j]+=cur[i-1][j];
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cur[i][j]+=cur[i][j-1];
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (g[i][j] and !cur[i][j]) return false;
	return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	g.resize(n+2,vi(m+2));
	pre.resize(n+2,vi(m+2));
	tmp.resize(n+2,vi(m+2));
	cur.resize(n+2,vi(m+2));
	for (int i=1;i<=n;i++) {
		string s; cin>>s;
		for (int j=1;j<=m;j++) g[i][j]=pre[i][j]=s[j-1]=='X';
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) 
		pre[i][j]+=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];

	int lo=0,hi=1e6;
	while (lo<hi-1) {
		int mid=lo+hi>>1;
		if (check(mid)) lo=mid;
		else hi=mid;
	}
	cout<<lo<<endl;
	check(lo);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) cout<<(tmp[i][j]==1?'X':'.');
		cout<<endl;
	}
	
	return 0;
}
