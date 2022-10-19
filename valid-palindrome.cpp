#include <string>
using std::string;

class Solution {
public:
    /* First strip any non-alphanumeric character and make all letters lowercase.
     * Then, check if the resulting string is a palindrome. */
    bool isPalindrome(string s) {
       string test_string = this->stripForPalindromeTest(s);
       unsigned int len = test_string.length();

        // An empty string is a palindrome
        if (test_string.empty()) return true;

        // Iterate over test string and mirror check for equal characters
        for (unsigned int i = 0; i < len; i++)
            if (test_string[i] != test_string[len - 1 - i])
                return false;

        return true;

    }

private:
    string stripForPalindromeTest(string s) {
        string result = "";

        for (unsigned int i = 0; i < s.length(); i++) {
            char c = s[i];
            // Turn uppercase to lowercase
            if (c >= 'A' && c <= 'Z') {
               result += c + ('a' - 'A');
               continue;
            }

            // Allow lowercase
            if (c >= 'a' && c <= 'z') {
                result += c;
                continue;
            }

            // Allow numbers
            if (c >= '0' && c <= '9') {
                result += c;
            }
        }
        return result;
    }
};
