#include <string>
using std::string;

#define ALPHABET_LENGTH 26

class Solution {
public:
    // Compare between the histograms of the input strings.
    bool isAnagram(string s, string t) {
        return this->createHistogram(s).equals(this->createHistogram(t));
    }
private:
    class AlphabetHistogram {
        int letter_histogram[ALPHABET_LENGTH] = {0};

    public:
        bool equals(AlphabetHistogram a) const {
            for (int i = 0; i < ALPHABET_LENGTH; i++)
                if (this->letter_histogram[i] != a.letter_histogram[i])
                    return false;

            return true;
        }

        // Assumes letter is lower-case (according to constraints)
        void incrementLetter(char letter) {
            ++this->letter_histogram[letter - 'a'];
        }

    };

    AlphabetHistogram createHistogram(string s) const {
        AlphabetHistogram hist;

        for (unsigned int i = 0; i < s.length(); i++) hist.incrementLetter(s[i]);

        return hist;
    }
};
