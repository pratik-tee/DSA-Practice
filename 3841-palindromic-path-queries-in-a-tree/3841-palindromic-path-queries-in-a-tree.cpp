class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(n, vector<int>(LOG));
        vector<int> tin(n), tout(n), depth(n);
        int timer = 0;

        function<void(int,int)> dfs = [&](int u, int p) {
            tin[u] = ++timer;
            up[u][0] = p;

            for (int j = 1; j < LOG; j++)
                up[u][j] = up[up[u][j-1]][j-1];

            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
            tout[u] = timer;
        };
        dfs(0, 0);
        vector<int> bit(n + 2, 0);

        auto update = [&](int i, int val) {
            for (; i <= n; i += i & -i)
                bit[i] ^= val;
        };
        auto query = [&](int i) {
            int res = 0;
            for (; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        };

        for (int u = 0; u < n; u++) {
            int mask = 1 << (s[u] - 'a');
            update(tin[u], mask);
            update(tout[u] + 1, mask);
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int d = depth[u] - depth[v];
            for (int j = 0; j < LOG; j++)
                if (d & (1 << j))
                    u = up[u][j];

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[u][j] != up[v][j]) {
                    u = up[u][j];
                    v = up[v][j];
                }
            }

            return up[u][0];
        };
        vector<bool> ans;
        for (auto &q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int change = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));

                update(tin[u], change);
                update(tout[u] + 1, change);

                s[u] = c;
            } else {
                ss >> v;
                int w = lca(u, v);
                int mask = query(tin[u]) ^ query(tin[v]) ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};