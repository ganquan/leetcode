/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    
    func isSameTree(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        
        if nil ==  p && nil == q { 
            return true
        } else if let up = p, let uq = q {
           return (up.val == uq.val) && isSameTree(up.left, uq.left) && isSameTree(up.right, uq.right)
        } else {
           return false
       }
            
    }
}