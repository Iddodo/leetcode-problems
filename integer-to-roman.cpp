class Solution {
public:
    /*
    * Observations: 
    * 1) Dismantling number to its decimal base components is desirable because they are not connected to each other in Roman.
    * 2) Higher values appear to the left of the Roman string
    * 3) Due to problem constraints, 'MMM' is the highest possible number of thousands
    * 
    */
    string intToRoman(int num) {
        string result = "";
        int rem = num;
        
        /*
        * Simply build all components using 'baseCountToRoman'
        * Note: due to problem constraints, 0<=n<=3 for 'base' = 1000
        */
        for (int base = 1000; base > 0; base /= 10) {
            result += this->baseCountToRoman(rem / base, base);
            cout << endl;
            rem -= base*(rem / base);
        }
        
        return result;
    }
private:
    /*
    * This function is an attempt to prevent redundant code duplication.
    * Receives base counter and base itself and returns appropriate Roman string.
    * Assumes 1<=n<=9 and 'base' is a multiple of 10, s.t. 10<=base<=1000
    */
    string baseCountToRoman(int n, int base) {
        const char base_char = this->romanIntValue(base);
        const char middle_char = this->romanIntValue(5*base);
        const char next_base_char = this->romanIntValue(10*base);
        
        if (n < 4)
            return std::string(n, base_char);
        
        if (n == 4)
            return {base_char, middle_char};
        
        if (n == 5)
            return std::string(1, middle_char);
        
        if (n > 5 && n < 9)
            return std::string(1, middle_char) + std::string(n - 5, base_char);
        
        if (n >= 9)
            return {base_char, next_base_char};
        
        // Code will not get here
        return "";
    }
    
    const char romanIntValue(int n) {
        switch (n) {
            case 1: return 'I';
            case 5: return 'V';
            case 10: return 'X';
            case 50: return 'L';
            case 100: return 'C';
            case 500: return 'D';
            case 1000: return 'M';
        }
        // This code is negligible due to problem constraints
        return '\0';
    }
};
