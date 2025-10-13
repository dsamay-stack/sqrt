#include <iostream>
#include <string>
#include <vector>
#include <cwctype>
#include <clocale>
using namespace std;

static wstring tolower_all(const wstring& s) {
    wstring r = s; for (auto& ch : r) ch = towlower(ch); return r;
}

static bool is_word_char(wchar_t c) {
    return iswalnum(c) != 0 || c == L'_';
}

static vector<int> find_whole_words_icase(const wstring& text, const wstring& word) {
    vector<int> pos; if (word.empty()) return pos;
    wstring t = tolower_all(text), w = tolower_all(word);
    size_t start = 0, n = w.size(), m = t.size();
    while (true) {
        size_t i = t.find(w, start);
        if (i == wstring::npos) break;
        bool left_ok = (i == 0) || !is_word_char(t[i - 1]);
        bool right_ok = (i + n >= m) || !is_word_char(t[i + n]);
        if (left_ok && right_ok) pos.push_back(static_cast<int>(i) + 1);
        start = i + 1;
    }
    return pos;
}

int main() {
    _wsetlocale(LC_ALL, L"");

    wcout << L"¬вед≥ть р€док: ";
    wstring text; getline(wcin, text);

    wcout << L"¬вед≥ть слово дл€ пошуку: ";
    wstring word; getline(wcin, word);

    auto positions = find_whole_words_icase(text, word);
    if (positions.empty()) {
        wcout << L"—лово \"" << word << L"\" не знайдено.\n";
    }
    else {
        wcout << L"«найдено \"" << word << L"\" на позиц≥€х: ";
        for (size_t i = 0;i < positions.size();++i) { if (i) wcout << L", "; wcout << positions[i]; }
        wcout << L"\n";
    }
    return 0;
}
