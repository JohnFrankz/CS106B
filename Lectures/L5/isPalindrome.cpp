bool isPalindrome(string str) {
    int len = str.length();
    if (len == 1) {
        return true;
    }

    return str[0] == str[len - 1] && isPalindrome(str.sub(1, len - 2));
}

bool isPalindromeImp(string str) {
    return isSubStringPalindrome(str, 0, str.length() - 1);
}

bool isSubStringPalindrome(string str, int p1, int p2) {
    if (p1 >= p2) {
        return true;
    }

    return str[p1] == str[p2] && isSubStringPalindrome(str, p1 + 1, p2 - 1);
}
