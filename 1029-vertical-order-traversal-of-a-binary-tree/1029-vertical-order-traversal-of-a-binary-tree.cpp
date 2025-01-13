/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // base case
       
        
        
        //vertical,level,node
        map<int , map<int,multiset<int>>>nodes;
        
        //node,vertical,level
        queue<pair<TreeNode*,pair<int,int>>> todo;
        
        todo.push({root,{0,0}});     //push the root node
        
        while(!todo.empty()){
          auto it = todo.front();           
          todo.pop();
          TreeNode* node = it.first;  
          int x = it.second.first;          // x = vertical
          int y = it.second.second;   // y = level
          
            nodes[x][y].insert(node->val);
           if(node->left){
               todo.push({node->left,{x-1,y+1}});
           } 
           if(node->right){
               todo.push({node->right,{x+1,y+1}});
           }
            
        }
         vector<vector<int>>ans;
        
        for(auto p : nodes){  // VERTICAL
            vector<int>col;
            for(auto q : p.second){     // LEVEL
                col.insert(col.end(),q.second.begin(),q.second.end());
                
            }
            ans.push_back(col);
        }
        return ans;
        
    }
};