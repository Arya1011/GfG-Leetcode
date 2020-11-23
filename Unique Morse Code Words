https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3540/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
       if(words.empty())return 0; vector<string>codes{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<char,string>mp;
        set<string>unique;
        char ch='a';
        for(auto code:codes){
          mp[ch]=code;
            ch+=1;
        }
        
        for(auto word:words){

           string curr="";
            
            for(auto ch:word){
                
                curr+=mp[ch];
                
            }
            
            unique.insert(curr);
        
        
        }
        
        
        return unique.size();
        
        
        
    }
};
