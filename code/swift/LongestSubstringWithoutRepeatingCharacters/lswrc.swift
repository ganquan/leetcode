//这个Swift的性能啊。。。。
//986 / 987 test cases passed.
//Status: Time Limit Exceeded

class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        
        var m:[Character: Int] = [:]
        
        var maxLen = 0
        var lastRepeatPos = -1
        
        for i in 0..<s.indices.count {
            
            if let unwrapLastRepeatPos = m[s[i]], lastRepeatPos < unwrapLastRepeatPos {
                lastRepeatPos = unwrapLastRepeatPos
            }
            
            if i - lastRepeatPos > maxLen {
                maxLen = i - lastRepeatPos
            }
            
            m[s[i]] = i
        }
        
        return maxLen
    }
}

extension String {
    subscript (_ i: Int) -> Character {
        get {
            return self[index(startIndex, offsetBy: i)]
        }
    }
}