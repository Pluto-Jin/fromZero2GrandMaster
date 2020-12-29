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

int cnt[1<<20];
bool vis[1<<20];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,k; string s; cin>>n>>k>>s;
		if (k<=20) {
			for (int i=0;i<=n-k;i++) {
				int msk=0;
				for (int j=i;j<i+k;j++) msk|=1-s[j]+'0'<<i+k-1-j;
				vis[msk]=1;
			}
			int ok=0;
			for (int i=0;i<1<<k;i++) if (!vis[i]) {
				ok=1;
				cout<<"YES"<<endl;
				for (int j=k-1;~j;j--) cout<<(i>>j&1); cout<<endl; 
				break;
			}
			if (!ok) cout<<"NO"<<endl;
			for (int i=0;i<=n-k;i++) {
				int msk=0;
				for (int j=i;j<i+k;j++) msk|=1-s[j]+'0'<<i+k-1-j;
				vis[msk]=0;
			}
		} else {
			for (int i=1;i<=n;i++) cnt[i]=cnt[i-1]+s[i-1]-'0';
			for (int i=0;i<=n-k;i++) if (cnt[i+k-20]-cnt[i]==k-20) {
				int msk=0;
				for (int j=i+k-20;j<i+k;j++) msk|=1-s[j]+'0'<<i+k-1-j;
				vis[msk]=1;
			}
			for (int i=0;i<1<<20;i++) if (!vis[i]) {
				cout<<"YES"<<endl;
				for (int j=0;j<k-20;j++) cout<<0; 
				for (int j=19;~j;j--) cout<<(i>>j&1); cout<<endl; 
				break;
			}
			for (int i=0;i<=n-k;i++) if (cnt[i+k-20]-cnt[i]==k-20) {
				int msk=0;
				for (int j=i+k-20;j<i+k;j++) msk|=1-s[j]+'0'<<i+k-1-j;
				vis[msk]=0;
			}
			for (int i=1;i<=n;i++) cnt[i]=0;
		}
	}
	
	return 0;
}
