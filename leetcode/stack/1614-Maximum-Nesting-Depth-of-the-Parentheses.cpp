class Solution {
public:
    int maxDepth(string s) {
        int ans=0,maxi=0;
        for(char c:s){
            if(c=='('){
                ans++;
            }
            else if(c==')') ans--;

            maxi=max(ans,maxi);
        }
        return maxi;
        
    }
};