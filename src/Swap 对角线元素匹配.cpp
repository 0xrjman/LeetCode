#include <iostream>
#include <cstring>
using namespace std;
const int N = 101;
static int n;
static int e[N],m[N][N],line[N][N];
static bool book[N];
bool find(int x){   //查找匹配
    int i;
    for(int i = 1;i <= n;i++){
        if(line[x][i] && !book[i]){
            book[i] = true;
            if(!e[i] || find(e[i])){
                e[i] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while(cin >> n){
        memset(m,0,sizeof (m));
        memset(line,0,sizeof (line));
        memset(e,0,sizeof (e));
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                int temp;
                cin >> temp;
                if(temp) line[i][j] = true; //建立可能匹配的关系
            }
        }
        int sum = 0;
        for(int i = 1;i <= n;i++){   //以交换行的思路进行尝试
            memset(book,0,sizeof(book));
            if(find(i)) sum++;
        }
        if(sum != n) cout << "-1" << endl;  //如果无法找到匹配,则返回-1
        else{   //否则输出路径
            int e1[N],e2[N];
            int cnt = 0;
            for(int i = 1;i <= n;i++) e1[e[i]] = i;
            memcpy(e2,e1,sizeof(e2));
            for(int i = 1;i <= n;i++){
                if(e1[i] != i){
                    for(int j = i+1;j <= n;j++){
                        if(e1[j] == i){
                            swap(e1[i],e1[j]);
                            cnt++;
                        }
                    }
                }
            }
            cout << cnt << endl;
            for(int i =1; i <= n;i++){
                if(e2[i] != i){
                    for(int j = i + 1;j <= n;j++){
                        if(e2[j]==i){
                            cout << "R " << i << " " << j << endl;
                            swap(e2[i],e2[j]);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
