#include <iostream>
#include <stack>
#include <string>

using std::string;
using std::stack;

class Solution {
public:
    /* Use a stack data structure to keep track of any open parenthesis.
     * Test for a mismatch. */

    bool isValid(string s) {
        stack<char> parens;

        for (unsigned int i = 0; i < s.length(); i++) {
            if (this->isLeftParen(s[i])) {
                parens.push(s[i]);
                continue;
            }

            // Otherwise, it's a right parenthesis. Test for a mismatch.
            if (parens.empty() || this->rightParensToLeft(s[i]) != parens.top())
                return false;

            parens.pop();
        }
        // There cannot be any open parentheses at the end of the string.
        return parens.empty();

    }
private:
    inline bool isLeftParen(char p) { return (p == '{' || p == '[' || p == '('); }

    char rightParensToLeft(char p) {
        switch (p) {
            case '}': return '{';
            case ')': return '(';
            case ']': return '[';
        }

        // Code won't get here due to constraints
        return '\0';
    }

};
