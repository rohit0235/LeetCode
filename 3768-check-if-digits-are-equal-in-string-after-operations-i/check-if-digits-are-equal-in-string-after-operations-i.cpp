class Solution {
public: 
   
    // bool isssame(string &s ){   
            
    //        private  int n = s.size();
          
    //        for(int i=1;i<n;i++){
    //                if(s[i]!=s[i-1]) return false;
    //        }

    //        return true;

    // }
   
    bool hasSameDigits(string s) {
        int n = s.size();
        
              
        //    int count =0;///
        while (s.size()>2){
             
               string nr = "";
            // count++;//
               n = s.size();
               for(int i=1;i<n;i++){
                    int a = s[i]-'0';
                    int b = s[i-1]-'0';
                     int c = (a+b)%10;

                     nr.push_back(c+'0');  
               }
                //  cout<<s<<endl;
            //    if(count==3) break;
               
               s = nr;
        }

        return s[0]==s[1];

    }
};