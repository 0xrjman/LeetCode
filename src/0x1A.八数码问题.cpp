//A*+Hash判重
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int N = 1000000, HN = 1000003;
int head[HN], next[N];//链表（用于哈希）
int st[N][9], goal[9];
int dis[N];
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int Hash(int *st) {
    int v = 0;
    for(int i = 0; i < 9; i++)
        v = v*10 + st[i];//恰如其分得将9个数字映射成9位数
    return v % HN;//确保hash值不超过hash表大小
}

bool try_insert(int rear) {
    int h = Hash(st[rear]); //计算hash值
    int u = head[h];
    while(u) {
        if(!memcmp(st[u], st[rear], sizeof(st[0])))
            return 0;//重复，不挂，返回假
        u = next[u];
    }
    next[rear] = head[h];//rear指向旧的head[h]
    head[h] = rear;//rear成为新的head[h],如此一来，就把rear插到链表的头上了
    return 1;
}

int bfs() {
    memset(head, 0, sizeof(head));//初始化查找表，其实就是表头们
    int fron = 1, rear = 2; //局面下标
    while (fron < rear) {
        if (!memcmp(goal, st[fron], sizeof(st[0]))) //st[0]的长度为9,比较九个字节的内存单元
            return fron;//找到目标图
        int z;
        for(z = 0; z < 9; z++)
            if(!st[fron][z]) break;//找到白格,更新z为队首的白格
        int x = z / 3, y = z % 3;   //转换为[3,3]矩阵的坐标
        //0的下标为6,得到坐标(2,0)
        //2 6 4
        //1 3 7
        //0 5 8
        for(int d = 0; d < 4; d++){
            int nx = x + dx[d]; //下一状态坐标x
            int ny = y +dy[d];  //下一状态坐标y
            int nz = 3 *nx + ny;    //下一状态序列下标
            if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {//判断边界
                memcpy(&st[rear],&st[fron], sizeof(st[0]));
                //如果下一局面和当前局面不同
                st[rear][nz] = st[fron][z];
                st[rear][z] = st[fron][nz];
                //--->尝试移动,交换旧局面的 z和nz,得到新局面st[rear]
                dis[rear] = dis[fron] + 1;//累加距离
                if(try_insert(rear))//判重,若不重，则进队
                    rear++;
            }
        }
        fron++;//完成队首的尝试，队首出队。这个bfs和普通的bfs不太一样，st[][]其实就是队列，就是很多张图
    }
    return 0;
}

int main() {
    //freopen("test.in", "r", stdin);
    for(int i = 0; i < 9; i++) scanf("%d", &st[1][i]);  //输入初始局面
    for(int i = 0; i < 9; i++) scanf("%d", &goal[i]);   //输入目标局面
    int ans = bfs();
    if(ans > 0) printf("%d\n", dis[ans]);
    else puts("-1");
    fclose(stdin);
    return 0;
}
