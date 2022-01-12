// graphDistances.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> g, int s)
{
    int sz = g.size();
    for (int i = 0; i < sz; i++)
        g[i][i] = 0;

    vector<int> tovisit;
    vector<int> sol(g[s].begin(), g[s].end());
    for (int i = 0; i < sz; i++) {
        if (sol[i] == -1)
            sol[i] = INT_MAX;
        else
            tovisit.push_back(i);
    }
    //vector<int> root(sol.begin(), sol.end());
    
    while (!tovisit.empty()) {
        int indx = tovisit.front();
        tovisit.erase(tovisit.begin());
        if (indx == s) 
            continue;
        int curRoot = sol[indx];
        if (curRoot == INT_MAX) 
            continue;
        vector<int> cur = g[indx];
        for (int j = 0; j < sz; j++) {
            if (cur[j] == -1 || indx == j) continue;
            if (sol[j] > cur[j] + curRoot) {
                sol[j] = cur[j] + curRoot;
                tovisit.push_back(j);
            }
        }
        cout << indx << " " << curRoot << "=";
        for (auto x : sol)
            cout << x << " ";
        cout << endl;
    }
    return sol;
}


int main()
{
    vector<vector<int>> gg = { 
        {-1, -1, 19, 8, 18, -1, -1, -1, -1, -1} ,
        { 10, 6, 4, 7, 0, 10, 18, -1, 0, -1 },
        { -1, -1, 15, -1, 17, 3, -1, 14, 16, 3 },
        { 4, 19, 3, 15, 8, 4, 6, 11, 5, 8 },
        { 5, 3, 10, -1, 0, 14, 15, 1, 16, 5 },
        { -1, 8, -1, -1, 5, -1, 5, 0, 1, -1 },
        { -1, 18, -1, 19, 2, -1, 10, -1, 8, 6 },
        { 14, 8, 12, 16, -1, -1, 0, 16, 15, 17 },
        { 4, 5, 1, 12, 0, 4, 8, 15, 1, -1 },
        { 13, 7, 17, -1, 4, 13, 16, 3, 12, 9 }};
    vector<int> ret = solution(gg, 8);
    for (auto x : ret)
        cout << x << ", ";
    cout << endl;
    std::cout << "Hello World!\n";
}
