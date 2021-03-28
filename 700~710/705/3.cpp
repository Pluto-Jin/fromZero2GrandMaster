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

const int N=1e5+1;
int a[N][26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,k; string s; cin>>n>>k>>s;
		if (n%k) {cout<<-1<<endl;continue;}
		for (int i=1;i<=n;i++) {
			for (int j=0;j<26;j++) a[i][j]=a[i-1][j];
			a[i][s[i-1]-'a']++;
		}		 
		for (int i=n;~i;i--) {
			int cnt=0;
			for (int j=0;j<26;j++) cnt+=(a[i][j]=(k-a[i][j]%k)%k);
			if (cnt<n-i) {
				if (s[i]=='z') continue;
				cout<<s.substr(0,i)<<(char)(s[i]+1);
				if (int &tmp=a[i][s[i]-'a'+1];--tmp==-1) tmp=k-1,cnt+=k;
				a[i][0]+=n-i-cnt;
				for (int j=0;j<26;j++) while (a[i][j]--) cout<<(char)(j+'a');
				cout<<endl; break;
			}
			if (cnt==n-i) {
				if (i==n) {cout<<s<<endl;break;}
				int ok=0;
				for (int j=s[i]-'a'+1;!ok and j<26;j++) if (a[i][j]) ok=j,a[i][j]--;
				if (!ok) continue;
				cout<<s.substr(0,i)<<(char)(ok+'a');
				for (int j=0;j<26;j++) while (a[i][j]--) cout<<(char)(j+'a');
				cout<<endl; break;
			}
		}
		for (int i=0;i<26;i++) a[0][i]=0;
	}
	
	return 0;
}
