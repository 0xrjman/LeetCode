//Hdu3038.How Many Answers Are Wrong---带权并查集
#include <iostream>
using namespace std;
const int MAX = 200001;
static int bb[MAX],sum[MAX];
void make_set(int n){
    for(int i = 0;i <= n;i++){
        bb[i] = i;
        sum[i] = 0; 
    }
}
int find_set(int x){
    if(x != bb[x]){
        int t = bb[x];
        bb[x] = find_set(bb[x]);
        sum[x] += sum[t];   //更新结点信息
    }
    return bb[x];
}
int main()
{
    ios::sync_with_stdio(0);
    int n,m;
    while(cin >> n >> m){
        make_set(n);
        int cnt = 0;
        for(int i = 0;i < m;i++){
            int l,r,val;
            cin >> l >> r >> val;
            l--;    //将闭区间设为开区间
            int fl = find_set(l);
            int fr = find_set(r);
            //矛盾唯一情况为根结点相同但长度不同
            if(fl == fr && sum[l] - sum[r] != val) cnt++;   
            else{
                bb[fl] = fr;
                sum[fl] = -sum[l] + sum[r] + val;   //更新信息
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
