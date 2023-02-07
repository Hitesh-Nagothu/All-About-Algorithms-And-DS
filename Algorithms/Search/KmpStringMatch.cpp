#include "../allheaders.h"
using namespace std;

//(longest proper prefix which is also a suffix) array
// o(pattern length)
vector<int> buildLPSArray(string pattern) {
    int patternSize = pattern.length();
    vector<int> lps(patternSize, 0);

    int matchedLength = 0;
    int idx = 1;

    while (idx < patternSize) {
        //match consecutive lengths
        if (pattern[idx] == pattern[matchedLength]) {
            matchedLength += 1;
            lps[idx] = matchedLength;
            idx += 1;
        }
        else {
            //reset matched length if no match
            if (matchedLength != 0) {
                matchedLength = lps[matchedLength - 1];
            }
            else {
                lps[idx] = 0;
                idx += 1;
            }

        }
    }

    return lps;
}

//o(len of text) + O(time to build lps)
void KMPSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m > n) return;

    vector<int> lps = buildLPSArray(pattern);

    for (auto x : lps) {
        cout << x << " ";
    }
    int i = 0;
    int j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << "Pattern " << pattern << " found in text starting at index " << i - j << endl;
            j = lps[j - 1]; //reset j to find next match
        }
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1]; //jump j to previous point until it had a match in text
            }
            else {
                i++; //cannot move j below 0, hence shift i
            }
        }
    }
}

int main() {
    string text = "cxdwzolfrccawvewcxdwzolfrccxdwzolfrccawvewkrcawvewkrkrysotfbdngngvfrj";
    string pattern = "cxdwzolfrccawvewkr";
    KMPSearch(text, pattern);
    return 0;
}
