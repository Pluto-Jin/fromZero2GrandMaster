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

	int a[3];
	ll INF=1e18,s[3]={0},m[3]={INF,INF,INF},ans=0;
	for (int i=0;i<3;i++) cin>>a[i];
	for (int i=0;i<3;i++) {
		for (int j=0;j<a[i];j++) {
			int x; cin>>x;
			ans+=x;
			s[i]+=x;
			chkmin(m[i],x);
		}
	}
	sort(s,s+3);
	sort(m,m+3);
	cout<<ans-2ll*min(s[0],m[0]+m[1])<<endl;

	
	return 0;
}
