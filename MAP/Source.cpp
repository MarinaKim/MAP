#include<iostream>
#include<string>
#include<map>
#include<fstream>
using namespace std;
/* map-ассоциативный контейнер
хранит значения в паре, по двум св-м: 1- ключ (first), 2- значение(second)
ключ уникальный
в map элементы стоят в отсортированном порядке по ключу
*/
int main() {
	int n;
	cout << "num:";
	cin >> n;
	switch (n) {
	case 1: {
		map<string, string>fruits;
		fruits["apple"] = "green";
		fruits["banana"] = "yellow";
		fruits["apple"] = "red";
		fruits["ananas"] = "brown";

		for (map<string, string>::iterator it = fruits.begin();it != fruits.end();it++)
			cout << it->first << "\t" << it->second << endl; //first-ключ, second-значение
	}break;
	case 2: {
		map<int, string>fruits;
		fruits[1] = "green";
		fruits[5] = "yellow";
		fruits[6] = "red";
		fruits[3] = "brown";

		fruits.erase(3);//удаление с указание ключа
		for (map<int, string>::iterator it = fruits.begin();it != fruits.end();it++)
			cout << it->first << "\t" << it->second << endl; //выводит список сортированный по ключам

		cout << "------------------------------------------------------------------" << endl;
		auto it = fruits.find(5); //тип итератора, автоматически будет сам определять тип используемого итератора
		//find ищет по ключу
		cout << it->second << endl;
	}break;

		//используется для словаря, т.к. для поска тратиться логарифмическое время
		//dictionary
	case 3: {
		map<string, string> dict;
		ifstream in_file("dictionary.txt");
		string word, description;
		if (!in_file) {
			cerr << "file open error" <<endl;
		}
		else {
			while (!in_file.eof()) {
				getline(in_file, word, '/');
				getline(in_file, description);
				dict[word] = description;
			}
		}

		for (auto it = dict.begin();it != dict.end(); it++)
			cout << it->first << "\t" << it->second << endl;
		cout << "------------------------------------------------------------------------" << endl;
		int choice;
		while (true) {
			cout << "Choce:";			
			cout << "1-add a word" << endl;
			cout << "2-delete" << endl;
			cout << "3-search" << endl;
			cout << "4-edit" << endl;
			cout << "0-exit" << endl;
			cin >> choice;
			if (choice == 0) break;
			switch (choice) {
			case 1: {
				cout << "Enter a word:";
				cin >> word;
				cout << "Enter a description:";
				cin >> description;
				dict[word] = description;

				for (auto it = dict.begin();it != dict.end(); it++)
					cout << it->first << "\t" << it->second << endl;
				cout << "------------------------------------------------------------------------" << endl;

			}break;

			case 2:{
				cout << "Enter a word:";
				cin >> word;
				/*auto itr = dict.find(strstr(dict.begin()->first.c_str(), word.c_str()));
				*/
				auto itr = dict.find(word);
				if (itr != dict.end())
					dict.erase(itr->first);

				for (auto it = dict.begin();it != dict.end();it++) {				
					cout << it->first << endl << it->second <<endl;
				}
				cout << "------------------------------------------------------------------------" << endl;

			}break;

			case 3: {
				cout << "Enter a word:";
				cin >> word;
				for (auto it = dict.begin();it != dict.end();it++) {
					if (strstr(it->first.c_str(), word.c_str()));//поиск подслова
					cout << it->first << endl << it->second << endl << endl;
				}
			}break;

			case 4: {
				int ch;
				cout << "Choce:";
				cout << "1-edit a word" << endl;
				cout << "2-edit a description" << endl;
				cout << "0-exit" << endl;
				cin >> ch;
				if (ch == 0) break;
				switch (ch) {
				case 1: {
					cout << "Enter a word:";
					cin >> word;
					auto itr = dict.find(word);
					string nword;
					cout << "Enter new word:";
					cin >> nword;
					dict[nword] = itr->second;
					dict.erase(itr->first);
					for (auto it = dict.begin();it != dict.end();it++) {
						cout << it->first << endl << it->second << endl;
					}
				}break;

				case 2: {
					cout << "Enter a word:";
					cin >> word;
					auto itr = dict.find(word);
					string ndesc;
					cout << "Enter new description:";
					/*cin >> ndesc;*/
					cin.ignore();
					getline(cin, ndesc);
					dict[itr->first] = ndesc;
				
					for (auto it = dict.begin();it != dict.end();it++) {
						cout << it->first << endl << it->second << endl;
					}
				}break;
				}
			}break;
			}
		}
	}break;

	case 4: {
		ifstream in_file("dictionary.txt");
		string word;
		map<string, int> words;
		if (!in_file) {
			cerr << "file open error." << endl;
		}
		else {
			while (!in_file.eof()) {
				in_file >> word;
				words[word]++;
			}
		}
		for (auto it = words.begin(); it != words.end();it++)
			cout << it->first << "\t" << it->second << endl;
	}break;

	case 5: {
		ifstream in_file("dictionary.txt");
		char word;
		map<char, int> words;
		if (!in_file) {
			cerr << "file open error." << endl;
		} 
		else {
			while (!in_file.eof()) {
				in_file >> word;
				words[word]++;
			}
		}
		for (auto it = words.begin(); it != words.end();it++)
			cout << it->first << "\t" << it->second << endl;

	}break;
	}
	system("pause");
	return 0;
}