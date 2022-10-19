#include <vector>
#include <string>
using std::string;

class Solution {
public:
    /*
    * This solution is almost identical to 'count-and-say'.
    * Simply iterate over chars array and count cons. rep. chars.,
    * Clear the existing information in chars and overwrite with the result. */

    int compress(vector<char>& chars) {
        std::vector<CharSubstringInfo> info;
        info.push_back(CharSubstringInfo(chars[0]));
        int unique_substrings = 1;
        string result = "";

        for (unsigned int i = 0; i < chars.size(); i++) {
           char current_char = chars[i];
           CharSubstringInfo& current_sub = info[unique_substrings - 1];

           if (current_char != current_sub.character) {
              unique_substrings++;
              info.push_back(CharSubstringInfo(current_char));
           }
           info[unique_substrings - 1].count++;
        }

        // Clear the vector, as we will be overwriting its contents.
        chars.clear();

        for (int i = 0; i < unique_substrings; i++) {
            chars.push_back(info[i].character);

            if (info[i].count > 1) {
                string count = info[i].getCountString();

                for (int j = 0; j < count.length(); j++) {
                    chars.push_back(count[j]);
                }
            }
        }

        return chars.size();

    }

private:
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

};
