class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        else:
            minn = min(strs)
            maxn = max(strs)
            for i,element in enumerate(minn):
                if(element != maxn[i]):
                    return minn[:i]
            return minn
