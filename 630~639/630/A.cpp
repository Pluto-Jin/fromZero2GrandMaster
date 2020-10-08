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
		int a,b,c,d; cin>>a>>b>>c>>d;
		int x,y,x1,y1,x2,y2; cin>>x>>y>>x1>>y1>>x2>>y2;
		int q=x+b-a,w=y+d-c;
		if (x1==x2 and (a or b) or y1==y2 and (c or d) or q>x2 or q<x1 or w>y2 or w<y1) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}

