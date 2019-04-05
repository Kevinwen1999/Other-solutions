void reverse(char* s, int i, int j) {
    for (int k = 0; k < (j - i + 1) / 2; k++) {
        s[i + k] = s[i + k] ^ s[j - k];
        s[j - k] = s[j - k] ^ s[i + k];
        s[i + k] = s[i + k] ^ s[j - k];
    }
}
char* reverseWords(char* s) {
    int N = strlen(s);
    reverse(s, 0, N - 1);
    int si = 0, i = 0;
    int cnt = 1;
    while (si < N) {
        if (s[si] == ' ') {
            if (!cnt) {
                s[i++] = ' ';
                cnt = 1;
            }
            si++;
            continue;
        }
        
        int sj = si;
        while (sj != N && s[sj] != ' ') {
            sj++;
        }
        sj--;
        reverse(s, si, sj);
        for (int k = si; k <= sj; k++) {
            s[i++] = s[k];
        }
        cnt = 0;
        si = sj + 1;
    }
    if (i && s[i - 1] == ' ') i--;
    s[i] = '\0';
    return s;
}
