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

int n,a[53],b[53],m;
vi cur,ans[53];

void solve(int i,int j) {
	int cnt[4]={0},res=0;
	vi tmp;
	for (int k=j+1;k<cur.size();k++) cnt[3]+=b[cur[k]]-a[cur[k]]+1,tmp.pb(cur[k]);
	for (int k=j;k<j+1;k++) cnt[2]+=b[cur[k]]-a[cur[k]]+1;
	for (int k=i;k<j;k++) cnt[1]+=b[cur[k]]-a[cur[k]]+1,tmp.pb(cur[k]);
	for (int k=0;k<i;k++) cnt[0]+=b[cur[k]]-a[cur[k]]+1,tmp.pb(cur[k]);
	a[cur[i]]=a[cur[j]];
	cur.resize(0);
	for (auto i:tmp) cur.pb(i);
	for (int k=0;k<4;k++) res+=!!cnt[k];
	ans[++m].pb(res);
	for (int k=0;k<4;k++) if (cnt[k]) ans[m].pb(cnt[k]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	int id=0,tmp=-1;
	for (int i=1;i<=n;i++) {
		int x; cin>>x;
		if (x!=tmp+1) cur.pb(++id),tmp=a[id]=b[id]=x;
		else b[id]++,tmp++;
	}
	for (int k=1;k<=n;k++) {
		for (int i=0;i<cur.size();i++) {
			for (int j=i+1;j<cur.size();j++) if (a[cur[i]]==b[cur[j]]+1) {
				solve(i,j);
				goto gg;
			}
		} 
gg:		if (cur.size()==1) break;
    }
	cout<<m<<endl;
	for (int i=1;i<=m;i++) {
		for (auto j:ans[i]) cout<<j<<' ';
		cout<<endl;
	}
	
	return 0;
}
