// 敌兵布阵---根为0建立线段树
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
vector<int> nums;
vector<int> value;
//构建线段树 (对nums的6个元素，在区间[0,5]构造线段树)
//以下的 (lc + 1) 和 (rc + 1) 源于以0为根结点开始构造
inline int lc(int x){   //左孩子
    return x << 1;
}
inline int rc(int x){   //右孩子
    return x << 1|1;    //(x/2) + 1
}
inline int mid(int l,int r){    //分割点(父亲结点)
    return (l+r)>>1;
}
void build(int pos, int l, int r) {
    if (l == r) {
        value[pos] = nums[l];
        return;
    }
    build(lc(pos), l, mid(l,r));
    build(rc(pos), mid(l,r)+1, r);
    value[pos] = value[lc(pos)] + value[rc(pos)];
}
//线段树区间求和
int sum(int pos, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && qr >= r) return value[pos];
    return sum(lc(pos), l, mid(l,r), ql, qr)
         + sum(rc(pos), mid(l,r) + 1, r, ql, qr);
}
//更新线段树
void update(int pos, int l, int r, int index, int new_value) {
    if (l == r && l == index) {
        value[pos] += new_value;
        //if(value[pos] < 0) value[pos] = 0;
        return;
    }
    if (index <= mid(l,r)) {
        update(lc(pos), l, mid(l,r), index, new_value);
    }
    else {
        update(rc(pos), mid(l,r) + 1, r, index, new_value);
    }
    value[pos] = value[lc(pos)] + value[rc(pos)];
}

int main() {
    int t,n,cnt = 0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        n = n > 50000? 50000:n;
        nums.push_back(0);
        for(int i = 0;i < n;i++){
            int temp;
            scanf("%d",&temp);
            nums.push_back(temp);
        }
        for(int i = 0;i < n*4;i++) value.push_back(0);
        build(1,1,n); //构造线段树
        char s[10];
        int a,b;
        printf("Case %d:\n",++cnt);
        while(1){
            nums.clear();
            value.clear();
            scanf("%s",s);
            if(!strcmp(s,"Query")){
                scanf("%d%d",&a,&b);
                int ret = sum(1,1,n,a,b);
                printf("%d\n",ret);
            }else if(!strcmp(s,"Add")){
                scanf("%d%d",&a,&b);
                update(1,1,n,a,b);
            }else if(!strcmp(s,"Sub")){
                scanf("%d%d",&a,&b);
                update(1,1,n,a,-b);
            }else if(!strcmp(s,"End")){
                break;
            }
        }
    }
    return 0;
}
/* 敌兵布阵---根为1建线段树
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
vector<int> nums;
vector<int> value;
//构建线段树 (对nums的6个元素，在区间[0,5]构造线段树)
//以下的 (lc + 1) 和 (rc + 1) 源于以0为根结点开始构造
void build(int pos, int l, int r) {
    if (l == r) {
        value[pos] = nums[l];
        return;
    }
    int mid = (l+r)/2;
    build(pos<<1, l, mid);
    build(pos<<1|1, mid+1, r);
    value[pos] = value[pos<<1] + value[pos<<1|1];
}
//线段树区间求和
int sum(int pos, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && qr >= r) return value[pos];
    int mid = (l + r ) / 2;
    return sum(pos<<1, l, mid, ql, qr)
         + sum(pos<<1|1, mid + 1, r, ql, qr);
}
//更新线段树
void update(int pos, int l, int r, int index, int new_value) {
    if (l == r && l == index) {
        value[pos] += new_value;
        //if(value[pos] < 0) value[pos] = 0;
        return;
    }
    int mid = (l + r) / 2;
    if (index <= mid) {
        update(pos<<1, l, mid, index, new_value);
    }
    else {
        update(pos<<1|1, mid + 1, r, index, new_value);
    }
    value[pos] = value[pos<<1] + value[pos<<1|1];
}

int main() {
    int t,n,cnt = 0;
    scanf("%d",&t);
    while(t--){
        nums.clear();
        value.clear();
        scanf("%d",&n);
        n = n > 50000? 50000:n;
        nums.push_back(0);
        for(int i = 0;i < n;i++){
            int temp;
            scanf("%d",&temp);
            nums.push_back(temp);
        }
        for(int i = 0;i < n*4;i++) value.push_back(0);
        build(1,1,n); //构造线段树
        char s[10];
        int a,b;
        printf("Case %d:\n",++cnt);
        while(1){
            scanf("%s",s);
            if(!strcmp(s,"Query")){
                scanf("%d%d",&a,&b);
                int ret = sum(1,1,n,a,b);
                printf("%d\n",ret);
            }else if(!strcmp(s,"Add")){
                scanf("%d%d",&a,&b);
                update(1,1,n,a,b);
            }else if(!strcmp(s,"Sub")){
                scanf("%d%d",&a,&b);
                update(1,1,n,a,-b);
            }else if(!strcmp(s,"End")){
                break;
            }
        }
    }
    return 0;
}
*/
