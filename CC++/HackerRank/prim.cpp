#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'prims' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER start
 */
struct Edge {
    int from, to, cost;
    Edge(vector<int> _edge) {
        from = _edge[0];
        to = _edge[1];
        cost = _edge[2];
    }
    bool operator > (const Edge &src) const {
        return cost > src.cost;
    }
};

int prims(int n, vector<vector<int>> edges, int start) {
    #define _from [0]
    #define _to [1]
    #define _cost [2]

    int minCosts = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge>> q;
    vector<bool> picked(n + 1, false);
    int currentVertex = start;
    for (int c = 0; c < n - 1; c++) {
        picked[currentVertex] = true;
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i]_to == currentVertex) swap(edges[i]_to, edges[i]_from);
            if (edges[i]_from == currentVertex) {
                q.push(Edge(edges[i]));
                edges.erase(edges.begin() + i);
                i--;
            }
        }
        
        while (picked[q.top().from] && picked[q.top().to])
            q.pop();
        currentVertex = q.top().to;
        minCosts += q.top().cost;
        q.pop();
    }
    return minCosts;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> edges(m);

    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    string start_temp;
    getline(cin, start_temp);

    int start = stoi(ltrim(rtrim(start_temp)));

    int result = prims(n, edges, start);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
