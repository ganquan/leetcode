class Solution {
    func reverse(_ x: Int) -> Int {
        var result: Int
        let isNegtive: Bool = x < 0 ? true : false
        var i = abs(x)
        var s: String = ""
        
        while i % 10 == 0 && i != 0 {
            i = i / 10
        }
        
        while i != 0 {
            let digit = i % 10
            s.append(String(digit))
            i = i / 10
        }
        
        if isNegtive {
            s.insert("-", at: s.startIndex)
        }
        
        result = Int(s) ?? 0
        if result > Int32.max || result < Int32.min {
            result = 0
        }
        
        return result
    }
}