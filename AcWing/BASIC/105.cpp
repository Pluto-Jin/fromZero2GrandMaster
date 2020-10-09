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
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

const int N=1e5+1;
int cnt[2][N];
ll pre[N];

ll solve(int id,int n,int t) {
	if (t%n) return -1;
	for (int i=1;i<=n;i++) pre[i]=1ll*cnt[id][i]-t/n+pre[i-1];
	sort(pre+1,pre+n+1);
	ll res=0;
	for (int i=1;i<=n;i++) res+=abs(pre[n+1>>1]-pre[i]);
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m,t; cin>>n>>m>>t;
	for (int i=0;i<t;i++) {
		int x,y; cin>>x>>y;
		cnt[0][x]++,cnt[1][y]++;
	}
	ll a=solve(0,n,t),b=solve(1,m,t);
	if (a==-1 and b==-1) cout<<"impossible"<<endl;
	else if (a==-1) cout<<"column"<<' '<<b<<endl;
	else if (b==-1) cout<<"row"<<' '<<a<<endl;
	else cout<<"both"<<' '<<a+b<<endl;

	return 0;
}
