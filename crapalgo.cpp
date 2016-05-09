#include "crapalgo.h"

CrapAlgo::CrapAlgo()
{
    gv=* new vector< vector< vector< pair<int,int> > > >;
}

int CrapAlgo::algo(int _startNode,int _endNode, vector< vector< pair<int,int> > >& g,int n)
{
    //in vars
    //int n; // len of graph
    startNode=_startNode;
    endNode=_endNode;

    //out vars
    int len; //len of shorter path
    vector<int> path; // shorter path

    //time vars

    //make a right graph

    //make a good graph
    makeGoodGraph(startNode,endNode,g,n);

    //algo

    len = f(startNode,0,path,6);

    cout<<len<<endl;
    for(size_t i=0;i<path.size();i++){
        cout<<path[i]<<"-";
    }

    //end algo

    //ending

    return 0;//endTime-startTime;
}

int CrapAlgo::f(int node,int iteration, vector<int>& path, int endNode)
{
    unsigned int m = INF;

    if (path.size()<iteration+1) path.push_back(node);

    for(size_t i=0;i<this->gv[iteration][node].size();i++){

        if(gv[iteration][node][i].first == endNode){
            //cout<<"!this is the end mu only friend\n";
            m = min(m,gv[iteration][node][i].second);
            path[iteration]=endNode;
            //cout<<"!"<<node<<"->"<<this->gv[iteration][node][i].first<<":"<<m<<"\n";//!
            continue;//TODO
        }

        //cout<<"!from "<<node<<" to "<<this->gv[iteration][node][i].first<<"\n";//!
        int oldm=m;

        m=min(m,this->gv[iteration][node][i].second+
              f(this->gv[iteration][node][i].first,iteration+1,path,endNode));

        if(m<oldm){
            path[iteration+1]=gv[iteration][node][i].first;
        }

        //cout<<"!"<<node<<"->"<<this->gv[iteration][node][i].first<<":"<<m<<"\n";//!
    }

    return m;
}

void CrapAlgo::makeGoodGraph(int startNode, int endNode,vector<vector<pair<int, int> > >& g, int n)
{
    vector<bool> t(n,false);
    gotonode(startNode,0,g,endNode,t);

   /* //test
    for(size_t i=0;i<gv.size();i++){
        for(size_t j=0;j<gv[i].size();j++){
            for(size_t l=0;l<gv[i][j].size();l++){
                cout<<gv[i][j][l].first<<" "<<gv[i][j][l].second<<"\n";
            }
            cout<<"--\n";
        }
        cout<<"----\n";
    }
    cout<<"--------\n";*/
}

void CrapAlgo::gotonode(int node, int iteration, vector<vector<pair<int, int> > >& graph, int endNode, vector<bool>& t)
{
    vector<vector<pair<int,int> > > tmpvector(0);
    vector< pair<int,int> > emptyvector(0);

    if(gv.size()<iteration+1){
        gv.push_back(tmpvector);
    }

    while(gv[iteration].size()<node+1){
        gv[iteration].push_back(emptyvector);
    }

    if(!t[node]){
        gv[iteration][node]=graph[node];
        t[node]=true;
    }

    for(size_t i=0;i<graph[node].size();i++){
        if (graph[node][i].first==endNode){
            continue;
        }
        gotonode(graph[node][i].first, iteration+1, graph, endNode, t);
    }
    return;
}

int CrapAlgo::min(int left, int right)
{
    if (left<=right) return left;
    return right;
}
