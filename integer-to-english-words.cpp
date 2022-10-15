#include <string>
#include <vector>
#include <cmath>

using std::string;

class Solution {
public:
    /*
    * Observations:
    * 1) The upper bound is 2,147,483,647
    * 2) Thousands separators split a number into digit groups that are linguistically independent
    * Therefore, simply split a word using these separators and handle every sub-thousand number individually.
    */
    string numberToWords(int num) {
        if (num <= 0) {
            return "Zero";
        }

        string result = "";
        int separators = 0;
        std::vector<int> digit_groups;

        // Calculate number of separators and prepare digit groups
        for (int rem = num; rem > 0; rem /= 1000) {
            digit_groups.push_back(rem % 1000);
            separators++;
        }

        // Iterate over digit groups, handle each group and add relevant suffix if necessary.
        for (int i = separators, base = pow(1000, separators - 1); i > 0; i--, base /= 1000) {
            int group = digit_groups[i - 1];

            // Skip iteration in case of an empty digit group
            if (group <= 0) continue;

            // Add whitespace only if digit group is not the first
            if (i < separators) {
                result += " ";
            }

            result += this->subThousandToString(group);

            if (group > 0 && base > 1) {
                result += " " + this->numberString(base);
            }
        }

        return result;
    }
private:
    // Convert sub-thousand number to a string
    string subThousandToString(int n) const {
        int hundreds = n / 100;
        int tens_ones = n - 100*(n / 100);

        string result = "";

        if (hundreds > 0) {
            result = this->numberString(hundreds) + " " + this->numberString(100);

            if (tens_ones > 0) {
                result += " ";
            }
        }

        // In case tens and ones digits form a one-word number
        if ((tens_ones > 10 && tens_ones < 20) || tens_ones % 10 == 0) {
            result += this->numberString(tens_ones);

        } else {
            int tens = tens_ones / 10;
            int ones = tens_ones - 10*tens;

            result += this->numberString(10*tens);

            if (ones > 0) {
                if (tens > 0) result += " ";
                result += this->numberString(ones);
            }
        }

        return result;
    }

    // Get the string of a selected number of numbers
    string numberString(int n) const {
        switch (n) {
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
            case 20: return "Twenty";
            case 30: return "Thirty";
            case 40: return "Forty";
            case 50: return "Fifty";
            case 60: return "Sixty";
            case 70: return "Seventy";
            case 80: return "Eighty";
            case 90: return "Ninety";
            case 100: return "Hundred";
            case 1000: return "Thousand";
            case 1000000: return "Million";
            case 1000000000: return "Billion";
        }

        // Not a selected type of number
        return "";
    }
};
