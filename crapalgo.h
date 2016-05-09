#ifndef CRAPALGO_H
#define CRAPALGO_H

#include <iostream>
#include <vector>

using namespace std;

class CrapAlgo
{
private:
    vector< vector< vector< pair<int,int> > > > gv; //good vector
    static const unsigned int INF = INT_MAX;
    int endNode;
    int startNode;

    int f(int node, int iteration, vector<int>& path, int endNode);

    void makeGoodGraph(int startNode, int endNode, vector< vector< pair<int,int> > >& g, int n);
    int min(int left,int right);

    void gotonode(int node, int iteration, vector< vector< pair<int,int> > >& graph, int endNode, vector<bool>& t);
public:
    CrapAlgo();
    int algo(int startNode, int endNode, vector<vector<pair<int,int> > >& g, int n);

};

#endif // CRAPALGO_H
