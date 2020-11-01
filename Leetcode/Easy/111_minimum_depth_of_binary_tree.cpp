/*******************************************************************
* https://leetcode.com/problems/minimum-depth-of-binary-tree/
* Easy
* 
* Conception: 
*  1. 
*
* Given a binary tree, find its minimum depth.
* The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*
* Note: A leaf is a node with no children.
*
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1.
*
*******************************************************************/
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
    void helper(TreeNode* root,int count,int &finalcount){
        if(root==NULL){
            finalcount=min(finalcount,count);
            return;
        }
        
        if(root->left==NULL and root->right==NULL){
            finalcount=min(finalcount,count+1);
            return;
        }
        
        if(root->left){
            helper(root->left,count+1,finalcount);
        }
        if(root->right){
            helper(root->right,count+1,finalcount);
        }
        return;
    }

    int minDepth(TreeNode* root) {
        
        int finalcount = INT_MAX;
        helper(root,0,finalcount);

        return finalcount;
    }
};