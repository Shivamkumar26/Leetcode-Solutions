class Solution {
public:
    struct Trienode {
        bool is_end;
        string word;
        Trienode* child[26];
        
        Trienode() {
            is_end=false;
            word="";
            for(int i=0;i<26;i++) child[i]=NULL;
        }
    };
    
    Trienode *root=new Trienode();
    void insert(string &s) {
        Trienode* curr=root;
        int n=s.size();
        for(int i=0;i<n;i++) {
            int id=s[i]-'a';
            if(curr->child[id]==NULL)
                curr->child[id]=new Trienode();
            curr=curr->child[id];
        }
        curr->word=s;
        curr->is_end=true;
    }
    
    vector<string> res;
    vector<int> delrow={-1,0,1,0};
    vector<int> delcol={0,1,0,-1};
    void dfs(vector<vector<char>> &board,int i,int j,int n,int m,Trienode* curr) {
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='#') return;
        int idx=board[i][j]-'a';
        if(curr->child[idx]==NULL) return;
        curr=curr->child[idx];
        if(curr->is_end) {
            res.push_back(curr->word);
            curr->is_end=false;
        }
        char v=board[i][j];
        board[i][j]='#';
        for(int k=0;k<4;k++) {
            int rw=i+delrow[k];
            int cl=j+delcol[k];
            dfs(board,rw,cl,n,m,curr);
        }
        board[i][j]=v;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size();
        int m=board[0].size();
        for(auto it:words) insert(it);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                dfs(board,i,j,n,m,root);
        return res;
    }
};