/*
[zj]			[Q]https://zerojudge.tw/ShowProblem?problemid= [題目編號]
[tioj]		[Q]https://tioj.ck.tp.edu.tw/problems/ [題目編號]
[cses]		[Q]https://cses.fi/problemset/task/ [題目編號]
[vjudge]	[Q]https://vjudge.net/problem/ [題目編號]
[]
*/

/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>

/*using namespace*/
using namespace std;

/*define type*/
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT ULLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define FIR first
#define SEC second
#define DBG if(debug)
#define ifif if
#define elif else if
#define wassomething() empty()==false

/*struct*/
struct super_pair{
	INT x1=0;
	INT x2=0;
	INT x3=0;
	INT x4=0;
	INT x5=0;
};
/*fn宣告*/
/*num*/
bool debug=1;
bool iofast=true;
//PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
//INT mx[]={0,1,0,-1};
//INT my[]={1,0,-1,0};
INT dp[90+1];
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	INT n,m;
	cin>>n>>m;
	/*solve*/
	dp[0]=1;
	for(INT i=1;i<=m;i++){
		if(i<=n){
			dp[i]=dp[i-1]*2;
		}else{
			dp[i]=dp[i-1]*2-dp[i-n-1]+dp[i-n-2];
		}
	}
	cout<<dp[m]<<endl;
	DBG{
		for(INT i=1;i<=m;i++)cerr<<dp[i]<<" ";
		cerr<<endl;
	}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
