class LRUCache {
public:
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>:: iterator> mp;
    int max_sz;
    LRUCache(int capacity) 
    { 
        max_sz=capacity;
    }
    
    
    //reset the position of pair in the list
    void reset(int key,int value)
    {
        cache.erase(mp[key]);
        cache.push_front({key,value});
        mp[key]=cache.begin();
    }
    
    
    int get(int key) 
    {
        //if key is found
        if(mp.find(key)!=mp.end())
        {
            int value=(*mp[key]).second;
            reset(key,value);
            return value;          
        }
        return -1;
    }
    
    void put(int key, int value) {
        
         //already present
         if(mp.find(key)!=mp.end())
         {
              reset(key,value);
         }
        
          else
          {
               cache.push_front({key,value});
                mp[key]=cache.begin();
                 //check for overflow
                if(cache.size()>max_sz)
                {
                       mp.erase(cache.back().first);
                       cache.pop_back();
                }
          }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
