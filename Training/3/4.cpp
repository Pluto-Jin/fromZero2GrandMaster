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

const int N=5001;
int a[N],b[N],c[N],last[N];
vi edge[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m,k; cin>>n>>m>>k;
	for (int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
	for (int i=1;i<=n;i++) last[i]=i;
	for (int i=1;i<=m;i++) {
		int x,y; cin>>x>>y;
		chkmax(last[y],x);
	}
	for (int i=1;i<=n;i++) edge[last[i]].pb(i);
	priority_queue<int> s;
	for (int i=1;i<=n;i++) {
		while (k<a[i]) {
			if (s.empty()) {cout<<-1<<endl;return 0;}
			s.pop(); k++;
		}
		k+=b[i];
		for (auto to:edge[i]) {
			s.emplace(-c[to]);
			k--;
		}
	}
	while (k<0) {
		if (s.empty()) {cout<<-1<<endl;return 0;}
		s.pop(); k++;
	}
	int ans=0;
	while (s.size()) ans-=s.top(),s.pop();
	cout<<ans<<endl;
	
	return 0;
}
