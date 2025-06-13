class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
         
             unordered_map<int,int>trust1;
             unordered_map<int,int>trust2;

             for(auto i:trust){
                 
                     int u =i[0];    int v =i[1];

                     trust1[u]++;
                     trust2[v]++;

             }

             for(int i=1;i<=n;i++){
                    
                    if (trust1[i]==0 && trust2[i]==n-1 ) return i;

             }

             return -1;



        //    vector<vector<int>>adj(n);

        //    for(auto i:trust){
        //               
        //               
               
        //              adju].push_back(v);
             
        //    }




    }
};