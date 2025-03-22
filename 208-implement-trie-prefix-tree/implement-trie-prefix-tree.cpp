class Trie {
public:
     struct trienode {
         bool isendofword;
         trienode* children[26];
     };

     
      trienode *getnode (){
              trienode *newnode=new trienode();
              newnode ->isendofword=false;

              for(int i=0;i<26;i++){
                   newnode->children[i]=NULL;
              }

              return newnode;
      }
      trienode*   root;
    Trie() {
     root=getnode();
    }
    
    void insert(string word) {
           trienode *crawler=root;
          

           for(int i=0;i<word.length();i++){
                   char words=word[i];
                  int idx =words-'a';
                   
                  if (crawler->children[idx]==NULL){
                         crawler->children[idx]=getnode();
                  }
                crawler=crawler->children[idx];
           }
           crawler->isendofword=true;
                           
    }
    
    bool search(string word) {
             trienode *crawler=root;
          

           for(int i=0;i<word.length();i++){
                   char words=word[i];
                  int idx =words-'a';
                   
                  if (crawler->children[idx]==NULL){
                       return false;
                  }
                crawler=crawler->children[idx];
           }
           if (crawler!=NULL &&  crawler->isendofword==true){
                  return true;
           }
           return false;
                           
    }
    
    bool startsWith(string prefix) {
             trienode *crawler=root;
          
              int i=0;
           for(;i<prefix.length();i++){
                   char words=prefix[i];
                  int idx =words-'a';
                   
                  if (crawler->children[idx]==NULL){
                       return false;
                  }
                crawler=crawler->children[idx];
           }
           if (i==prefix.length()){
                  return true;
           }
           return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */