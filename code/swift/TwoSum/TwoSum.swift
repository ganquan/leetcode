class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
         var result: [Int]?
        
        for i in 0...nums.count - 1 {
            let j = i + 1
            for j in j...nums.count - 1 {
                if nums[i] + nums[j] == target {
                    result = [i, j]
                    return result ?? [0]
                } else {
                    continue
                }
            }
            
        }
        
        return result ?? [0]
    }
}