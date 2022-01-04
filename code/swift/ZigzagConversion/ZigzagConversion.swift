class Solution {
    
    //模拟，把zigzag构造出来
    //把每一行当做一个String处理
    //一开始思路比较原始，把构造zigzag当做二位数组处理，就需要计算列数目，其实意义不大。
    func convert(_ s: String, _ numRows: Int) -> String {
        
        if numRows <= 1 {
            return s
        }
        
        var strs:[String] = Array<String>(repeating: "", count: numRows)
        var row = 0
        var row_step = 1         //行的步进值，达到numRow - 1之后，要变成-1
        
        for i in 0...s.count - 1 {
            let idx = s.index(s.startIndex, offsetBy: i)
            strs[row].append(s[idx])
            
            if row == 0 {
                row_step = 1
            } else if row == numRows - 1 {
                row_step = -1
            }
        
            row += row_step
        }

        var result:String = ""
        for r in 0...numRows - 1 {
            result += strs[r]
        }

        return result
    }
}