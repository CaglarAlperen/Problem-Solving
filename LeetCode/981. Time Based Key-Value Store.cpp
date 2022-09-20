class TimeMap {
public:
    map<string, map<int, string>> um;
    
    TimeMap() 
    {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        um[key][timestamp] = value;       
    }
    
    string get(string key, int timestamp) 
    {
        auto it = um[key].upper_bound(timestamp);
        if (it == um[key].begin() && um[key].begin()->first != timestamp)
            return "";
        if (it != um[key].begin())
            it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */