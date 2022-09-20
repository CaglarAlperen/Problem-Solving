class LRUCache {
public:
    typedef struct Node
    {
        int key;
        int val;
        Node *prev;
        Node *next;
    } Node;
    
    unordered_map<int, Node*> _cache;
    Node *_head;
    Node *_tail;
    int _capacity;
    
    LRUCache(int capacity) 
    {
        _capacity = capacity;
        _head = NULL;
        _tail = NULL;
    }
    
    void push_to_front(Node *element)
    {
        element->prev = NULL;
        element->next = _head;
        if (_head)
            _head->prev = element;
        _head = element;
        if (_tail == NULL)
            _tail = element;
    }
    
    void move_to_front(Node *element)
    {
        if (element == _head)
            return;
        
        if (element->next)
            element->next->prev = element->prev;
        if (element->prev)
            element->prev->next = element->next;
        
        if (element == _tail && element->prev != NULL)
            _tail = element->prev;
        
        element->prev = NULL;
        if (element != _head)
            element->next = _head;
        if (element != _head && _head != NULL)
            _head->prev = element;
        _head = element;
        
    }
    
    void pop()
    {
        if (_tail->prev)
        {
            _tail->prev->next = NULL;
        }
        _cache.erase(_tail->key);
        _tail = _tail->prev;
    }
    
    int get(int key) 
    {
        int ret;
        
        if (_cache.find(key) != _cache.end())
        {
            move_to_front(_cache[key]);
            ret = _cache[key]->val;
        }
        else
        {
            ret = -1;
        }
        
        return ret;
    }
    
    void put(int key, int value) 
    {
        if (_cache.find(key) != _cache.end())
        {
            _cache[key]->val = value;
            move_to_front(_cache[key]);
        }
        else
        {
            Node *element = new Node();
            element->key = key;
            element->val = value;
                
            if (_cache.size() == _capacity)
            {
                pop();        
            }
            
            _cache[key] = element;
            push_to_front(element);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */