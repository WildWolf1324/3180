#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<string>> findAnagrams(const vector<string>& word_list)
{
    unordered_map<string, vector<string>> anagram_map;
    for (auto str: word_list) {
        string sorted_str(str); //make a copy
        sort(sorted_str.begin(), sorted_str.end()); // sort the string
        anagram_map[sorted_str].push_back(str); //Constructs vector and inserts into hashtable
    }
    
    vector<vector<string>> anagrams;
    for (auto ele: anagram_map) //Check if anagrams present
            anagrams.push_back(ele.second);
            
    return anagrams;
}

//const pair<string, vector<string>>&
