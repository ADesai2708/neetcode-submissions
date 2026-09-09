class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string str:strs){
            vector<int> count(26,0);
            for(char c:str){
                count[c-'a']++;
            }
            string key;
            for(int i=0;i<26;i++){
                key+=to_string(count[i]);
                key+="#";
            }
            mp[key].push_back(str);
        }
            vector<vector<string>> result;
            for(auto& pair:mp){
                result.push_back(pair.second);
            }
            return result;
        
    }
};
