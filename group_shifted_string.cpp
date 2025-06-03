#include<iostream> 
#include<unordered_map> 
#include<vector> 

using namespace std; 

class Solution{
public: 
     string shift(const string& s){
       int n = s.size(); 
       if(n<=1) return ""; 
       string key; 
       for(int i=1; i<n; ++i){
         int diff = (26+s[i]-s[i-1])%26; 
         key +=to_string(diff) +","; 
       }
       return key; 
     }
     vector<vector<string>> groupStrings(vector<string>& strings) {
       vector<vector<string>> res; 
       unordered_map<string, vector<string>> mp; 

       for(const string s: strings){
         string key = shift(s); 
         mp[key].push_back(s); 
       }
       for(auto [p, vec]:mp){
         res.push_back(vec); 
       }
       return res; 
       
     }
};
int main(){
  vector<string> strings = {"ab", "ba", "a", "z", "abcef", "abc" , "bcd", "xyz"};
  Solution sol; 
  vector<vector<string>> res= sol.groupStrings(strings); 
  
  for(auto vec:res) {
    cout  << "[ " ; 
    for(string s:vec){
      cout << s << " , " ; 
    }
    cout << "]" <<endl; 
  }
  return 0; 
}
