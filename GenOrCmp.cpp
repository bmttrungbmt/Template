#include <bits/stdc++.h>

using namespace std;
const string NAME = "";
const int bg = 1;
const int ed = 1;
const int type = 1; /// 1:Gen test, 2:Compare code

void genTest() {
    ofstream inp((NAME + ".inp").c_str());

    inp.close();
}

string toStr(int x, int y) {
    string rs;
    while(x > 0) {
        rs = char(x%10 + '0') + rs;
        x /= 10; y /= 10;
    }
    /// Add 0
    while(y > 0) {
        rs = '0' + rs;
        y /= 10;
    }
    return rs;
}

void sys(string cmd) {
    system(cmd.c_str());
}

bool copyFile(string SRC, string DEST) {
    ifstream src(SRC.c_str());
    ofstream dest(DEST.c_str());
    dest << src.rdbuf();
    return src && dest;
}

void copyTest(int itest) {
    sys("mkdir Test" + toStr(itest, ed));
    sys("./" + NAME); //linux
    //sys(NAME + ".exe");
    string inp, out;
    inp = NAME + ".inp";
    out = "Test" + toStr(itest, ed) + "/" + NAME + ".inp";
    if(!copyFile(inp, out)) {
        cout << "Cannot copy file *.inp " << itest << "!\n";
    }
    inp = NAME + ".inp";
    out = "Test" + toStr(itest, ed) + "/" + NAME + ".inp";
    if(!copyFile(inp, out)) {
        cout << "Cannot copy file *.out " << itest << "!\n";
    }
}

bool compare() {
    sys("./" + NAME); sys("./" + NAME + "_trau"); //linux
    //sys(NAME + ".exe"); sys(NAME + "_trau.exe");
    if(sys("diff " + NAME + ".out " + NAME + ".ans") != 0)
        return 0;
    return 1;
}

int main() {
    srand(time(NULL));
    for(int itest = bg; itest <= ed; ++itest) {
        genTest();
        if(type == 1) {
            copyTest(itest);
        }
        if(type == 2) {
            if(!compare()) {
                cout << itest << " WRONG!!!\a\n";
                return 0;
            }
            cout << itest << "RIGHT\n";
        }
    }
}
