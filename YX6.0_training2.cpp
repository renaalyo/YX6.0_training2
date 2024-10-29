#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
typedef unsigned long int uli;

using namespace std;

int main()
{
    uli a,b,c,d;
    cin >> a >> b >> c >> d;
    vector<pair<uli, uli>> v1;
    if (a > 0 && c > 0) {
        v1.push_back({ b + 1, d + 1 });
    }
    if (b > 0 && d > 0) {
        v1.push_back({ a + 1, c + 1 });
    }
    if (a > 0 && b > 0) {
        v1.push_back({ max(a,b) + 1, 1});
    }
    if (c > 0 && d > 0) {
        v1.push_back({1, max(c,d) + 1 });
    }
    auto minElement = min_element(v1.begin(), v1.end(),
        [](const pair<uli, uli>& a, std::pair<uli, uli>& b) {
            return (a.first + a.second) < (b.first + b.second);
        });
    cout << minElement->first << " " << minElement->second << "\n";
    return 0;
}
