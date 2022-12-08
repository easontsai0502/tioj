/*
[Q]https://tioj.ck.tp.edu.tw/problems/1092
[BFS]
[Topological sorting][DP]
[AC]
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
#include<cstring>

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
INT out[10000+1];
INT winner[10000+1];
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast){what_the_fuck;}
	while(cin>>n>>e){
		if(n==0&&e==0)return 0;
		/*re:0*/
		memset(out,0,sizeof(out));
		memset(winner,0,sizeof(winner));
		for(INT i=0;i<=n+1;i++){
			backtree[i].clear();
		}
		a=b=0;
		fplay.clear();
		/*CIN*/
		for(INT i=0;i<e;i++){
			cin>>a>>b;
			a--;
			b--;
			backtree[b].push_back(a);
			out[a]++;
		}
		cin>>fplay;
		/*solve*/

		//bfs
		//拓撲排序
		deque<INT>q;
		q.push_back(n-1);
		winner[n-1]=0;//數字為0，先的人贏
		//數字為1，後的人贏
		while(q.wassomething()){
			INT now=q.front();
			q.pop_front();
			for(INT i:backtree[now]){
				out[i]--;
				if(winner[now]==0)winner[i]=1;//如果now點為必贏，那採i的人必輸
				if(out[i]==0)q.push_back(i);//如果這裡是最後一次通往這，就把他列入代辦清單
			}
			if(debug){
				cout<<now<<":";
				for(INT i=0;i<n;i++){
					cout<<winner[i]<<" ";
				}
				cout<<endl;
			}
		}
		if(fplay=="Mimi")winner[0]^=1;
		if(winner[0])cout<<"Mimi"<<endl;
		else cout<<"Moumou"<<endl;
		//cout<<endl;
		if(debug){
			for(INT i=0;i<n;i++){
				cout<<winner[i]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

/*
[I1]
5 6
1 2
1 3
2 3
2 4
3 5
4 5
Mimi
0 0
[O1]
Moumou
[I2]
5 6
1 2
1 3
2 3
2 4
3 5
4 5
Moumou
0 0
[O2]
Mimi
[I3]
3 2
1 2
2 3
Moumou
2 1
1 2
Moumou
0 0
[O3]
Moumou
Mimi
*/

/*think*/
/*
dp[i]表該人贏or輸
*/
