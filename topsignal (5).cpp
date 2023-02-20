#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> graph[N];
vector<vector<int>> cycles;
void dfs_cycle(int u, int p, int color[], int par[], int &cyclenumber)
{
    if (color[u] == 2)
    {
        return;
    }
    if (color[u] == 1)
    {
        vector<int> v;
        cyclenumber++;
        int cur = p;
        v.push_back(cur);
        while (cur != u)
        {
            cur = par[cur];
            v.push_back(cur);
        }
        cycles.push_back(v);
        return;
    }
    par[u] = p;
    color[u] = 1;
    for (int v : graph[u])
    {
        if (v == par[u])
        {
            continue;
        }
        dfs_cycle(v, u, color, par, cyclenumber);
    }
    color[u] = 2;
}
void addEdge(int u, int v)
{
    graph[u].push_back(v);
}
int solution(int &cyclenumber, map<int, string> p, string account, int k)
{
    for (int i = 0; i < cyclenumber; i++)
    {
        for (int x : cycles[i])
            if (p[x] == account && cycles[i].size() == k)
                return 1;
    }
    return 0;
}
void solve()
{
    map<string, pair<int, int>> cur;
    string from, to, ATM, time;
    int amount, num_transaction = 0;
    set<string> ans;
    vector<vector<string>> edge;
    long int total = 0;
    do
    {
        cin >> from;
        if (from == "#")
            break;
        else
        {
            cin >> to;
            cin >> amount;
            fflush(stdin);
            cin >> time;
            cin >> ATM;
            cur[from].first += amount;
            cur[to].second += amount;
            ans.insert(from);
            ans.insert(to);
            num_transaction++;
            total += amount;
            edge.push_back({from, to});
        }
    } while (from != "#");
    map<string, int> temp;
    map<int, string> p;
    int index = 0;
    for (auto i : ans)
    {
        p[index] = i;
        temp[i] = index++;
    }
    for (int i = 0; i < edge.size(); i++)
    {
        int u = temp[edge[i][0]];
        int v = temp[edge[i][1]];
        addEdge(u, v);
    }
    int color[N];
    int par[N];
    int cyclenumber = 0;
    dfs_cycle(1, 0, color, par, cyclenumber);
    string query;
    do
    {
        cin >> query;
        if (query == "#")
            break;
        else
        {
            if (query == "?number_transactions")
            {
                cout << num_transaction << endl;
            }
            else if (query == "?total_money_transaction")
            {
                cout << total << endl;
            }
            else if (query == "?list_sorted_accounts")
            {
                for (auto i : ans)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
            else if (query == "?total_money_transaction_from")
            {
                string account;
                cin >> account;
                cout << cur[account].first << endl;
            }
            else if (query == "?inspect_cycle")
            {
                string account;
                cin >> account;
                int k;
                cin >> k;
                cout << solution(cyclenumber, p, account, k) << endl;
            }
        }
    } while (query != "#");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}