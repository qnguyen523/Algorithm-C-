/*
 * Word.cpp
 *
 *  Created on: Mar 30, 2022
 *      Author: Quoc
 */
#include <iostream>
#include <string>
using namespace std;
class Word {
public:
	string word;
	int count;
	Word() {
		word = "";
		count = 0;
	}
	Word(string w, int c) {
		word = w; count = c;
	}
	void print() {
		cout << word << " " << count << endl;
	}
	// overloading operator <<
	friend ostream & operator << (ostream &out, const Word &w) {
		out << w.word << " " << w.count << endl;
		return out;
	}
	// sort in ascending order of count and descending order of word
	bool operator < (const Word &w) const {
		int i = count - w.count;
		int j = w.word.compare(word);
		if (i != 0)
			return i < 0;
		// when a.count == b.count
		return j < 0;
	}
};



