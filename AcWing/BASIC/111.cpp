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

const int N=5e4+1;
int ans[N],cnt;
struct node {
	int x,y,id;
	bool operator<(const node &tmp) const {
		return x==tmp.x?y<tmp.y:x<tmp.x;
	}
};
multiset<node> a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=1;i<=n;i++) {
		int x,y; cin>>x>>y;
		a.insert({x,y,i});
	}
	while (a.size()) {
		auto p=a.begin();
		cnt++;
		while (p!=a.end()) {
			auto [x,y,id]=*p;
			a.erase(p);
			ans[id]=cnt;
			p=a.lower_bound({y,(int)1e9,0});
		}
	}
	cout<<cnt<<endl;
	for (int i=1;i<=n;i++) cout<<ans[i]<<endl;
	
	return 0;
}
