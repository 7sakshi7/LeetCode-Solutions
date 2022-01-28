class TrieNode{
    public:
    vector<TrieNode*>children;
    bool isEnd;
    TrieNode(){
        this->children = vector<TrieNode*>(26,NULL);
        this->isEnd = false;
    }
};

class WordDictionary {
public:
    TrieNode *newNode = new TrieNode();
    WordDictionary() {
    }
    
    void addWord(string word) {
        TrieNode* temp = newNode;
        for(int i=0;i<word.size();i++){
            if(!temp->children[word[i]-'a'])
                temp->children[word[i]-'a'] = new TrieNode();
            temp = temp->children[word[i]-'a'];            
        }
        temp->isEnd = true;
    }
    
    bool searchNode(string word,TrieNode* root,int i){
        if(i == word.size()){
            return root->isEnd;
        }
        
        if(word[i] == '.'){
            for(int j = 0;j<26;j++){
                if(root->children[j]){
                    if(searchNode(word,root->children[j],i+1))
                    return true;
                }     
            }
        }
        else{
            if(root->children[word[i]-'a']){
                if(searchNode(word,root->children[word[i]-'a'],i+1))
                    return true;
            }
            else
                return false;
        }
        return false;
    }
    
    bool search(string word) {
         TrieNode* temp = newNode;
        return searchNode(word,temp,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
