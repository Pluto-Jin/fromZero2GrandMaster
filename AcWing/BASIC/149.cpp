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

const int N=1e5+1;
int n,k;
ll dep,ans;
priority_queue<pll> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		ll x; cin>>x;
		pq.push(mp(-x,-1));
	}
	while ((pq.size()-1)%(k-1)) pq.push(mp(0,0));
	while (1) {
		ll sum=0,d=0;
		for (int i=0;i<k and pq.size();i++) {
			sum-=pq.top().fi;
			chkmin(d,pq.top().se);
			pq.pop();
		} 
		ans+=sum;
		chkmax(dep,-d);
		if (pq.empty()) break;
		pq.push(mp(-sum,d-1));
	}
	cout<<ans<<endl<<dep<<endl;
	
	return 0;
}
