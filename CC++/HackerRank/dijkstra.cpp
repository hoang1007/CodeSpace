#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'shortestReach' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER s
 */

vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    #define _from [0] 
    #define _to [1] 
    #define _dist [2]
    #define INF -1
    
    vector<int> dist(n + 1, INF);
    vector<bool> picked(n + 1, false);

    dist[s] = 0;
    dist[0] = INT32_MAX;
    for (int c = 0; c < n - 1; c++) {
        int minVertex = 0;
        for (int i = 1; i <= n; i++)
            if (!picked[i] && dist[i] != INF && dist[i] < dist[minVertex])
                minVertex = i;
        picked[minVertex] = true;

        for (int i = 0; i < edges.size(); i++) {
            if (edges[i]_to == minVertex) swap(edges[i]_from, edges[i]_to);
            if (edges[i]_from == minVertex) {
                if (dist[edges[i]_to] == INF || dist[edges[i]_to] > dist[minVertex] + edges[i]_dist)
                    dist[edges[i]_to] = dist[minVertex] + edges[i]_dist;
            }
        }
    }
    dist.erase(dist.begin() + s);
    dist.erase(dist.begin());
    return dist;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = shortestReach(n, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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
