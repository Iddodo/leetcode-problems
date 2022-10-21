#include <stdint.h>

class Solution {
public:

    /* Iterate over the 32 bits of 'n' and increment 'weight' for every lit bit.
     * Uses overflow property of the bitwise shift-right operator to end the loop. */

    int hammingWeight(uint32_t n) {
        int weight = 0;

        for (uint32_t comp = 1; comp > 0; comp = comp << 1)
            weight += (n & comp) > 0;

        return weight;
    }
};
