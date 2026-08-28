#include <bits/stdc++.h>
using namespace std;
 
// Types
#define ll long long
#define ld long double
#define endl '\n'
 
// Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
 
// Shortcuts
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
 
 
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> edges(n, vector<int> ());
    for(int i=0; i<n-1; i++){
        int x;
        cin>>x;
        --x;
        edges[x].pb(i+1);
        edges[i+1].pb(x);
    }
 
    queue<int> q;
    q.push(0);
    vector<int> visited(n, 0);
    visited[0] = 1;
 
    int ans = 0;
 
    while(!q.empty()){
        int k = q.size();
        ans += (k%2);
        while(k--){
            int node = q.front();
            q.pop();
            for(auto x : edges[node]){
                if(visited[x] == 0){
                    visited[x] = 1;
                    q.push(x);
                }
            }
        }
    }
 
    cout<<ans<<endl;
    
 
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
 
    return 0;
}