class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> kinds(candies.begin(),candies.end());  //用set容器确定糖果的种数
        return min(kinds.size(),candies.size()/2);  
    }
};
//如果每种糖果都有重复，那么返回 candies.size()/2 即为可获得最大的种数
//如果妹妹无法获得最大的种数，因为糖果数量为偶数,那妹妹至少能获得set容器内有的所有种数
