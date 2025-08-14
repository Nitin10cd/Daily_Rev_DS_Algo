#include<bits/stdc++.h>
using namespace std;

class LRUCache {      
    int capacity;
    list<pair<int,int>> dq;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
public:
  

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        
        dq.splice(dq.begin(), dq, mp[key]);
        return mp[key]->second;
    }
    
    
   void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->second = value;
            dq.splice(dq.begin(), dq, mp[key]);
        } else {
          
            if (dq.size() == capacity) {
                auto last = dq.back();
                mp.erase(last.first);
                dq.pop_back();
            }

            dq.push_front({key, value});
            mp[key] = dq.begin();
        }
    }
};