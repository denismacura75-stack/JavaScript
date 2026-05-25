#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

bool isNumber(const string& s) {
    bool hasDigit = false;
    bool hasDot = false;

    for (char c : s) {
        if (isdigit(c)) {
            hasDigit = true;
        }
        else if (c == '.' && !hasDot) {
            hasDot = true;
        }
        else {
            return false;
        }
    }
    return hasDigit;
}

bool isLatin(const string& s) {
    for (char c : s) {
        if (!isalpha(c) || !(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z')) {
            return false;
        }
    }
    return !s.empty();
}

int main() {
    try {
        ifstream infile("input.txt");
        if (!infile) throw runtime_error("Cannot open input.txt");

        stringstream buffer;
        buffer << infile.rdbuf();
        string text = buffer.str();
        infile.close();

        string copied_text = text;

        vector<string> words;
        string temp;

        for (char c : text) {
            if (isalnum(c) || c == '.') {
                temp += c;
            }
            else {
                if (!temp.empty()) {
                    words.push_back(temp);
                    temp.clear();
                }
            }
        }
        if (!temp.empty()) words.push_back(temp);

        int number_count = 0;
        vector<string> latin_words;

        for (const string& w : words) {
            if (isNumber(w)) number_count++;
            if (isLatin(w)) latin_words.push_back(w);
        }

        vector<string> filtered;
        for (size_t i = 0; i < words.size(); i++) {
            if (i % 2 == 0) filtered.push_back(words[i]);
        }

        stringstream result;

        result << "=== TEXT COPY ===\n" << copied_text << "\n\n";
        result << "Number of values: " << number_count << "\n\n";

        result << "Latin words:\n";
        for (const string& w : latin_words) {
            result << w << " ";
        }
        result << "\n\n";

        result << "Text without every second word:\n";
        for (const string& w : filtered) {
            result << w << " ";
        }

        cout << result.str();

        ofstream outfile("output.txt");
        if (!outfile) throw runtime_error("Cannot create output.txt");

        outfile << result.str();
        outfile.close();

    }
    catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}