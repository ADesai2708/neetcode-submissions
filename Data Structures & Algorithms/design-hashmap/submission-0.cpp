class MyHashMap {
public:
    static const int SIZE=1000;
    vector<list<pair<int,int>>> bucket;
    int hash(int key){
        return key % SIZE;
    }
    MyHashMap() {
        bucket.resize(SIZE);
    }
    
    void put(int key, int value) {
        int index=hash(key);
        for(auto &p:bucket[index]){
            if(p.first==key){
                p.second=value;
                return;
            }
        }
        bucket[index].push_back({key,value});
    }
    
    int get(int key) {
        int index=hash(key);
        for(auto &p:bucket[index]){
            if(p.first==key){
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index=hash(key);
        for(auto it=bucket[index].begin();
        it != bucket[index].end();++it){
            if(it->first ==key){
                bucket[index].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */