/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
     Node* constructQuadTree(vector<vector<int>>& grid, int rs, int re, int cs, int ce) {
        if (rs > re || cs > ce) return NULL;
        
        bool isLeaf = true;
        int val = grid[rs][cs];
        for (int i = rs; i <= re; i++) {
            for (int j = cs; j <= ce; j++) {
                if (grid[i][j] != val) {
                    isLeaf = false;
                    break;
                }
            }
            if (!isLeaf) break;
        }
        
        if (isLeaf) return new Node(val, true);
        
        int rowMid = (rs + re) / 2;
        int colMid = (cs + ce) / 2;
        Node* topLeft = constructQuadTree(grid, rs, rowMid, cs, colMid);
        Node* topRight = constructQuadTree(grid, rs, rowMid, colMid+1, ce);
        Node* bottomLeft = constructQuadTree(grid, rowMid+1, re, cs, colMid);
        Node* bottomRight = constructQuadTree(grid, rowMid+1, re, colMid+1, ce);
         
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return constructQuadTree(grid, 0, n-1, 0, n-1);
    }
};

/*

Notice that you can assign the value of a node to True or False when isLeaf is False, and both are accepted in the answer.

*/