//
// Created by adeshchoudhar on 23/04/22.
//

class Solution {
public:
    unordered_map <string, string> um;
    string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = "http://tinyurl.com/", code = "";
        srand(time(0));
        for (int i = 0; i < 6; i++) {
            code.push_back(s[rand() % 62]);
        }
        um[code] = longUrl;
        shortUrl += code;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string longUrl = um[shortUrl.substr(19)];
        return longUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
