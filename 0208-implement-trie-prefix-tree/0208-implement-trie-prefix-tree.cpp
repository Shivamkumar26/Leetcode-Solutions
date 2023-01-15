struct Node{
    Node* links[26];
    bool flag = false;
    
    bool contains(char ch) { return (links[ch-'a'] != NULL); }
    void addlink(char ch, Node* node) { links[ch-'a'] = node; }
    Node* get(char ch) { return links[ch-'a']; }
    
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};

class Trie {
    Node* root;
public:
    Trie() { root = new Node(); }
    
    
    // all functions are almost same... think and code... 
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->contains(word[i]))
                node->addlink(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->contains(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.size(); i++) {
            if(!node->contains(prefix[i])) return false;
            node = node->get(prefix[i]);
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