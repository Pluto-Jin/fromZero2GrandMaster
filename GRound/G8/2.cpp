#include "bits/stdc++.h"
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

	ll n; cin>>n;
	string s="codeforces";
	int cnt[10];
	fill(cnt,cnt+10,1);
	int p=0;
	ll cur=1;
	while (cur<n) {
		cnt[p++]++;
		p%=10;
		cur=1;
		for (int i=0;i<10;i++) cur*=cnt[i];	
	}	
	for (int i=0;i<10;i++) for (int j=0;j<cnt[i];j++) cout<<s[i];
	cout<<endl;
	
}

