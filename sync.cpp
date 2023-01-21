#include <bits/stdc++.h>

using namespace std;

/* BFS Function to find all accessible states */
void bfs(long long num_nodes, vector<long long> q,
         vector<vector<long long>> adj, vector<bool> &visited)
{
    long long vis;
    while (!q.empty()) {
        vis = q[0];
        visited[vis] = true;

        q.erase(q.begin());

        for (long long i = 0; i < adj[vis].size(); i++) {
            long long neigh = adj[vis][i];
            if (!visited[neigh]) {
                q.push_back(neigh);
                visited[neigh] = true;
            }
        }
    }
}

/* Check if all elements in vector are equal */
bool all_equals(vector<long long> v)
{
    for (long long i = 0; i < v.size() - 1; i++) {
        if (v[i] != v[i + 1]) return false;
    }

    return true;
}

/* Check if vector of vectors contains a specific vector */
bool vector_contains_elem(vector<vector<long long>> v,
                          vector<long long> elem)
{
    for (auto c : v) {
        if (c == elem) return true;
    }

    return false;
}

/* Print a vector's elements */
void print_result(vector<long long> v)
{
    for (auto x : v) {
        cout << x << "\n";
    }
}

/* Copy src vector into dest vector */
void copy_vector(vector<long long> src, vector<long long> &dest)
{
    dest.clear();
    for (auto x : src) {
        dest.push_back(x);
    }
}

/* Count the maximum number of equal elements a vector has */
long long equal_elements(vector<long long> v)
{
    map<long long, long long> elements;
    for (auto x : v) {
        elements[x]++;
    }

    long long max = -1;
    map<long long, long long>::iterator it = elements.begin();
    while (it != elements.end())
    {
        if (it->second > max) max = it->second;
        ++it;
    }

    return max;
}

/* DFS function to find and print the synchronizing word */
bool dfs(vector<vector<long long>> &adj, vector<vector<long long>> x,
         long long num_nodes, long long num_symbols, vector<long long> seq)
{
    /* If all initial states reached
       the same final state, we found the sync word */
	if (all_equals(x[x.size() - 1])) {
        print_result(seq);
        return true;
    }

    /* Find the next best symbol */
    long long max_eq = -1;
    long long max_sym;
    vector<long long> max_v;
    for (long long i = 0; i < num_symbols; i++) {
        vector<long long> newv;
        newv.clear();
        for (auto w : x[x.size() - 1]) {
            newv.push_back(adj[w][i]);
        }

        if (!vector_contains_elem(x, newv)) {
            long long tmp = equal_elements(newv);
            if (tmp > max_eq) {
                max_eq = tmp;
                max_sym = i;
                copy_vector(newv, max_v);
            }
        }
    }

    /* Continue the DFS on the above chosen symbol */
    seq.push_back(max_sym);
    x.push_back(max_v);
    bool tmp = dfs(adj, x, num_nodes, num_symbols, seq);
    if (tmp) {
        return true;
    }
    x.pop_back();

    return false;
}

int main(int argc, char **argv)
{
    long long n, m, s;
    cin >> n >> m >> s;

    vector<vector<long long>> adj(n, vector<long long>(m));
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            cin >> adj[i][j];
        }
    }

    vector<long long> sources;
    if (s) {
        for (long long i = 0; i < s; i++) {
            long long tmp;
            cin >> tmp;
            sources.push_back(tmp);
        }
    } else {
        for (long long i = 0; i < n; i++) {
            sources.push_back(i);
        }
    }

    /* accessible task */
    if (!strcmp(argv[1], "accessible")) {
        vector<bool> visited(n, false);
        bfs(n, sources, adj, visited);
        for (long long i = 0; i < n; i++) {
            if (visited[i]) {
                cout << i << "\n";
            }
        }
    }

    /* sync task */
    if (!strcmp(argv[1], "synchronize")) {
        vector<long long> seq;

        /* the x variable represents the succession of states from
           the initial states to the final states (which are all equal) */
        vector<vector<long long>> x;
        x.push_back(sources);
        dfs(adj, x, n, m, seq);
    }
    
    return 0;
}
