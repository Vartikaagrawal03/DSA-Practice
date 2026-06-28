class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        
        vector<int> visited(n, 0);      // 0 = not visited
        vector<int> time(n, 0);         // store visit time
        
        int ans = -1;
        int timer = 1;
        
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            
            int node = i;
            unordered_map<int, int> localTime; // node -> step
            
            while (node != -1 && !visited[node]) {
                visited[node] = 1;
                localTime[node] = timer++;
                node = edges[node];
                
                if (node != -1 && localTime.count(node)) {
                    ans = max(ans, timer - localTime[node]);
                    break;
                }
            }
        }
        
        return ans;
    }
};