#include<iostream>
#include<string>
#include<vector>
using namespace std;

class database{
	private:
		vector<vector<string>> table = {
			{"1","2","3"},
			{"4","5","6"},
			{"7","8","9"},
		};
		vector<string> komoku_x = {"a","b","c"};
		vector<string> komoku_y = { "d","e","f" };
		int longest_string_size = 1;
		//デバッグ用データを格納

	public:
		void write(int x, int y, string input);//指定した座標の要素を書き換える
		void display();//端末に表示
		void add_komoku_x(string input);//項目x追加
		void add_komoku_y(string input);//項目y追加
		void file_output();//ファイル出力
};

inline void database::write(int x, int y, string input) {
	if (table[0].size() < x && table.size() < y) {
		cout << "error" << endl;
		return;
	}
	table[y][x] = input;
}

inline void database::display() {
	cout << "-----------------------" << endl;
	for (int i = 0; i < longest_string_size+1; i++)cout << " ";
	for (int i = 0; i < komoku_x.size(); i++)cout << komoku_x[i]<<" ";
	cout << endl;

	for (int i = 0; i < table.size(); i++) {
		cout << komoku_y[i] << " ";
		for (int j = 0; j < table[i].size(); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------------------" << endl;
}

inline void database::add_komoku_x(string input) {
	
}

inline void database::add_komoku_y(string input) {
	
}

inline void database::file_output() {

}