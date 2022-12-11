/*
[Q]https://tioj.ck.tp.edu.tw/problems/1084
[]
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

/*define type*/
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define DBG if(debug)
#define FIR first
#define SEC second
#define elif else if
#define ifif if
//#define CIN( nn ) DBG{cout<<"input:"<<endl;}cin >> nn ;
//#define COUT( nn ) DBG{cout<<"output:{";}cout << nn ; DBG{cout<<"}"<<endl;}
#define wassomething() empty()==false
/*struct宣告*/
struct mat;
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;
PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
const INT mxn=500;
INT tree[mxn+1][mxn+1];
INT linecount[mxn+1];
INT n;
deque<INT> lit;
INT al=0;
/*struct定義*/
struct mat{
	INT a[2][2];
	mat(){
		memset(a,0,sizeof(a));
	}
	mat operator*(const mat &b)const{
		mat re;
		for(INT i=0;i<2;i++){
			for(INT j=0;j<2;j++){
				for(INT k=0;k<2;k++){
					re.a[i][j]=(re.a[i][j]+a[i][k]*b.a[k][j])%mod;
				}
			}
		}
		return re;
	}
};
/*fn定義*/
PII padd(PII a,PII b){
	return {a.FIR+b.FIR,a.SEC+b.SEC};
}
bool INT_DFS(INT a){
	linecount[a]--;
	al--;
	lit.push_back(a);
	if(al==0){
		INT runcount=lit.size();
		while(runcount--){
			cout<<lit.front()<<endl;
			lit.pop_front();
		}
		cout<<endl;
		return true;
	}
	for(INT i=0;i<=n;i++){
		if(tree[a][i]){
			tree[a][i]--;
			tree[i][a]--;
			if(INT_DFS(i))return true;
			tree[a][i]++;
			tree[i][a]++;
		}
	}
	linecount[a]++;
	al++;
	lit.pop_back();
	return false;
}
/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	INT m;
	while(cin>>m){
		if(m==0)return 0;
		/*re:0*/
		INT st=1;
		al=m+1;
		memset(tree,0,sizeof(tree));
		memset(linecount,0,sizeof(linecount));
		lit.clear();
		/*CIN*/
		while(m--){
			INT x,y;
			cin>>x>>y;
			n=max(n,max(x,y));
			linecount[x]++;
			linecount[y]++;
			tree[x][y]++;
			tree[y][x]++;
			if(linecount[x]&1)st=x;
			if(linecount[y]&1)st=y;
		}
		/*solve*/
		INT_DFS(st);
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
