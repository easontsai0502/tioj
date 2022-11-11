/*
[Q]https://tioj.ck.tp.edu.tw/problems/1175
[AC]
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

/*struct*/

/*fn宣告*/

/*num*/

/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	/*CIN*/
	INT n;
	cin>>n;
	INT a[n+1];
	for(INT i=1;i<=n;i++){
		cin>>a[i];
	}
	INT dp[n+1];
	vector<INT> vec;
	dp[0]=0;
	vec.push_back(a[1]);
	INT l=1;
	for(INT i=1;i<=n;i++){
		if(a[i]>vec.back()){
			vec.push_back(a[i]);
			l++;
			dp[i]=l;
		}else{
			auto it=lower_bound(vec.begin(),vec.end(),a[i]);
			*it=a[i];
			dp[i]=(INT)(it-vec.begin()+1);
		}
	}
	cout<<l;
	/*solve*/
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
