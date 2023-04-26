#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        map<int, vector<int>> m;
        for(int i = 0; i < n; i++){
            m[r[i]].push_back(i);
        }
        int calculate = 0;
        calculate = m.begin()->second.size();
        vector<int> ans(n, 0);

        for(int i = 0; i < m.begin()->second.size(); i++){
            ans[m.begin()->second[i]] = 1;
        }
        // for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        for(auto i = (++m.begin()); i != m.end(); i++){
            for(int j = 0; j < i->second.size(); j++){
                // cout << i->second[j] << " ";
                int left = 0, right = 0;
                if(i->second[j] - 1 >= 0 and r[i->second[j]] > r[i->second[j]-1]) left = ans[i->second[j] - 1] + 1;
                if(i->second[j] + 1 < n and r[i->second[j] > r[i->second[j] + 1]]) right = ans[i->second[j] + 1] + 1;
                ans[i->second[j]] = max({left, right, 1});
                calculate += ans[i->second[j]];
            } 
        }

        return calculate;
        // for(int i = 0; i < n; i++) cout << ans[i] << " ";
    }
};



int main(){
    vector<int> v = {1, 2, 2};
    Solution solution;
    solution.candy(v);
}