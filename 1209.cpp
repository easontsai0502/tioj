/*
[Q]https://tioj.ck.tp.edu.tw/problems/1209
[]
*/

/*include*/
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
#include<stack>
#include<cstring>
#include<unordered_map>

/*using namespace*/
using namespace std;

/*define type*/
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"

/*struct*/

/*fn宣告*/

/*num*/
bool debug=false;
bool iofast=true;
INT n,m;
vector<INT> tree[40000+1];
INT flag[40000+1];
/*fn定義*/
bool dfs(INT nw,INT ls,INT flagn){
	if(flag[nw]){
		if(flag[nw]==flagn)return true;
		else return false;
	}else{
		bool re=true;
		flag[nw]=flagn;
		for(INT i:tree[nw]){
			if(i==ls)continue;
			re=dfs(i,nw,3-flagn);
			if(re)continue;
			else break;
		}
		return re;
	}
}
/*main*/
int main(){
	if(!debug&&iofast)cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	while(cin>>n>>m){
		/*re:0*/
		for(INT i=0;i<=40000;i++){
			tree[i].clear();
			flag[i]=0;
		}
		/*CIN*/
		for(INT i=0;i<m;i++){
			INT a,b;
			cin>>a>>b;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		/*solve*/
		if(dfs(1,-1,1))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
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
