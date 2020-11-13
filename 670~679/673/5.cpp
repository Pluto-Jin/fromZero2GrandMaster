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

const int N=3e5+1;
int n,a[N],trie[N*30][2],ind;
ll cnt[30][2];
vi ch[N*30];

void insert(int tmp,int id) {
	int p=0;
	for (int i=29;~i;i--) {
		int &x=trie[p][tmp>>i&1];
		if (!x) x=++ind;
		p=x,ch[x].pb(id);
	}
}

void dfs(int at=0,int cur=29) {
	if (cur<0) return;
	int l=trie[at][0],r=trie[at][1],x=ch[l].size(),y=ch[r].size();
	ll sum=0;
	if (l and r) {
		int j=0;
		for (int i=0;i<x;i++) {
			while (j<y and ch[r][j]<ch[l][i]) j++;
			sum+=j;
		}
		cnt[cur][0]+=sum,cnt[cur][1]+=1ll*x*y-sum;
	}	
	if (l) dfs(l,cur-1);
	if (r) dfs(r,cur-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	for (int i=0;i<n;i++) {
		int x; cin>>x;
		insert(x,i);
	}
	dfs();
	ll ans=0,x=0;
	for (int i=0;i<30;i++) {
		if (cnt[i][0]<=cnt[i][1]) ans+=cnt[i][0];
		else ans+=cnt[i][1],x|=1<<i;
	}
	cout<<ans<<' '<<x<<endl;
	
	return 0;
}
