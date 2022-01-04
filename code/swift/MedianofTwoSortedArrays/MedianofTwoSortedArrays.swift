class Solution {
    func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
        
        let merged: [Int] = mergeSortedArray(nums1, nums2)
        let median:Double = calculateMedianOfArray(merged)
        
        return median
    }
    
    
    func mergeSortedArray(_ a:[Int], _ b:[Int]) -> [Int] {
        var merged: [Int] = []
        
        var i = 0, j = 0
        while i < a.count && j < b.count {
            if a[i] < b[j] {
                merged.append(a[i])
                i += 1
            } else {
                merged.append(b[j])
                j += 1
            }
        }
        
        if i == a.count && j < b.count {
            merged.append(contentsOf: b[j...b.count - 1])
        } else if j == b.count && i < a.count{
            merged.append(contentsOf: a[i...a.count - 1])
        } else {
            print("weired, a.count = \(a.count), b.count = \(b.count), i = \(i), j = \(j)")
        }
        
        return merged
    }
    
    func calculateMedianOfArray(_ arr:[Int]) -> Double {
        var median:Double = 0
        
        guard arr.count != 0  else {
            return median
        }
        
        if arr.count % 2 == 0 {
            //偶数个元素
            let second = arr.count / 2
            let first = second - 1
            median = Double(arr[first] + arr[second]) / 2
        } else {
            //奇数个元素
            median = Double(arr[arr.count / 2])
        }
        
        return median
    }
}