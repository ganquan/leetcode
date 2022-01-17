class LFUCache {
    
    private var valueMap: [Int: DoubleLinkedListNode] = [:]                 // <key, value wrap in Node with freq>
    private var freqMap: [Int: DoubleLinkedList] = [:]                      // <freq, List>
    private var minFreq = 1
    
    public var max_cache_size: Int
    
    init() {
        max_cache_size = 5
    }
    
    init(_ capacity: Int) {
        max_cache_size = capacity
    }
    
    private func resettleNode(_ node: DoubleLinkedListNode) {
        node.useCount()
        
        if node.freq <= minFreq {
            minFreq = node.freq
        }
        
        if let newFreqList = freqMap[node.freq] {
            newFreqList.appendNode(node)
        } else {
            //出现了新的频率
            let newlist = DoubleLinkedList()
            newlist.appendNode(node)
            freqMap[node.freq] = newlist
        }
    }
    
    
    func put(_ key: Int, _ value: Int) {
        
        if max_cache_size <= 0 {
            return
        }
        
        if let node = valueMap[key] {
            //有缓存，更新value
            node.val = value
            
            if let freqList = freqMap[node.freq] {
                freqList.removeNode(node)
                
                if freqList.isEmpty {
                    freqMap.removeValue(forKey: node.freq)
                }
            }
            
            resettleNode(node)
            
        } else {
            //无缓存，新增
            //
            //新增之前检查容量，检查是否超出容量，否则移除最旧的缓存
            tryToRetireTheLeastUsedNode()
            
            let node = DoubleLinkedListNode(value, key)
            valueMap[key] = node
            
            resettleNode(node)
        }
        
    }
    
    func get(_ key: Int) -> Int {
        
        if let node = valueMap[key] {
            //存在
            //从旧频率表中移除
            if let oldFreqList = freqMap[node.freq] {
                oldFreqList.removeNode(node)
                if oldFreqList.isEmpty {
                    freqMap.removeValue(forKey: node.freq)
                }
            }
            
            resettleNode(node)
            
            return node.val
        }
        
        return -1
    }
    
    public func tryToRetireTheLeastUsedNode() {
        
        while count >= max_cache_size {
            //删除最少使用（频率最低）且最旧缓存
            if let list = freqMap[minFreq], !list.isEmpty, let h = list.head {
                list.removeNode(h)
                valueMap.removeValue(forKey: h.key)
                
                if list.isEmpty {
                    freqMap.removeValue(forKey: minFreq)
                }
                
            } else {
                freqMap.removeValue(forKey: minFreq)
                minFreq += 1
            }
        }
        
    }

}

extension LFUCache {
    
    var count: Int {
        return valueMap.count
    }
}

extension LFUCache {
    class DoubleLinkedListNode {
        
        var freq: Int = 0
        var val: Int
        var key: Int
        weak var prev: DoubleLinkedListNode?
        weak var next: DoubleLinkedListNode?
        
        init(_ v: Int, _ k: Int) {
            val = v
            key = k
            prev = nil
            next = nil
        }
        
        public func useCount() {
            freq += 1
        }
    }
    
    
    class DoubleLinkedList {
        
        weak var head: DoubleLinkedListNode?
        weak var tail: DoubleLinkedListNode?
        
        init() {
            
        }
        
        var isEmpty: Bool {
            get {
                return (head == nil && tail == nil)
            }
        }
        
        func appendNode(_ node: DoubleLinkedListNode?) {
            if head == nil {
                head = node
            }
            
            node?.prev = tail
            tail?.next = node
            tail = node
        }
        
        func removeNode(_ node: DoubleLinkedListNode?) {
            
            if node === head {
                head = node?.next
            }
            
            if node === tail {
                tail = node?.prev
            }
            
            node?.prev?.next = node?.next
            node?.next?.prev = node?.prev
            
            node?.prev = nil
            node?.next = nil
        }
    }
}