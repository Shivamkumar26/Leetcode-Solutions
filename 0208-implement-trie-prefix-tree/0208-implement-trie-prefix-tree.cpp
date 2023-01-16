struct Node {
    Node* links[26];
    bool flag = false;
    
    bool contains(char ch) {
        return links[ch-'a']!=NULL;
    }
    void add(char ch, Node* node) {
        links[ch-'a'] = node; 
    }
    Node* get(char ch) {
        return links[ch-'a'];
    }
    void marktrue() {
        flag = true;
    }
    bool isEnd() {
        return flag == true;
    }  
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->contains(word[i])) {
                node->add(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->marktrue();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->contains(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->contains(word[i])) {
                return false;
            }
            node = node->get(word[i]);
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