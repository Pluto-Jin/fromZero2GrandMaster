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

#include<numeric>
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
		string a,b; cin>>a>>b;
		int n=a.size(),m=b.size();
		for (int i=1;i<=n;i++) if (n%i==0) {
			string tmp;
			for (int j=0;j<n/i;j++) tmp+=a.substr(0,i);
			if (tmp==a) {
				a=a.substr(0,i);
				break;
			}
		}
		for (int i=1;i<=m;i++) if (m%i==0) {
			string tmp;
			for (int j=0;j<m/i;j++) tmp+=b.substr(0,i);
			if (tmp==b) {
				b=b.substr(0,i);
				break;
			}
		}
		if (a!=b) cout<<-1<<endl;
		else {
			int x=a.size(),y=b.size();
			for (int i=0;i<lcm(n/x,m/y);i++) cout<<a;
			cout<<endl;
		}
	}
	
	return 0;
}
