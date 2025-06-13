class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

    
// int minLength = min(str1.length(), str2.length());

//         for (int i = minLength; i > 0; i--)
//         {
//             string candidate = str1.substr(0, i);
//             if (str1.size() % i == 0 && str2.size() % i == 0)
//             {
//                 string repeated1 = "", repeated2 = "";
//                 for (int j = 0; j < str1.size() / i; j++)
//                 {
//                     repeated1 += candidate;
//                 }
               
//                 for (int j = 0; j < str2.size() / i; j++)
//                 {
//                     repeated2 += candidate;
//                 }
//                 if (repeated1 == str1 && repeated2 == str2)
//                 {
//                     return candidate;
//                 }
//             }
//         }
//         return "";

       if (str2.length()> str1.length())
            return gcdOfStrings(str2,str1);

        if (str1 == str2)
            return str1;
        if (str2.size()==0)
            return str1;
        if (str1.size()==0)
            return str1;        

        if(str1.compare(0, str2.length(), str2) == 0){
            return gcdOfStrings(str1.substr(str2.length()), str2);
        } 

        return ""; //where no gcd possible.

            
    }
};