template <class T> void readInt(T &x) {
    int neg = 1; char c = 0; x = 0;
    while((c < '0' || '9' < c) && c != '-') c = getchar();
    while(('0' <= c && c <= '9') || c == '-') {
        if(c == '-') neg *= -1; else x = x * 10 + int(c - '0');
        c = getchar();
    }
    x *= neg;
}
