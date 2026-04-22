#pragma GCC optimize("O3,unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN_SUM 300005
#define LOGN 19
#define MAX_ST_NODES 15000000

vector<int> adj[MAXN_SUM];
vector<int> node_colors[MAXN_SUM];
int parent[MAXN_SUM][LOGN], depth[MAXN_SUM];
int n, k, s, q;

struct Node {
    Node *l = nullptr, *r = nullptr;
    int lazy = 0;
};
Node node_pool[MAX_ST_NODES];
int node_idx;
Node* null_node;

Node* roots[MAXN_SUM];

void init_structures() {
    node_idx = 0;
    null_node = &node_pool[node_idx++];
    null_node->l = null_node->r = null_node;
    null_node->lazy = 0;
}

Node* update(Node* v, int tl, int tr, int l, int r, int add) {
    Node* new_v = &node_pool[node_idx++];
    *new_v = *v;
    
    if (l > r) return new_v;

    if (l == tl && r == tr) {
        new_v->lazy += add;
        return new_v;
    }

    int tm = tl + (tr - tl) / 2;

    if (new_v->lazy != 0) {
        Node* next_l = &node_pool[node_idx++]; *next_l = *new_v->l; next_l->lazy += new_v->lazy; new_v->l = next_l;
        Node* next_r = &node_pool[node_idx++]; *next_r = *new_v->r; next_r->lazy += new_v->lazy; new_v->r = next_r;
        new_v->lazy = 0;
    }
    
    new_v->l = update(new_v->l, tl, tm, l, min(r, tm), add);
    new_v->r = update(new_v->r, tm + 1, tr, max(l, tm + 1), r, add);
    
    return new_v;
}

int count_matches(Node* v1, Node* v2, Node* v3, Node* v4, int tl, int tr, int lz1, int lz2, int lz3, int lz4) {
    if (v1 == null_node && v2 == null_node && v3 == null_node && v4 == null_node) {
        return (lz1 == lz2 && lz2 == lz3 && lz3 == lz4) ? (tr - tl + 1) : 0;
    }

    int current_lz1 = lz1 + v1->lazy;
    int current_lz2 = lz2 + v2->lazy;
    int current_lz3 = lz3 + v3->lazy;
    int current_lz4 = lz4 + v4->lazy;
    
    if (tl == tr) {
        return (current_lz1 == current_lz2 && current_lz2 == current_lz3 && current_lz3 == current_lz4);
    }

    int tm = tl + (tr - tl) / 2;
    
    return count_matches(v1->l, v2->l, v3->l, v4->l, tl, tm, current_lz1, current_lz2, current_lz3, current_lz4) +
           count_matches(v1->r, v2->r, v3->r, v4->r, tm + 1, tr, current_lz1, current_lz2, current_lz3, current_lz4);
}

void dfs_lca(int u, int p, int d) {
    depth[u] = d;
    parent[u][0] = p;
    for (int v : adj[u]) {
        if (v != p) dfs_lca(v, u, d + 1);
    }
}

void dfs_pst(int u, int p) {
    roots[u] = update(roots[p], 1, k, 1, k, 1);
    for (int color : node_colors[u]) {
        roots[u] = update(roots[u], 1, k, color, color, -1);
    }
    for (int v : adj[u]) {
        if (v != p) dfs_pst(v, u);
    }
}

void build_lca_table(int root) {
    dfs_lca(root, 0, 0);
    for (int j = 1; j < LOGN; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (parent[i][j - 1] != 0) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int j = LOGN - 1; j >= 0; --j) {
        if (parent[u][j] != 0 && depth[u] - (1 << j) >= depth[v]) u = parent[u][j];
    }
    if (u == v) return u;
    for (int j = LOGN - 1; j >= 0; --j) {
        if (parent[u][j] != 0 && parent[u][j] != parent[v][j]) {
            u = parent[u][j]; v = parent[v][j];
        }
    }
    return parent[u][0];
}

void solve() {
    cin >> n >> k >> s >> q;
    init_structures();
    for (int i = 0; i <= n; ++i) {
        adj[i].clear(); node_colors[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for (int i = 0; i < s; ++i) {
        int v, x; cin >> v >> x;
        node_colors[v].push_back(x);
    }

    build_lca_table(1);
    roots[0] = null_node;
    dfs_pst(1, 0);

    for (int i = 0; i < q; ++i) {
        int u, v; cin >> u >> v;
        int lca = get_lca(u, v);
        int plca = parent[lca][0];
        cout << count_matches(roots[u], roots[v], roots[lca], roots[plca], 1, k, 0, 0, 0, 0) << (i == q - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}