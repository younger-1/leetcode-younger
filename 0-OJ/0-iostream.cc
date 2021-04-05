#include <iostream>

using namespace std;

void A() {
    int a, b;
    // note:
    // long a, b;

    while (cin >> a >> b) {
        cout << a + b << endl;
    }
}

void B() {
    int t;
    cin >> t;
    int a, b;
    for (int i = 0; i < t; ++i) {
        cin >> a >> b;
        cout << a + b << endl;
    }
}

void D() {
    int n;
    while (cin >> n && n != 0) {
        int sum = 0;
        int a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
    }
}

void G() {
    int a = 0, sum = 0;
    while (cin >> a) {
        sum += a;
        if (cin.get() == '\n') {
            cout << sum << endl;
            sum = 0;
        }
    }
}

#include <algorithm>
#include <string>
#include <vector>

// 输入: 第一行为 n, 第二行是n个空格隔开的字符串
// 输出: 一行排序后的字符串，空格隔开，无结尾空格
void H() {
    int n;
    string str;
    cin >> n;
    vector<string> v;
    // 循环 n 次
    while (n) {
        cin >> str;
        v.push_back(str);
        --n;
    }
    sort(v.begin(), v.end(), less<string>());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    // less(小于)
    // greater(大于)
    // equal_to(等于)
    // not_equal_to(不相等)
    // less_equal(小于等于)
    // greater_equal(大于等于)
}

// 输入: 多个测试用例，每个测试用例一行。每行通过空格隔开
// 输出: 一行排序过的字符串，每个字符串通过空格隔开
void I() {
    vector<string> v;
    string a;
    while (cin >> a) {
        v.push_back(a);
        if (cin.get() == '\n') {
            sort(v.begin(), v.end());
            for (string &b : v) {
                cout << b << ' ';
            }
            cout << endl;
            // note:
            v.clear();
        }
    }
}

// 输入: 多个测试用例，每个测试用例一行。每行通过,隔开
// 输出: 一行排序后的字符串，用','隔开，无结尾空格

void J1() {
    string s;
    char c;
    vector<string> v;
    // 每次读一个字符
    while (cin.get(c)) {
        if (c == ',') {
            v.push_back(s);
            s.clear();
        } else if (c != '\n') {
            s.push_back(c);
        } else if (c == '\n') {
            v.push_back(s);
            sort(v.begin(), v.end());
            for (int i = 0; i < v.size() - 1; i++) {
                cout << v[i] << ",";
            }
            cout << v[v.size() - 1] << endl;
            s.clear();
            v.clear();
        }
    }
}

void J2() {
    vector<string> v;
    string a;
    while (cin >> a) {
        int pos = 0;
        int start = 0;
        // 手动分割字符串
        while (pos != a.npos) {
            pos = a.find(',', start);
            string b = a.substr(start, pos - start);
            v.push_back(b);
            start = pos + 1;
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() - 1; i++) {
            cout << v[i] << ',';
        }
        cout << v[v.size() - 1] << endl;
        v.clear();
    }
}

#include <sstream>

void J3() {
    string line;
    vector<string> v;
    while (cin >> line) {
        istringstream iss(line);
        string s;
        while (getline(iss, s, ',')) {
            v.push_back(s);
        }
        sort(v.begin(), v.end());

        int n = v.size();
        for (int i = 0; i != n - 1; i++) {
            cout << v[i] << ',';
        }
        cout << v[n - 1] << endl;
        v.clear();
    }
}

#include <fstream>

// 从文件读入
void read_from_file() {
    ifstream infile("graph.txt");
    vector<vector<int>> matrix;
    istringstream iss;
    string line;
    vector<int> tmpvector;
    while (getline(infile, line)) {
        // 复用iss
        iss.str(line);
        int tmp;
        // 读入一行数据，存在向量中
        while (iss >> tmp) {
            tmpvector.push_back(tmp);
        }
        matrix.push_back(tmpvector);
        tmpvector.clear();
        // 复用iss需要clear
        iss.clear();
    }
    infile.close();
}

int main() {
    // A();
    // B();
    // D();
    // G();
    // H();
    // I();
    // J3();
    vector<string> data;
    string good;
    while (getline(cin, good, ',')) {
        data.push_back(good);
    }
    return 0;
}
