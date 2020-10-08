#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se first
#define endl '\n'
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin>>n;
	string s;
	cin>>s;
	int tmp=0;
	for (int i=0;s[i];i++) 
		if (s[i]=='(') tmp++;
		else tmp--;
	if (tmp) {cout<<-1<<endl;return 0;}

	int ans=0;
	for (int i=0;i<n;) {
		while (tmp>=0) if (s[i++]=='(') tmp++; else tmp--; 	
		if (i>n) break;
		int l=1;
		while (tmp<0) {if (s[i++]=='(') tmp++;else tmp--;l++;}
		ans+=l;
	}
	cout<<ans<<endl;
}
