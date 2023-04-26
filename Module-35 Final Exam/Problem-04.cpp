#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int visited[105], d[105];
    vector<pair<int, int> > adj_list[105];

    void dijkstra(int src){
        d[src] = 0;
        priority_queue<pair<int, int> > pq;
        pq.push({0, src});

        while(!pq.empty()){
            pair<int, int> head = pq.top();
            pq.pop();

            int select_node = head.second;
            if(visited[select_node] == 1) continue;
            visited[select_node] = 1;

            for(auto edge_entry : adj_list[select_node]){
                int adj_node = edge_entry.first;
                int edge_cst = edge_entry.second;

                if(d[select_node] + edge_cst < d[adj_node]) {
                    d[adj_node] = d[select_node] + edge_cst;
                    pq.push({-d[adj_node], adj_node});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(int i = 0; i < 105; i++){
            visited[i] = 0;
            d[i] = 1e9;
        }

        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj_list[u].push_back({v, w});
        }

        dijkstra(k);

        if(*max_element(d+1, d+n+1) == 1e9) return -1;
        return *max_element(d+1, d+n+1);
    }
};

int main(){
    vector<vector<int> > v = {{1, 2, 1}, {2, 1, 3}};
    Solution solution;
    cout << solution.networkDelayTime(v, 2, 2);
}