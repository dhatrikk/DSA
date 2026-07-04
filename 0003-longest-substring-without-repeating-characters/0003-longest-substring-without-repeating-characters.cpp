class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;

        int l=0, r=0;
        int n=s.size();

        vector<int> fre(128,-1);

        while(r<n){
            if(fre[s[r]]!=-1){
                if(fre[s[r]]>=l){
                    l=fre[s[r]]+1;
                }
            }
            fre[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};