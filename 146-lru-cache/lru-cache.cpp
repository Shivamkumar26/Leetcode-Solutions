class LRUCache {
    class Node {
        public:
        int key, val;
        Node* next, *prev;
        Node (int k, int v){
            key = k;
            val = v;
        }
    };

    unordered_map<int, Node*> mp;
    int size;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void insertAtHead(Node* node) {
        Node* t = head->next;
        head->next = node;
        node->next = t;
        node->prev = head;
        t->prev = node;
    }
    void deleteNode(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }
public:
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()) {
           Node* n = mp[key];
           deleteNode(n);
           insertAtHead(n);
           return n->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            mp[key]->val = value;
            Node* n = mp[key];
            deleteNode(n);
            insertAtHead(n);
        }
        else {
            if(size == mp.size()) {
                Node* n = tail->prev;
                deleteNode(n);
                mp.erase(n->key);
            }
            mp[key] = new Node(key, value);
            insertAtHead(mp[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */