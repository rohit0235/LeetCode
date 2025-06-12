class Solution {
public:
        
    bool v(char i){
             if (i=='a' || i=='e' || i=='i' || i=='o' || i=='u') return true;

             return false;
        }
   
    int maxVowels(string s, int k) {
           
           int n =s.size();
            
           int vowels=0;
           
           for(int i=0;i<k;i++){
                if (v(s[i])==1) vowels++;
           }
           
           int maxi = vowels;
           for(int i=k;i<n;i++){
                  
               if (v(s[i])==1) vowels++;
               if (v(s[i-k]) )vowels--;

               maxi =max(maxi,vowels );
                 
           }


            return maxi;

    }
};