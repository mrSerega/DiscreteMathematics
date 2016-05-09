#include "test.h"

#include "dijkstra.h"
#include "crapalgo.h"

#include <fstream>
#include <iostream>

Test::Test()
{
    //in stream
    ifstream input;
    input.open("input.txt");

    //in vars
    int testLen = 0;
    int n = 0;
    input>>n>>testLen;
    vector< vector< pair<int,int> > > testVector(testLen);

    //reading
    for(int i=0;i<n;i++){
        int leftNode, rightNode, len;
        input>>leftNode>>rightNode>>len;
        testVector[leftNode].push_back(make_pair(rightNode,len));
    }

    //testing
        //testOfDijkstra(testVector);
    CrapAlgo* crapAlgo = new CrapAlgo();
    crapAlgo->algo(0,6,testVector,testLen);


}

void Test::print(vector<int> vec)
{
    for(unsigned int i=0;i<vec.size()-1;i++){
        cout<<vec[i]<<"-";
    }
    cout<<vec.back();
}

void Test::testOfDijkstra(vector< vector< pair<int,int> > > testVector)
{
    //out vars
    int outputLen;
    vector<int> outputPath;
    int time;

    //
    Dijkstra* dijkstra = new Dijkstra();
    time = dijkstra->algo(0,testVector.size()-1,testVector.size(), testVector, outputPath, outputLen);

    cout<<"Dijkstra: "<<time<<"ms "<<"result is "<<outputLen<<": ";
    print(outputPath);
}
