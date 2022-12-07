/*
[Q]https://cses.fi/problemset/task/1722/
[AC]
[矩陣快速冪]
*/

/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>

/*using namespace*/
using namespace std;

#define st first
#define nd second
#define ll long long int
#define elif else if
#define O_O ios::sync_with_stdio(0), cin.tie(0)
#define m_p make_pair
#define pii pair<int, int>
#define p_b push_back
#define pp_b pop_back
#define N 100010

#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define DBG if(debug)
#define FIR first
#define SEC second
#define elif else if
#define wassomething() empty()==false
bool debug=0;
bool iofast=true;

PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
PII padd(PII a,PII b){
	return {a.FIR+b.FIR,a.SEC+b.SEC};
}


int const NN = 1e6 + 10;

int w[N], m[N], c[N], dp[NN];

int main(){
	if(!debug&&iofast){what_the_fuck;}
	int n, t;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> w[i] >> m[i] >> c[i];
	cin >> t;
	vector<int>ww, mm;
	ww.p_b(0);
	mm.p_b(0);
	for(int i = 1; i <= n; i++){
		int tl = 0;
		for(int j = 1; tl + j <= c[i] && j * w[i] <= t; j *= 2){
			tl += j;
			ww.p_b(j * w[i]);
			mm.p_b(j * m[i]);
		}
		tl = c[i] - tl;
		if(tl * w[i] <= t){
			ww.p_b(tl * w[i]);
			mm.p_b(tl * m[i]);
		}
	}
	for(int i = 1; i <= ww.size(); i++)
		for(int j = t; j >= ww[i]; j--){
			dp[j] = max(dp[j], dp[j - ww[i]] + mm[i]);
		}
	cout << dp[t] << '\n';
}