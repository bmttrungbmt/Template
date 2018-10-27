#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
const string NAME = "cir"; ///filename
const string DIR = "Test/Testcir/"; ///path to tests
const int bg = 1; ///first test
const int ed = 20; ///last test
const int Linux = 1; /// =1 if use linux

string numToStr(int x, int y) {
    string rs;
    while(x > 0) {
        rs = char(x%10 + '0') + rs;
        x /= 10; y /= 10;
    }
    ///Add 0
    /*while(y > 0) {
        rs = '0' + rs;
        y /= 10;
    }*/
    return rs;
}

bool copyFile(const char *SRC, const char* DEST) {
    std::ifstream src(SRC, std::ios::binary);
    std::ofstream dest(DEST, std::ios::binary);
    dest << src.rdbuf();
    return src && dest;
}

bool copyTest(int i) {
    string FileIn, FileOu;
    string iTest = numToStr(i, ed);
    //copy test
    FileIn = DIR + iTest + "/" + NAME + ".inp";
    FileOu = NAME + ".inp";
    if(copyFile(FileIn.c_str(), FileOu.c_str()) == 0) {
        cout << "Error: Copy file";
        return 0;
    }
    FileIn = DIR + iTest + "/" + NAME + ".out";
    FileOu = NAME + ".ans";
    if(copyFile(FileIn.c_str(), FileOu.c_str()) == 0) {
        cout << "Error: Copy file";
        return 0;
    }
    return 1;
}

int main() {
    srand(time(NULL));
    for(int i = bg; i <= ed; ++i) {

        if(!copyTest(i)) return 0;

        auto start = high_resolution_clock::now();
            if(Linux) system(("./" + NAME).c_str());
            else system((NAME + ".exe").c_str());
        auto stop = high_resolution_clock::now();

        if(system(("diff " + NAME + ".out " + NAME + ".ans").c_str()) != 0) {
            cout << "Test " << i << ": WRONG!\n";
        } else cout << "Test " << i << ": CORRECT!\n";

        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "Execution Time: "
             << double(duration.count())/double(1e9) << " seconds\n";
    }
    return 0;
}

