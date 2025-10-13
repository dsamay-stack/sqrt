#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
using namespace std;

wchar_t tolower_unicode(wchar_t c) {
    wchar_t buf[2] = { c, L'\0' };
    CharLowerBuffW(buf, 1);      // WinAPI
    return buf[0];
}

int main() {
  
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    wcout << L"Введіть рядок: ";
    wstring s;
    getline(wcin, s);

    wcout << L"Введіть літери для пошуку (можна підряд або через пробіли/коми): ";
    wstring letters_line;
    getline(wcin, letters_line);

    
    vector<wchar_t> query_letters_order;  
    unordered_set<wchar_t> seen;
    for (wchar_t ch : letters_line) {
        if (ch == L' ' || ch == L',' || ch == L';' || ch == L'\t') continue;
        wchar_t low = tolower_unicode(ch);
        if (!seen.count(low)) {
            seen.insert(low);
            query_letters_order.push_back(ch); 
        }
    }

    if (query_letters_order.empty()) {
        wcout << L"Літери для пошуку не задані." << endl;
        return 0;
    }

    unordered_map<wchar_t, vector<int>> pos_map;

    for (size_t i = 0; i < s.size(); ++i) {
        wchar_t c_low = tolower_unicode(s[i]);
        if (seen.count(c_low)) {
            pos_map[c_low].push_back(static_cast<int>(i) + 1);
        }
    }

    for (wchar_t orig : query_letters_order) {
        wchar_t key = tolower_unicode(orig);
        const auto it = pos_map.find(key);
        if (it == pos_map.end() || it->second.empty()) {
            wcout << L"Символ '" << orig << L"' не знайдено." << endl;
        }
        else {
            wcout << L"Позиції символу '" << orig << L"': ";
            const auto& v = it->second;
            for (size_t i = 0; i < v.size(); ++i) {
                if (i) wcout << L", ";
                wcout << v[i];
            }
            wcout << endl;
        }
    }

    return 0;
}
