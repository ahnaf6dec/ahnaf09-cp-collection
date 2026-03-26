#include <bits/stdc++.h>
using namespace std;

// Function to get normal 0-based index
int charToIndex(char c) {
    if (islower(c)) return c - 'a'; // a->0, b->1, ..., z->25
    else if (isupper(c)) return c - 'A'; // A->0, B->1, ..., Z->25
    else return -1; // invalid input
}

// Function to get reverse 0-based index
int charToReverseIndex(char c) {
    if (islower(c)) return 'z' - c; // z->0, y->1, ..., a->25
    else if (isupper(c)) return 'Z' - c; // Z->0, Y->1, ..., A->25
    else return -1; // invalid input
}

// Normal mapping: index -> char
char indexToChar(int pos) {
    if (pos < 0 || pos > 25) return '?'; // invalid
    return 'a' + pos; // 0->a, 1->b, ..., 25->z
}

// Reverse mapping: index -> char
char reverseIndexToChar(int pos) {
    if (pos < 0 || pos > 25) return '?'; // invalid
    return 'z' - pos; // 0->z, 1->y, ..., 25->a
}


// ----------------------------
// Random Generator Setup
// ----------------------------
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int l, int r) {
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}

// ----------------------------
// Character generators
// ----------------------------
char randLower() { return 'a' + rng() % 26; }
char randUpper() { return 'A' + rng() % 26; }
char randAlphaNum() {
    int t = rng() % 3;
    if (t == 0) return randLower();
    if (t == 1) return randUpper();
    return '0' + rng() % 10;
}
char randBinary() { return rng() % 2 ? '1' : '0'; }
char randFromSet(const vector<char>& pool) { return pool[rng() % pool.size()]; }
char randVowel() { const string v = "aeiou"; return v[rng() % v.size()]; }
char randConsonant() { const string c = "bcdfghjklmnpqrstvwxyz"; return c[rng() % c.size()]; }
char randPrintableASCII() { return 32 + rng() % 95; } // 32 to 126

// ----------------------------
// String Generators
// ----------------------------
string randString(int len, char(*charGen)() = randLower) {
    string s(len, 'a');
    for (int i = 0; i < len; ++i) s[i] = charGen();
    return s;
}

string randFromSetString(int len, const vector<char>& pool) {
    string s(len, pool[0]);
    for (int i = 0; i < len; ++i) s[i] = randFromSet(pool);
    return s;
}

string randWordsString(int n, int minLen, int maxLen) {
    string res;
    for (int i = 0; i < n; ++i) {
        int len = randInt(minLen, maxLen);
        res += randString(len) + " ";
    }
    return res;
}

string randStartEnd(int len, char start, char end, const vector<char>& pool) {
    if (len == 1) return string(1, start);
    string s(len, pool[0]);
    s[0] = start;
    s[len-1] = end;
    for (int i = 1; i < len-1; ++i) s[i] = randFromSet(pool);
    return s;
}

string maxLenString(int len, char fill='a') {
    return string(len, fill);
}

string repeatPattern(const string& pattern, int times) {
    string s;
    for (int i = 0; i < times; ++i) s += pattern;
    return s;
}

string randPalindrome(int len, char(*charGen)() = randLower) {
    string s(len, 'a');
    for (int i = 0; i < (len+1)/2; ++i) s[i] = s[len-i-1] = charGen();
    return s;
}

string randAlternating(int len, char a, char b) {
    string s(len, a);
    for (int i = 0; i < len; ++i) s[i] = (i%2 ? b : a);
    return s;
}

string randDistinctChars(int len, int distinctCount) {
    assert(distinctCount <= 26);
    string chars;
    for (int i = 0; i < distinctCount; ++i) chars += ('a'+i);
    return randFromSetString(len, vector<char>(chars.begin(), chars.end()));
}

string randSubstring(const string& base, int len) {
    assert(len <= (int)base.size());
    int start = randInt(0, base.size()-len);
    return base.substr(start, len);
}

string randPrefixSuffix(int len, const string& prefix, const string& suffix) {
    assert(len >= prefix.size() + suffix.size());
    int midLen = len - prefix.size() - suffix.size();
    string mid = randString(midLen);
    return prefix + mid + suffix;
}

string randPrintableString(int len) {
    return randString(len, randPrintableASCII);
}

// ----------------------------
// Word List Generators
// ----------------------------
vector<string> randWordsList(int n, int minLen, int maxLen, char(*charGen)() = randLower) {
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        int len = randInt(minLen, maxLen);
        words[i] = randString(len, charGen);
    }
    return words;
}

// ----------------------------
// Print Utilities
// ----------------------------
void printVector(const vector<string>& vec, const string& sep=" ") {
    for (auto &s : vec) cout << s << sep;
    cout << "\n";
}

void printLeetCodeVector(const vector<string>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "\"" << vec[i] << "\"";
        if (i+1 != vec.size()) cout << ",";
    }
    cout << "]\n";
}

// ----------------------------
// Stress Test Generator Examples
// ----------------------------
int main() {
    cout << "Random lowercase: " << randString(10) << "\n";
    cout << "Random uppercase: " << randString(10, randUpper) << "\n";
    cout << "Random alphanumeric: " << randString(12, randAlphaNum) << "\n";
    cout << "Random binary: " << randString(15, randBinary) << "\n";
    cout << "Random vowel string: " << randString(10, randVowel) << "\n";
    cout << "Random consonant string: " << randString(10, randConsonant) << "\n";
    cout << "Random printable ASCII string: " << randPrintableString(15) << "\n";
    
    vector<char> pool = {'x','y','z','a','b','c'};
    cout << "Random from pool: " << randFromSetString(12, pool) << "\n";
    
    cout << "Random palindrome: " << randPalindrome(11) << "\n";
    cout << "Random alternating ABAB: " << randAlternating(12,'A','B') << "\n";
    cout << "Max length string: " << maxLenString(50,'x') << "\n";
    cout << "Repeated pattern: " << repeatPattern("abc", 10) << "\n";
    
    vector<string> words = randWordsList(5,3,8);
    cout << "Random words list: ";
    printVector(words);
    cout << "LeetCode style: ";
    printLeetCodeVector(words);

    cout << "String with prefix 'pre' and suffix 'suf': " << randPrefixSuffix(15,"pre","suf") << "\n";
    cout << "Random substring of 'abcdefghijklm': " << randSubstring("abcdefghijklm", 5) << "\n";
    cout << "Random string with 5 distinct chars: " << randDistinctChars(12,5) << "\n";

    return 0;
}

