//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define vvi vector< vi >
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define mii map<Int,Int>
#define pb push_back
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	int n;
	cin>>n;
	vector<string> up;
	string ans = "";
	int add = 1;
	for(int i=1; i<=n/2; i++){
		ans = "";
		for(int j=1; j<=add; j++){
			ans += "D";
		}
		for(int j=1; j<=(n-add)/2; j++)	ans = "*"+ans;
		for(int j=1; j<=(n-add)/2; j++)	ans = ans + "*";
		add += 2;
		cout<<ans<<endl;
		up.pb(ans);
	}
	for(int i=1; i<=n; i++)	cout<<"D";
	cout<<endl;
	for(int i=n/2-1; i>=0; i--){
		cout<<up[i]<<endl;
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}