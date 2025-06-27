#include<vector>
using namespace std;

class Solution {
    bool visited[510];

    void dfs(vector<int> graph[], vector<int>& quiet, int s, vector<int>& result) {
        visited[s] = true;

        for (int v : graph[s]) {
            if (!visited[v]) {
                dfs(graph, quiet, v, result);
            }

            if (quiet[v] < quiet[result[s]]) {
                result[s] = v;
            }

            if (quiet[result[v]] < quiet[result[s]]) {
                result[s] = result[v];
            }
        }
    }

public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<int> graph[510];
        vector<int> result;

        for (vector<int> e : richer) {
            graph[e[1]].push_back(e[0]);
        }

        for (size_t i = 0; i < quiet.size(); ++i) {
            visited[i] = false;
            result.push_back(i);
        }

        for (size_t i = 0; i < quiet.size(); ++i) {
            if (!visited[i]) {
                dfs(graph, quiet, i, result);
            }
        }

        return result;
    }
};