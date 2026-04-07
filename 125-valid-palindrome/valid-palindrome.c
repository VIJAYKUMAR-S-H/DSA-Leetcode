

bool isPalindrome(char* s) {
    int left = 0;
    int right = 0;

    // find length of string
    while (s[right] != '\0') {
        right++;
    }
    right--; // last index

    while (left < right) {

        // skip non-alphanumeric from left
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        // skip non-alphanumeric from right
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // compare characters (case-insensitive)
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}