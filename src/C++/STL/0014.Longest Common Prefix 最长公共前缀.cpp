class Solution {    //最长公共前缀---STL
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int minn = 0x3f3f3f3f;
        for(auto i:strs){   //找到其中最短长度的string
            if(i.size() < minn) minn = i.size();
        }
        string com; //构造后为 ""
        for(int j = 0;j < minn;j++){
            vector<string>::iterator i = strs.begin();  
            char c = (*i)[j];
            while(i < strs.end()){  //遍历,判断是非具有相同的c 
                if(c == (*i)[j]) i++;
                else return com;    //字符不同,返回结果
            }
            com += c;   //累加前缀
        }
        return com;
    }
};
