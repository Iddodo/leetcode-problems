#define NUM_SUBSTRACTIONS 6

class Solution {
public:
    /*
    * Observation: substraction instances are not vague and do not have double meanings.
    * For example, 'IV' always means 4, since it only appears to the right of the string (40, 400 are covered by XL and CD)
    * Therefore, our algorithm will look at pairs of 2-letter substrings and test for substractions.
    * A special endcase for the last character is also included.
    */
    int romanToInt(string s) {
        const int len = s.length();
        int result = 0;
        int i = 0;
        bool is_substraction;
        
        // Iterate over two character substrings in order to locate substractions
        for (i = 0; i < len - 1; i++) {
            result += this->evaluatePair(s[i], s[i+1], &is_substraction);
            
            // Make next iteration skip 2 characters due to pair being located
            if (is_substraction) {
                i++;
            }
        }
        
        // Add value of last character in case it wasn't evaluated
        if (i != len) {
            result += this->romanCharValue(s[len - 1]);
        }
        
        return result;
    }
    
private:
    // An array of available substractions
    const string substractions[NUM_SUBSTRACTIONS] = {"IV", "IX", "XL", "XC", "CD", "CM"};
    
    /*
    * Returns the value that should be added to integer value of roman number.
    * In case of no valid substraction, return roman value of left character
    */
    const int evaluatePair(char x, char y, bool* is_substraction) {
        const string pair = {x, y};
        
        // Set 'is_substraction' to true in case of an instance.
        *is_substraction = true;
        
        for (int i = 0; i < NUM_SUBSTRACTIONS; i++) {
            if (pair.compare(this->substractions[i]) == 0) {
                
                // Value of a substraction is evaluated in this manner
                return this->romanCharValue(y) - this->romanCharValue(x);
            }
        }
        
        // No valid substraction was found
        *is_substraction = false;
        
        return this->romanCharValue(x);
    }
    
    const int romanCharValue(char x) {
        switch (x) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        // The code will not get here due to problem constraints
        return 0;
    }
    
};
