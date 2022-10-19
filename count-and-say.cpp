#include <vector>
#include <string>
using std::string;

class Solution {
public:
    // As instructed, simply perform 'sayNumber' for n-1 times on previous iterations.
    string countAndSay(int n) {
        string result = "1";

        if (n == 1) return result;

        for (int i = 2; i <= n; i++) {
            result = this->sayNumber(result);
        }

        return result;
    }
private:
    // Bundle a character and its count together for easier access.
    // Include a function that translates the count into a string.
    struct CharSubstringInfo {
        char character;
        int count;

        CharSubstringInfo(char c, int count = 0) : character(c), count(count) {}

        string getCountString() const {
            if (this->count < 10) return string(1, '0' + this->count);

            string result = "";
            for (int r = this->count; r > 0; r /= 10) {
               result = string(1, ('0' + r % 10)) + result;
            }

            return result;
        }
    };

    /* This function "says" a number according to instructions
     * Uses a vector (could have also been a linked list) to store
     * characters and their counts according to order. */

    string sayNumber(string num) const {
        std::vector<CharSubstringInfo> info;
        info.push_back(CharSubstringInfo(num[0]));
        int unique_substrings = 1;

        for (unsigned int i = 0; i < num.length(); i++) {
           char current_char = num[i];
           if (current_char != info[unique_substrings - 1].character) {
              unique_substrings++;
              info.push_back(CharSubstringInfo(current_char));
           }
           info[unique_substrings - 1].count++;
        }

        string result = "";
        for (int i = 0; i < unique_substrings; i++) {
           result += info[i].getCountString() + string(1, info[i].character);
        }

        return result;
    }

};
