/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var cursor1 = l1
        var cursor2 = l2
        
        var result:ListNode?
        var result_cursor: ListNode?
        
        //进位
        var upgrade_digit: Int = 0
        
        while cursor1 != nil && cursor2 != nil {
            
            var curr_digit_sum: Int = 0
            let unwrap_val1: Int = cursor1?.val ?? 0
            let unwrap_val2: Int = cursor2?.val ?? 0
            
            //计算当前digit和进位的digit
            curr_digit_sum = unwrap_val1 + unwrap_val2 + upgrade_digit
            let curr_digit = curr_digit_sum % 10
            upgrade_digit = curr_digit_sum / 10
            
            if let _ = result {
                let new_digit = ListNode(curr_digit)
                result_cursor?.next = new_digit
                result_cursor = new_digit
            } else {
                result = ListNode(curr_digit)
                result_cursor = result
            }

            //处理链表不同长度的情况
            if nil == cursor1?.next && nil != cursor2?.next {
                //一长一短，短的用0值继续参与计算
                cursor1 = ListNode(0)
                cursor2 = cursor2?.next
            } else if nil == cursor2?.next && nil != cursor1?.next {
                //一长一短，短的用0值继续参与计算
                cursor1 = cursor1?.next
                cursor2 = ListNode(0)
            } else if nil == cursor2?.next && nil == cursor1?.next{
                //相同长度计算到最后一位，如果存在进位，则将进位保存为最终的node
                if upgrade_digit != 0  {
                    let new_digit = ListNode(upgrade_digit)
                    result_cursor?.next = new_digit
                    result_cursor = new_digit
                }

                cursor1 = cursor1?.next
                cursor2 = cursor2?.next
                
            } else {
                //正常处理
                cursor1 = cursor1?.next
                cursor2 = cursor2?.next
            }
        }
        
        return result
    }
}