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
		int n; cin>>n;
		string s; cin>>s;
		int od=0,ev=0;
		for (int i=0;i<n;i+=2) if ((s[i]-'0')%2) od=1;
		for (int i=1;i<n;i+=2) if ((s[i]-'0')%2==0) ev=1;
		if (n%2) cout<<(od?1:2)<<endl;
		else cout<<(ev?2:1)<<endl;
	}
}
