class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
           if (s1==s2) return true;
            int n =s1.size();
            // int count=0;
            // for (int i=0;i<n;i++) if (s1[i]!=s2[i]) count++;
            //  if (count>2) return false;
            char checkf='\0';
            char checks='\0';
            int count=0;
           for (int i=0;i<n;i++){
                   
                   if (checkf=='\0' && s1[i]!=s2[i]){
                           if (count>0) return false;
                           checkf=s1[i];
                           checks=s2[i];
                   }
                   else if (s1[i]!=s2[i]){

                           if (s1[i]==checks && s2[i]==checkf){
                            count++;
                            checkf='\0';
                            
                           }         
                           else{
                            return false;
                           }
                   }


           }

           if (checkf=='\0' ) return true;
           return false;
    }
};