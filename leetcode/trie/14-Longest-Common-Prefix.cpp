class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        // for (int i = 1; i < strs.size(); i++) {
        //     while (strs[i].find(prefix) != 0) {
        //         prefix.pop_back();

        //         if (prefix.empty())
        //             return "";
        //     }
        // }

        // return prefix;
        for(int i=1;i<strs.size();i++){
            int j=0;
            while(j< min(prefix.length(),strs[i].length())){
                if(prefix[j]!=strs[i][j]){
                    break;
                }
                j++;
            }
            prefix=prefix.substr(0,j);
        }
        return prefix;

    }
};