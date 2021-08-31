// 123401234
#include <string>
#include <vector>

using namespace std;

vector<string> ips;
string ip;

void dfs(string& s, int k, string& ip, int idx) {
    if (k == 0) {
        if (idx == s.length()) {
            ips.push_back(ip.substr(0, ip.length() - 1));
        }
        return;
    }
    for (int i = 1; i <= 3; i++) {
        if (idx + i > s.length()) {
            continue;
        }
        string section = s.substr(idx, i);
        if (i == 3 && stoi(section) > 255) {
            continue;
        }
        ip += section;
        ip += ".";
        dfs(s, k - 1, ip, idx + i);
        for (int j = 0; j < i + 1; j++) {
            ip.pop_back();
        }
    }
}

vector<string> valid_ips(string& s) {
    dfs(s, 4, ip, 0);
    return ips;
}
