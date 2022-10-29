/*
[Q]https://tioj.ck.tp.edu.tw/problems/1419
[Q]https://zerojudge.tw/ShowProblem?problemid=c230
[AC]
*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct treedata{
	int x;
	int y;
	int xy;
	int h;
};
struct treevs{
	bool operator()(treedata a,treedata b){
		return !((a.xy==b.xy)?:a.h>b.h,a.xy<b.xy);
	}
};
int main(){
	int n;
	while(cin>>n){
		priority_queue<treedata,vector<treedata>,treevs>treelist;
		for(int i=0;i<n;i++){
			treedata now;
			cin>>now.x>>now.y>>now.h;
			now.x=now.x*now.x;
			now.y=now.y*now.y;
			now.xy=now.x+now.y;
			treelist.push(now);
			
		}
		int ans=0,maxi=0;
		for(int i=0;i<n;i++){
			int now=(treelist.top()).h;
			treelist.pop();
			ans=max(ans,maxi-now);
			maxi=max(maxi,now);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
[I1]
5
3000 1000 50
8000 7000 100
0 0 100
3000 5000 300
10000 10000 150
[O1]
200
*/