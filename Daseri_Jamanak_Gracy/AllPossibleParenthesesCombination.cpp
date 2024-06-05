#include <iostream>
#include <memory>
#include <string>
#include <vector>

void f(std::string& str, int openCount, int closeCount, int n,
    std::vector<std::string>& ans) {
    if ((openCount > n || closeCount > n) || (closeCount - openCount > 0))
        return;

    if (str.size() == 2 * n) {
        ans.push_back(str);
        return;
    }
    str.push_back('(');
    f(str, openCount + 1, closeCount, n, ans);
    str.pop_back();

    str.push_back(')');
    f(str, openCount, closeCount + 1, n, ans);
    str.pop_back();
}

int main() {
    std::string str;
    std::vector<std::string> ans;
    int n;
    std::cin >> n;
    f(str, 0, 0, n, ans);
    for (std::string& x : ans) {
        std::cout << x << std::endl;
    }
    return 0;
}