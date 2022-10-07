class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        multimap<int,string> mp;
        istringstream iss(text);
        string word;
        while(iss >> word) {
            cout<<word<<" ";
            
            mp.insert({word.length(),word});
        }
        cout<<"\n";
        
        string res="";
        for(auto str:mp) {
            cout<<str.second<<" ";
            res += str.second;
            res += " ";
        }
        cout<<"\n";
        res.erase(res.begin() + res.length()-1);
        res[0] = toupper(res[0]);
        return res;
    }
};