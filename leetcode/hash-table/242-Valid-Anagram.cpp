class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        // unordered_map<char,int> counts;
        // unordered_map<char,int> countt;
        // for(int i=0;i<s.length();i++){
        //     counts[s[i]]++;
        //     countt[t[i]]++;
        // }
        // return counts==countt;
        vector<int> count(26,0);
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for(int x:count){
            if(x!=0){
                return false;
            }
        }
        return true;
    }
};