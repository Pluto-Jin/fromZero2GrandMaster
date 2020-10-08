#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		unordered_set<int> st;
		vi ar(n);
		for (int i=0;i<n;i++) {
			cin>>ar[i];
			st.insert(ar[i]);
		}
		cout<<st.size()<<endl;
	}
}

