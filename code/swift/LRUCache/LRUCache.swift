/**
 * Your LRUCache object will be instantiated and called as such:
 * let obj = LRUCache(capacity)
 * let ret_1: Int = obj.get(key)
 * obj.put(key, value)
 */

//Runtime: 2167 ms, faster than 26.99% of Swift online submissions for LRU Cache.
//Memory Usage: 31.3 MB, less than 79.43% of Swift online submissions for LRU Cache.
class LRUCache {
    
    private var map: [Int: DoubleLinkedListNode] = [:]
    private var head: DoubleLinkedListNode?
    private var tail: DoubleLinkedListNode?
    
    public var max_cache_size: Int {
        didSet { clean() }
    }
    
    init() {
        max_cache_size = 5
    }
    
    
    init(_ capacity: Int) {
        max_cache_size = capacity
    }
    
    public func put(_ key: Int, _ value: Int) {
        
        if let node = map[key] {
            //有缓存，更新value
            node.val = value
            
            //移除旧缓存，放到最新
            removeNode(node)
            appendNode(node)
            
        } else {
            //无缓存，增加node
            let n = DoubleLinkedListNode(value, key)
            map[key] = n
            appendNode(n)
        }
        
        //检查是否超出容量，则移除最旧的缓存
        clean()
    }

    public func get(_ key: Int) -> Int {
        
        if let v:DoubleLinkedListNode = map[key] {
            
            //移除缓存然后再放到最新
            removeNode(v)
            appendNode(v)
            
            return v.val
        }
        
        return -1
    }
}


extension LRUCache {
    
    var count: UInt {
        return UInt(map.count)
    }
    
    var isEmpty: Bool {
        return map.isEmpty
    }
}

extension LRUCache {
    class DoubleLinkedListNode {
        
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
        
        
        init(_ v: Int, _ k: Int, _ p: DoubleLinkedListNode?, _ n: DoubleLinkedListNode?) {
            val = v
            key = k
            prev = p
            next = n
        }
    }
    
    public func removeNode(_ node: DoubleLinkedListNode) {
        
        if node === head {
            head = node.next
        }
        
        if node === tail {
            tail = node.prev
        }
        
        node.prev?.next = node.next
        node.next?.prev = node.prev
        
        node.prev = nil
        node.next = nil
        
    }
    
    public func appendNode(_ node: DoubleLinkedListNode) {
        
        if head == nil {
            head = node
        }
        
        node.prev = tail
        tail?.next = node
        tail = node
    }

    public func clean() {
        
        while count > max_cache_size, let h = head {
            //删除最旧缓存
            removeNode(h)
            map.removeValue(forKey: h.key)
        }

    }
}