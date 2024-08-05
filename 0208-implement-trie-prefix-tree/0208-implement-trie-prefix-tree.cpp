class Node{
    public:
    Node *tree[26];
    bool flag=false;

    bool hasword(char ch){
        if(tree[ch-'a'] == NULL){
            return true;
        }else{
            return false;
        }
    }
    
    void put(char ch,Node* temp1){
        tree[ch-'a']=temp1;
    }

    Node* move(char ch){
        return tree[ch-'a'];
    }

    void end(){
        flag = true;
    }

};
class Trie {
public:
    Node *root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
     Node *temp=root;
       for(int i=0;i<word.length();i++){
           if(temp->hasword(word[i])){
              temp->put(word[i],new Node());
           }
           temp=temp->move(word[i]);
       }
       temp->end();
    }
    
    bool search(string word) {
        Node *temp=root;
         for(int i=0;i<word.length();i++){
             if(temp->hasword(word[i])){
                return false;
             }
             temp=temp->move(word[i]);
         }
         
         return temp->flag;
         
    }
    
    bool startsWith(string prefix) {
        Node *temp=root;
         for(int i=0;i<prefix.length();i++){
             if(temp->hasword(prefix[i])){
                return false;
             }
             temp=temp->move(prefix[i]);
         }
         return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */