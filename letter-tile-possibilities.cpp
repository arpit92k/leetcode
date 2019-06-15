
class Solution {
    std::unordered_set<std::string> unique_strings;
public:
    int numTilePossibilities(string tiles) {
        std::map<char, int> chars;
        for(int i=0; i<tiles.length();++i)
        {
            if(chars.find(tiles[i]) != chars.end())
                chars[tiles[i]]++;
            else
                chars[tiles[i]] = 1;
        }
        std::vector<pair<char,int>> charf;
        for(auto it = chars.begin(); it != chars.end(); ++it)
        {
            charf.push_back(std::make_pair<const char&,int&>(it->first,it->second));
        }
        generate_sequences("",charf);
        return unique_strings.size();
    }
    
private:
    void generate_sequences(std::string str,std::vector<pair<char, int>> &charf)
    {
        bool is_end = true;
        int l = charf.size();
        for(int i=0; i<l; ++i)
        {
            int f = charf[i].second;
            if(f > 0)
            {
                is_end = false;
                --charf[i].second;
                generate_sequences(str+charf[i].first,charf);
                generate_sequences(str,charf);
                ++charf[i].second;
            }
        }
        if(is_end && str.length() > 0)
        {
            unique_strings.insert(str);
        }
    }
};
