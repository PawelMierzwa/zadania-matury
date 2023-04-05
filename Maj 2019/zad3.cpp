#include <iostream>
#include <fstream>
#include <vector>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    std::ifstream source("liczby.txt");
    std::ofstream result("wyniki4.txt", std::fstream::app);

    result << "zadanie 4.3\n";

    std::vector<int> nums;
    int num;

    while (source >> num) {
        nums.push_back(num);
    }

    int longestSeqStart = -1;
    int longestSeqLen = 0;
    int longestSeqGcd = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        int seqStart = i;
        int seqLen = 1;
        int seqGdc = nums[i];

        for (int j = i + 1; j < nums.size(); j++) {
            seqLen++;
            seqGdc = gcd(seqGdc, nums[j]);

            if (seqGdc > 1) {
                if (seqLen > longestSeqLen) {
                    longestSeqStart = seqStart;
                    longestSeqLen = seqLen;
                    longestSeqGcd = seqGdc;
                }
            }
            else {
                break;
            }
        }
    }

    result
        << "pierwsza liczba: " << nums[longestSeqStart] 
        << " dlugosc ciagu: " << longestSeqLen 
        << " dzielnik: " << longestSeqGcd
        << "\n";

    source.close();
    result.close();

    return 0;
}