#include <iostream>                   //Hdu 2063 过山车 
#include <algorithm>                  //二分图匹配
#include <cstring>
using namespace std;

static int m,n;
static int line[501][501],boy[501],used[501];
//line数组标记可能的组合
//boy数组记录匹配的伴侣
//used数组作为标记,记录每一轮查找时,选择对象的占用情况---(在下方代码中代入题意理解)
//--->如果可能组合的used数组都被占用,表示无法成功匹配
bool find(int x){      //查找是否有男伴侣 
	int i;
	for(i = 1;i <= m;i++){  //查找每一名对象
		if(line[x][i] == 1 && used[i] == 0){    //存在没有被选择的可能伴侣
			used[i]=1;      //在这轮遍历中标记该名对象为伴侣
			if(boy[i] == 0 || find(boy[i])){ //若没有匹配,进行匹配，否则递归查找 是否 能够调换伴侣
				boy[i]=x;   //匹配成功
				return true;    
			}
		}
	}
	return false;   //一轮查找无法合理分配，那么匹配失败
}
int main()
{
	int t,a,b,i;
	while(cin>>t>>n>>m,t){
		memset(line,0,sizeof(line));
		memset(boy,0,sizeof(boy));
		memset(used,0,sizeof(used));
		for(i=0;i<t;i++){
			cin>>a>>b;
			line[a][b]=1;      //女a →选择→ 男b 
		}
		int sum=0;
		for(i = 1;i <= n;i++){
			memset(used,0,sizeof(used));    //对每一次查找，都要重置
            //每一轮查找都要根据情况递归查找每一名对象,该数组做查找时的访问标记
			if(find(i)) sum++;  //每一次寻找都进行重置
		}
		cout<<sum<<endl;
	}	
	return 0;
}
