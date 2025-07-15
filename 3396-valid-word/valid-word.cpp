class Solution {
public:
    bool isValid(string word) {
           
           int p=word.size();
           if (p<3) return false;
        
           bool c=0;
           bool v =0;
           for(char i:word){
                    
                    char n= tolower(i);
                    if (!isalnum(i)){
                         return false;
                    }
                    if (n=='a' || n=='e' || n=='i' || n=='o' || n=='u') {
                         v=true;
                    }
                    else if (!isdigit(n)){
                         c=true;
                    }


                    // if (v && c)return true;
               
           }

           return v&&c;
    }
};