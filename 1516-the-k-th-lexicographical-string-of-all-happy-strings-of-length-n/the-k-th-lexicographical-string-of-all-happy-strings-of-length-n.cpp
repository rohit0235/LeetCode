class Solution {
public:

    
    void solve (vector<string>&result,string &curr,int n){

                if (curr.size()==n) {
                      result.push_back(curr);
                    return ;
                }

                for (int i='a';i<='c';i++){
                        
               if (!curr.empty() && curr.back() == i) continue;

                        curr+=i;

                        solve(result,curr,n);  
                        
                        curr.pop_back();


                       
                } 
                 
              
    }
    string getHappyString(int n, int k) {
       
           vector<string>result;
           string curr="";
           
           solve(result,curr,n);

           if (result.size()<k) return "";
           else return  result[k-1];
     

    }
};