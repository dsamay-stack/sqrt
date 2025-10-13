
#include <iostream>
#include <string>
#include <vector>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
using namespace std;

wchar_t tolower_unicode(wchar_t c) {
    wchar_t buf[2] = { c, L'\0' };
    CharLowerBuffW(buf, 1); 
    return buf[0];
}

int main() {

    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    wcout << L"Введіть рядок: ";
    wstring s;
    getline(wcin, s);   

    wcout << L"Введіть літеру для пошуку: ";
    wchar_t ch;
    wcin >> ch;

    const wchar_t target = tolower_unicode(ch);

    vector<int> positions; 
    for (size_t i = 0; i < s.size(); ++i) {
        if (tolower_unicode(s[i]) == target) {
            positions.push_back(static_cast<int>(i) + 1);
        }
    }

    if (positions.empty()) {
        wcout << L"Символ '" << ch << L"' не знайдено." << endl;
    }
    else {
        wcout << L"Позиції символу '" << ch << L"': ";
        for (size_t i = 0; i < positions.size(); ++i) {
            if (i) wcout << L", ";
            wcout << positions[i];
        }
        wcout << endl;
    }
    return 0;
}
