class TreeAncestor {
public:
    vector<vector<int>>p;
    //O(NlogN) processing time taken
    TreeAncestor(int n, vector<int>& parent) {
        p.resize(20,vector<int>(parent.size(),-1));
        //Direct parents(2^0)
        for(int i=0;i<parent.size();i++){
            p[0][i]=parent[i];
        }
        //2^i parents
        for(int i=1;i<20;i++){
            for(int node=0;node<parent.size();node++){
                int parent=p[i-1][node];
                //if parent exists then we need to do the recursive work
                if(parent!=-1) p[i][node]=p[i-1][parent];
            }   
        }
    }
    
    int getKthAncestor(int node, int k) {
        
        //20 cuz max jump can be of order 10^4 which is approx a 20 bit number in binary
        for(int i=0;i<20;i++){
            //find the bit
            if(k & 1<<i){
                node=p[i][node];
                if(node==-1)return -1;
            }
        }
        
        return node;
    }
};
