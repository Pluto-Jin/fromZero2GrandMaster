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

int phi[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	for (int i=1;i<=1000;i++) phi[i]=i;
	for (int i=2;i<=1000;i++) if (phi[i]==i)
		for (int j=i;j<=1000;j+=i) phi[j]=phi[j]/i*(i-1);
	for (int i=1;i<=1000;i++) phi[i]+=phi[i-1];

	for (int tc=1;tc<=t;tc++) {
		int n; cin>>n;
		cout<<tc<<' '<<n<<' '<<1+phi[n]*2<<endl;		
	}
	
	return 0;
}
