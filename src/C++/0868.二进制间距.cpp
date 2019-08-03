class Solution {
  public:
    int binaryGap(int N) {  //位运算
        int ret = 0;        //自右向左遍历整个二进制数
        while ((N & 1) == 0) N >>= 1;   //排除尾部所有0
        for (int dis = 0;N; N >>= 1)
            if (N & 1) {    //如果为1,寻找最大的间距ret
                ret = dis > ret ? dis : ret;
                dis = 1;    //找到当前段的间距，找下一段，重置dis为1
            }else dis++;    //没有遇到第二个的‘1’,间距++
        return ret;
    }
};
