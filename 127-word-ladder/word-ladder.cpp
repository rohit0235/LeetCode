class Solution {
public:
    int ladderLength(string b, string e, vector<string>& wordList) {
        // note that we can change only one letter
        // and i have to find the shortest path 
          unordered_set<string>st(wordList.begin(),wordList.end());

          queue<string>q;
          q.push(b);
           int res =0;
          while (!q.empty()){
               res++;
                int n = q.size();
                for(int i=0;i<n;i++){
                      string front = q.front();
                      q.pop();
                      for(int j=0;j<front.size();j++){
                              char ch = front[j];
                               for(char c = 'a' ;c<='z';c++){
                                    front[j]= c;

                                    if (!st.count(front)){
                                          continue;
                                    }
                                    if (front==e) return res+1;
                                    st.erase(front);
                                    q.push(front);
                               }
                               front[j]= ch;
                      }

                } 

          }

          return 0;
    }
};