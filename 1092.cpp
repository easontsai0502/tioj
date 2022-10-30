/*
[Q]https://tioj.ck.tp.edu.tw/problems/1092
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
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
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
bool debug=false;
bool iofast=true;
INT n,e;
INT a,b;
vector<INT>tree[10000+1];
vector<INT>backtree[10000+1];
string fplay;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	while(cin>>n>>e){
		if(n==0||e==0)break;
		/*CIN*/
		for(INT i=0;i<=n;i++){
			tree[i].clear();
			backtree[i].clear();
		}
		for(INT i=0;i<e;i++){
			cin>>a>>b;
			tree[a].push_back(b);
			backtree[b].push_back(a);
		}
		cin>>fplay;
		
		/*solve*/
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
