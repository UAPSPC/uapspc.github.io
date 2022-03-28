#include <iostream>
#include <string>

using namespace std;

bool ends_with(string const& str, string const& suffix) {
    return str.size() >= suffix.size() && str.compare(str.size()-suffix.size(), suffix.size(), suffix) == 0;
}

int main() {
    string s;
    getline(cin, s);
    cout << (ends_with(s, "eh?")?"Canadian!":"Imposter!") << endl;
    return 0;
}
