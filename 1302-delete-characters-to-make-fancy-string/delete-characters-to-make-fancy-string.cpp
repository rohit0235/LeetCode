class Solution {
public:
    string makeFancyString(string s) {
          
            int n =s.size();

            for(int i=0;i<=n-3;i++){
                     int count =1;
                     for(int j=1;j<3;j++){
                            if (s[i]==s[i+j]){
                                 count++;
                            }
                           
                     }

                     if (count==3){
                         s[i]='#';
                     }
                  
            }

            string ans ="";
            for(char i:s){
                 if (i!='#')ans+=i;
            }
            return ans;

    }
};