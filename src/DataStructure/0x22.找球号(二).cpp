//找球号(二)----Hash_Table
//head数组是每个哈希值(hashcode/特征值)的链表头指针，next数组就是链表的next指针
//每个hashcode(key)存在一个链表,用next数组作索引指向具有相同key的元素
//head作为头指针,对每一个hashcode,存储它的头元素(此处采用最后进入链表的元素)
//hash表存储元素的原始数值,通过判断hash[head[key]] == m?即是否有相应哈希值的链表元素与m匹配
//得到哈希表中是否存在某个元素
#include<stdio.h>
#include<string.h>
const int N =1000002;
const int fib = 111123;
static int hash[N],head[N],next[N];
static int top;
//添加链表元素
void add(int m){
    int key = m % fib;      //球 m 对应的特征值
    next[top] = head[key];  //当前hashcode链表所含元素的索引数组  
    head[key] = top;        //记录当前hashcode链表的头元素为top
    hash[top] = m;          //记录当前输入元素的原始数值
    top++;                  //入表序号
}
//查询元素
bool query(int m){
    int key = m % fib;
    for(int i = head[key]; i > -1;i = next[i]){ //遍历具有同一key值的next表元素
        if(hash[i]==m) return true;
    }
    return false;
}
int main(){
    int n,m;
    int num;
    char s[6];
    scanf("%d",&n);
    memset(head,-1,sizeof(head));   //重置链表头指针为-1
    top = 0;//写在外面，只建立一个hash表
    while(n--){
        scanf("%s%d",s,&m);
        if(s[0]=='A'){
            for(int i=0;i<m;i++){
                scanf("%d",&num);
                add(num);
            }
        }
        else{
            for(int i=0;i<m;i++){
                scanf("%d",&num);
                if(query(num))
                printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}

