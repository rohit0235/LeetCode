class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
           if (s1==s2) return true;
            int n =s1.size();
            int count=0;
            for (int i=0;i<n;i++) if (s1[i]!=s2[i]) count++;
             if (count>2) return false;
            char checkf='\0';
            char checks='\0';
           for (int i=0;i<n;i++){
                   
                   if (checkf=='\0' && s1[i]!=s2[i]){
                           checkf=s1[i];
                           checks=s2[i];
                   }
                   else if (s1[i]!=s2[i]){

                           if (s1[i]==checks && s2[i]==checkf){
                                return true;
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