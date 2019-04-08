class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int a[10],i = 0;  //数据最大长度为10,定义a[10],
        while(N){         //获取N各位上的数字到数组a
            a[i++] = N % 10;
            N /= 10;
        }
        sort(a,a+i);      //采用next_permutation()进行全排列,调整为由小到大的初始序列
        do{
            int num = 0;  
            if(a[0] == 0) continue; //前导为0时跳过,注意不能return false,会结束函数
            else{
                for(int j = 0;j < i;j++){ //正序获取数组中的元素，保存为num
                    num = num*10+a[j];
                }
                if((num&num-1) == 0) return true; //对num进行判断，找到则返回true
            }
        }while(next_permutation(a,a+i));  //全排列函数
        return false; //只能在没找到结果时，即当前行,返回false;
    }
};
//判断一个数是否为2的幂:  (n&n-1) == 0 ? true : false;  //注意== 的优先级大于 &
//                     n&(n-1) == 0错误，先计算(n-1) == 0
//理解： 数值 二进制  数值-1 二进制
//       2     10    1      01        
//       4    100    3     011
//       8   1000    7    0111
//可见 ，当进行&(与)运算时, n&n-1) 必定等于 0
