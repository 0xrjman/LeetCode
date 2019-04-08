class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B)
    {
        vector<int> res(A.size(),0);    
        vector<int> temp(A.size(), 0);  
        vector<int> C(B);           
        sort(A.begin(), A.end());   
        sort(C.begin(), C.end());
        int n = A.size();
        for (int i = 0,j=0,K=0; i < A.size(); i++,j++){
            if (A[i] <= C[j]){  
                temp[--n] = A[i];
                j--;    
            }
            else temp[K++] = A[i];  
        }
        for (int i = 0; i < A.size(); i++){ 
            for (int j = 0; j < A.size(); j++){ 
                if (B[i] == C[j]){  
                    res[i] = temp[j];   
                    C[j] = -1;  
                    break;  
                }
            }
        }
        return res; 
    }
};
/* 注释版本
class Solution {
    //思路：即田忌赛马(折腾了比较久,对所有语句进行了注释)
    //对每一次遍历，用最差的马匹配对方最好的马
    //因此需要升序排序两个序列，根据策略找出匹配序列
    //注意:因为返回的是 A 的任意排列，使其相对于 B 的优势最大化。
    //所以B的原始顺序是固定的，要排序需要拷贝B序列为C进行运算
    //当找到A对应B的优势序列Temp时
    //对Temp的优势项, Temp[i] > C[i];
    //此时要根据B的原始顺序，更新Temp序列为res
    //即对res的优势项, res[i] > B[i]
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B)
    {
        vector<int> res(A.size(),0);    //结果序列，保存依据原始序列的结果优势序列
        vector<int> temp(A.size(), 0);  //临时序列，保存排序后的优势序列
        vector<int> C(B);           //复刻B为C
        sort(A.begin(), A.end());   //升序排序 A和C
        sort(C.begin(), C.end());
        int n = A.size();
        for (int i = 0,j=0,K=0; i < A.size(); i++,j++){
            if (A[i] <= C[j]){  //如果为劣势项,以 坏vs好 ,自序列后 向前放 
                temp[--n] = A[i];
                j--;    //下一个元素继续匹配该项
            }
            else temp[K++] = A[i];  //如果为优势项，好vs稍坏，自序列前 向后放
        }
        for (int i = 0; i < A.size(); i++){ //A.size()只是代表元素数量,i此处为待填充的res下标
            for (int j = 0; j < A.size(); j++){ //j此处为原始序列的下标
                if (B[i] == C[j]){  //原始B的下标i == 排序后的下标j , 达成映射关系,那么
                    res[i] = temp[j];   //待填充下标元素 = 原始序列下标元素
                    C[j] = -1;  //标记为负数,表示访问过
                    break;  //找到对应下标,进行下一轮
                }
            }
        }
        return res; //返回的是对应的结果容器
    }
};
*/
