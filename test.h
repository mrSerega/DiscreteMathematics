#ifndef TEST_H
#define TEST_H

using namespace std;
#include <iostream>
#include <vector>

class Test
{
public:
    Test();
    void print( vector<int>);
    void testOfDijkstra(vector< vector< pair<int,int> > >);
};

#endif // TEST_H
