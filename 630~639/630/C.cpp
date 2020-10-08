#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,k; cin>>n>>k;
		string s; cin>>s;

		int m=n/k,ans=0;
		for (int l=0;l<(k+1)/2;l++) {
			int ar[26]={0};
			for (int i=l,j=k-1-l;i<n and j<n;i+=k,j+=k) {
				ar[s[i]-'a']++;
				if (i!=j) ar[s[j]-'a']++;
			}
			int ma=0,sum=0;
			for (int i=0;i<26;i++) sum+=ar[i],ma=max(ma,ar[i]);
			ans+=sum-ma;
		}
		cout<<ans<<endl;
	}
}

