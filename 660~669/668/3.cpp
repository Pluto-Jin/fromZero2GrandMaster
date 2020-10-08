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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,k; cin>>n>>k;
		string s; cin>>s;
		int ok=1;
		for (int i=0;ok and i<k;i++) {
			int cur=0;
			for (int j=i;ok and j<n;j+=k) if (s[j]!='?') 
				if (cur and cur!=s[j]) ok=0;
				else cur=s[j];
			if (cur) s[i]=cur;
		}
		int a=0,b=0;
		for (int i=0;i<k;i++) if (s[i]=='1') a++; else if (s[i]=='0') b++;
		if (b>k/2 or a>k/2) ok=0;
		cout<<(ok?"YES":"NO")<<endl;
	}
}
