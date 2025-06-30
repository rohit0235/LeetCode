class Solution {
public:
    string digitSum(string s, int k) {
                  
                string check =s;

                while (check.length()>k){
                      
                      string s ="";
                      int number =0;
                      int n =check.size();
                      for(int i=0;i<n;i++){
                        //    cout<<number<<" ";  
                                  number+=(check[i]-'0');
                             if ((i+1)%k==0){
                                 s+=to_string(number);
                                 number=0;
                            }

                         
                      
                       
                              
                      } 

                      if (n%k!=0){
                                 s+=to_string(number);
                      }
                        //  cout<<endl;
                      check=s;
                }

                return check;

    }
};