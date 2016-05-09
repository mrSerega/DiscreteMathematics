#ifndef DIJKSTRA_H
#define DIJKSTRA_H

using namespace std;

#include <iostream>
#include <vector>


class Dijkstra
{
public:
    Dijkstra();
    int algo
    (
            int,
            int,
            int,
            vector< vector <pair <int,int> > >&,
            vector<int>&,
            int&
    );
};

#endif // DIJKSTRA_H
