/*
 *  http://e-maxx.ru/algo/dijkstra
 *  https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%94%D0%B5%D0%B9%D0%BA%D1%81%D1%82%D1%80%D1%8B
*/

using namespace std;

#include "dijkstra.h"

#include <iostream>
#include <vector>
#include <ctime>

Dijkstra::Dijkstra()
{

}

int Dijkstra::algo
    (
        int numOfStartNode,
        int numOfEndNode,
        int numOfNode,
        vector< vector< pair<int,int> > >& inputVector,
        vector<int>& shorterPath,
        int& len
       ) //return timme
{
    //for time control
    int startTime;
    int endTime;

    const int INF = 1000000000;

    //in vars
    int n = numOfNode;
    vector < vector < pair<int,int> > > g = inputVector;
    int s = numOfStartNode;

    //out vars
    vector<int> d (n, INF),  p (n);
    d[s] = 0;
    vector<char> u (n);

    //algo
    startTime = clock();

    for (int i=0; i<n; ++i)
    {
        int v = -1;

        for (int j=0; j<n; ++j)
        {
            if (!u[j] && (v == -1 || d[j] < d[v]))
            {
                v = j;
            }
        }

        if (d[v] == INF)
        {
            break;
        }

        u[v] = true;

        for (size_t j=0; j<g[v].size(); ++j)
        {
            int to = g[v][j].first,
            len = g[v][j].second;

            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
            }

        }

    }

    endTime = clock();
    //end algo

    //calc of path
    vector<int> path; // shorter path to numOfEndNode from numOfStartNode
    for (int v=numOfEndNode; v!=s; v=p[v])
    {
        path.push_back (v);
    }

    path.push_back (s);
    //end calc

    //ending
    int shorterPathLen = d[numOfEndNode]; //len of shorter path

    shorterPath = path;
    len = shorterPathLen;

    return endTime-startTime;
}
