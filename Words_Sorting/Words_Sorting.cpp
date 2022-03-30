// sort words in ascending order of count and descending order of word

#include <iostream>
#include "Word.cpp"
#include <map>
#include <vector>
using namespace std;
// function declaration
int wordCount (string s, char seperator);
void split (string strings[], string s, char seperator);
int main() {
	string s = "i love you because you love me nobody love you because you love nobody";
	char seperator = ' ';
	int count = wordCount(s, seperator);
	string strings[count];
	split(strings, s, seperator);
	map<string, Word> myMap;
	for (int i=0; i<count; i++) {
		// already inserted
		if (myMap.find(strings[i]) != myMap.end()) {
			myMap.at(strings[i]).count++;
			//			myMap.at(strings[i]).print();
		}
		else {
			myMap.insert(pair<string,Word>(strings[i], Word(strings[i], 1)));
		}
	}

	// showing contents:
	// map<string,Word>::iterator it = myMap.begin();
	vector<Word> v;
//	cout << "myMap contains:\n";
	for (auto it=myMap.begin(); it!=myMap.end(); ++it) {
//		cout << it->first << " => " << (it->second).count << '\n';
		v.push_back(it->second);
	}

//	cout << v.size() << endl;
	// sort in ascending order of count and descending order of word
	struct customComp {
		inline bool operator()(const Word &a, Word &b) {
			int i = a.count - b.count;
			int j = b.word.compare(a.word);
			if (i != 0)
				return i < 0;
			// when a.count == b.count
			return j < 0;
		}
	};
	// Solution 1: using custom Comparator
//	sort(v.begin(), v.end(), customComp());

	// Solution 2: using overloading operator <
	sort(v.begin(), v.end());
	cout << "My vector now contains:\n";
	for (int i=0; i<v.size(); i++)
		cout << v.at(i);
	return 0;
}
// get how many count
int wordCount (string s, char seperator) {
	int len = s.length();
	int currIndex = 0, i = 0;
	while (i <= len) {
		if (s[i] == seperator || i == len)
			currIndex += 1;
		i++;
	}
	return currIndex;
}

// create custom split() function
void split (string strings[], string s, char seperator) {
	int len = s.length();
	int currIndex = 0, i = 0;
	int startIndex = 0, endIndex = 0;
	while (i <= len)
	{
		if (s[i] == seperator || i == len) {
			endIndex = i;
			string subStr = "";
			subStr.append(s, startIndex, endIndex - startIndex);
			strings[currIndex] = subStr;
			currIndex++;
			startIndex = endIndex + 1;
		}
		i++;
	}
}
