#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    queue <int> vertices;
    vertices.push(s - 1);

    vector <int> dist;
    for (int i = 0; i < n; i++) {
        dist.push_back(-1);
    }

    dist[s - 1] = 0;
    while (!vertices.empty()) {
        int v = vertices.front();
        vertices.pop();

        for (int i = 0; i < edges[v].size(); i++) {
            if (dist[edges[v][i]] == -1) {
                vertices.push(edges[v][i]);
                dist[edges[v][i]] = dist[v] + 6;
            }
        }
    }

    vector <int> answ;

    for (int i = 0; i < n; i++) {
        if (dist[i] != 0) {
            answ.push_back(dist[i]);
        }
    }

    return answ;
}

int main() {
    int q;
    cin >> q;
    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n, m;
        cin >> n >> m;
        vector <vector <int> > edges(n);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            edges[a - 1].push_back(b - 1);
            edges[b - 1].push_back(a - 1);
        }
        int s;
        cin >> s;
        vector<int> result = bfs(n, m, edges, s);
        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }
    }
    return 0;
}