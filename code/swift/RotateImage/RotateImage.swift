class Solution {
    func rotate(_ matrix: inout [[Int]]) {
        var m = Maxtrix(matrix)
        m.rotate90Clockwise()
        
        matrix = m.splitArray(matrix.count)
    }
}

struct Maxtrix {
    //使用一维数组来存储
    var rowNum: Int = 0
    var colNum: Int = 0
    
    var matrix: [Int]
    
    init(_ m:[[Int]]) {
        rowNum = m.count
        colNum = m.count
        
        var tmp:[Int] = []
        m.forEach {
            tmp.append(contentsOf: $0)
        }
        matrix = tmp
    }
    
    init(_ row:Int, _ col: Int, _ initValue: Int) {
        rowNum = row
        colNum = col
        
        matrix = Array(repeating: initValue, count: rowNum * colNum)
    }
    
    func indexIsValid(row: Int, column: Int) -> Bool {
        return row >= 0 && row < rowNum && column >= 0 && column < colNum
    }
    
    func valueAt(row: Int, column: Int) -> Int {
        assert(indexIsValid(row: row, column: column), "Index out of range")
        return matrix[(row * colNum) + column]
    }
    
    subscript(row: Int, column: Int) -> Int {
        get {
            assert(indexIsValid(row: row, column: column), "Index out of range")
            return matrix[(row * colNum) + column]
        }
        set {
            assert(indexIsValid(row: row, column: column), "Index out of range")
            matrix[(row * colNum) + column] = newValue
        }
    }
    
    mutating func rotate90Clockwise() {
        //按照对角线，上下交换
        for r in 0...rowNum - 1 {
            for c in 0...colNum - 1 {
                if r == c {
                    break
                } else {
                    
                    let tmp = self[r, c]
                    self[r, c] = self[c, r]
                    self[c, r] = tmp
                    
                }
            }
        }
        
        
        //按照每行中点前后交换
        for r in 0...rowNum - 1 {
            var coloumStep = 0
            for c in 0...colNum - 1 {
                if c < colNum / 2 {
                    let tmp = self[r, c]
                    self[r, c] = self[r, colNum - coloumStep - 1]
                    self[r, colNum - coloumStep - 1] = tmp
                    
                    coloumStep += 1
                } else {
                    break
                }
            }
        }
    }
}

extension Maxtrix {
    func splitArray(_ n:Int) -> [[Int]] {
        
        var result:[[Int]] = []
        let start = 0
        let end = n
        for i in 0...matrix.count / n - 1 {
            
            result.append(Array(matrix[start+i*n..<end+i*n]))
        }
        
        return result
    }
}

extension Maxtrix {
    func printMatrix() {
        
        print("row = \(rowNum), col = \(colNum)")
        var lines:String = ""
        let leadingSpace = "  "

        for row:Int in 0...rowNum - 1 {
            
            if row == 0 {
                lines.append("[\n")
            }
            
            for col:Int in 0...colNum - 1 {
                
                if col == 0 {
                    lines.append(leadingSpace + "[")
                }
                
                lines.append(String(self[row, col])  + ",")
                
                if col == colNum - 1  {
                    lines.append("],\n")
                }
            }
            
            if row == rowNum - 1  {
                lines.append("]\n")
            }
        }
        
        print(lines)
    }
}