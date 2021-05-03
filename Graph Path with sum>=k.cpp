
#include<bits/stdc++.h>
using namespace std;


class Graph{

  public:
   int V;
   list<pair<int,int>>*l;

   Graph(int V){
       this->V=V;
       l=new list<pair<int,int>> [V];
   }

   bool helper(int src,int k);

   bool helper_util(int src,int k,vector<bool>&path);

   void addEdge(int u,int v,int w);

};



void Graph::addEdge(int u,int v,int w){


     l[u].push_back({v,w});
     l[v].push_back({u,w});

     return;


}


bool Graph::helper_util(int src,int k,vector<bool>&path){


        if(k<=0){
            return true;
        }

        //traverse on adjacency list
        for(auto it=l[src].begin();it!=l[src].end();it++){

               int v=(*it).first;
               int w=(*it).second;

               if(path[v]){
                   continue;
               }

               if(w>=k){
                   return true;
               }
               path[v]=true;
               if(helper_util(v,k-w,path)){
                   return true;
               }
               path[v]=false;
        }

        return false;


}


bool Graph::helper(int src,int k){

      vector<bool> path(V,false);

      path[src]=true;

      return helper_util(src,k,path);
     
}


int main()
{
    int v=9;
    Graph g(v);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int src=0;

    int k=62;

    if(g.helper(src,k)){
        cout<<"Yes"<<endl;
    }

    else{
        cout<<"No"<<endl;
    }
    
    






}
