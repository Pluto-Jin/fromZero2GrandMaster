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
		int ar[9][9];
		for (int i=0;i<9;i++) {
			string s; cin>>s;
			for (int j=0;j<9;j++) ar[i][j]=s[j]-'0';
		}
		ar[0][0]=ar[1][0];
		ar[3][1]=ar[4][1];
		ar[6][2]=ar[7][2];
		ar[1][3]=ar[2][3];
		ar[4][4]=ar[5][4];
		ar[7][5]=ar[8][5];
		ar[2][6]=ar[0][6];
		ar[5][7]=ar[3][7];
		ar[8][8]=ar[6][8];
		for (int i=0;i<9;i++) {
			for (int j=0;j<9;j++) cout<<ar[i][j];
			cout<<endl;
		}
	}
}

