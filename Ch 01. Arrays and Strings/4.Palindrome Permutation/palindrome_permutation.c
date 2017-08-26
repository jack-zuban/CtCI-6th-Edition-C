//
//  palindrome-permutation.c
//  Check if a given string is a permutation of a palidrome by toggling the bits that represent characters on the string.
//
//

#include <stdio.h>
#include <stdbool.h>

bool isEnglishLetter(char character)
{
    return ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'));
}

// Check that exactly one bit is set by substructing 1 from the integer and bit ANDing it with the original integer
bool checkThatOnlyOneBitIsSet(int bitVector)
{
    return (bitVector & (bitVector - 1)) == 0;
}

// Create a bit vector for the phrase. For each letter from the string, toggle the ith bit
int createBitVector(char *phrase)
{
    int toggle(int, int);
    bool isEnglishLetter(char letter);
    int bitVector = 0;

    while(*phrase) {
        if (isEnglishLetter(*phrase)) {
            bitVector = toggle(bitVector, (int) *phrase);
        }

        phrase++;
    }

    return bitVector;
}

// Toggle the ith bit in the bitVector
int toggle(int bitVector, int index)
{
    if (index < 0) return bitVector;

    int mask = 1 << index;

    if ((bitVector & mask) == 0) {
        bitVector |= mask;
    } else {
        bitVector &= ~mask;
    }

    return bitVector;
}

// if all bits are off, or only one bit is set, the phrase is a permutation of a palinsrome
bool isPermutationOfPalindrome(char *phrase)
{
    bool checkThatOnlyOneBitIsSet(int);
    int createBitVector(char *), bitVector;

    bitVector = createBitVector(phrase);

    return bitVector == 0 || checkThatOnlyOneBitIsSet(bitVector);
}

int main(int argc, const char * argv[]) {
    bool isPalindromePermutation(char *);
    char phraseForCheck[80] = {};

    printf("Please enter your phrase: ");
    fgets(phraseForCheck, 80, stdin);

    printf("The string is %s a permutation of a palindrome\n", isPermutationOfPalindrome(phraseForCheck) ? "" : "not");
    
    return 0;
}
