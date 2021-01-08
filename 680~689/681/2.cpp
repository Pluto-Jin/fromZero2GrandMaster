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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,m; cin>>n>>m;
		vi a(n+2),pre(n+2),nxt(n+2),id(n+2),in(n+2),b(m+1);
		for (int i=1;i<=n;i++) cin>>a[i],pre[i]=i-1,nxt[i]=i+1,id[a[i]]=i;
		for (int i=1;i<=m;i++) cin>>b[i],in[id[b[i]]]=1;
		in[0]=in[n+1]=1;
		int ok=1,ans=1,MOD=998244353;
		for (int i=1;ok and i<=m;i++) {
			int j=id[b[i]];
			if (!in[pre[j]] and !in[nxt[j]]) ans=ans*2%MOD;
			if (in[pre[j]] and in[nxt[j]]) ok=0;
			else if (in[pre[j]]) nxt[j]=nxt[nxt[j]],pre[nxt[j]]=j;
			else pre[j]=pre[pre[j]],nxt[pre[j]]=j;
			in[j]=0;
		}  
		cout<<(ok?ans:0)<<endl;
	}
	
	return 0;
}
