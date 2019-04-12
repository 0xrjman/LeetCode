class Solution
{
    public:
        vector<int> addToArrayForm(vector<int>& A, int K)
        {
            vector<int> B;
            while(K){
                B.push_back(K%10);
                K/=10;
            }
            int m = max(A.size(),B.size());
            int n = min(A.size(),B.size());
            reverse(A.begin(),A.end());
            vector<int> ret(m+1);
            //多定义一位,防止两数相加导致溢出
            for(int i = 0;i < m;i ++){
                if(i < n) ret[i] = A[i]+B[i];
                else if(A.size()>B.size())
                    ret[i] = 0 +A[i];
                else
                    ret[i] = 0+B[i];
             }
             for(int i = 0 ;i < ret.size();i ++){
                 if(ret[i]>=10){    
                     ret[i] -= 10;
                     ret[i+1] ++;
                 }
             }
             if(ret[ret.size()-1]==0) ret.pop_back();   //去除前导0
             reverse(ret.begin(),ret.end());
             return ret;
         }
 };
