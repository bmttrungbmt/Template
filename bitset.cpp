template <class T> int getBit(T x, int y) {return x >> (y - 1) & 1;}
template <class T> T turnOff(T x, int y) {return x & ~ (1 << (y - 1));}
template <class T> T turnOn(T x, int y) {return x | (1 << (y - 1));}
template <class T> T xorBit(T x, T y, int lim) {
    T res = 0, pw = 1;
    for(int i = 1; i <= lim; ++i) {
        if(getBit(x, i) != getBit(y, i)) res += pw;
        pw *= 2;
    }
    return res;
}
