class Solution {
    // search brutely
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

    // using map
    // 54 / 54 test cases passed.
    // Status: Accepted
    // Runtime: 56 ms
    // Memory Usage: 14.9 MB
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var result: [Int] = []

        //turn array to map
        //key: element of the array
        //value: index of the element in the array
        var tmpMap: [Int: [Int]] = [:]

        //init the map
        for i in 0...nums.count - 1 {
            
            if let _ = tmpMap[nums[i]] {
                tmpMap[nums[i]]?.append(i)
            } else {
                tmpMap[nums[i]] = [i]
            }
        }
        
        //search
        for i in 0...nums.count - 1 {

            let distance = target - nums[i]

            if let arr = tmpMap[distance] {
                if arr.count > 1 {
                    let j = arr.first(where: {$0 != i})!
                    result = [i, j]
                    break
                } else if arr.first != i {
                    result = [i, arr.first!]
                    break
                } else {
                    continue
                }
            } else {
                continue
            }

        }

        return result
    
    }

    // more brief
    // 57 / 57 test cases passed.
    // Status: Accepted
    // Runtime: 61 ms
    // Memory Usage: 14.5 MB
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {

        var tmpMap: [Int:Int] = [:]
        for i in 0...nums.count - 1 {
            let distance = target - nums[i]
            if let x = tmpMap[distance] {
                return [x, i]
            } else {
                tmpMap[num[i]] = i
                continue
            }
        }

        return []

    }
}