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
		//�f�o�b�O�p�f�[�^���i�[

	public:
		void write(int x, int y, string input);//�w�肵�����W�̗v�f������������
		void display();//�[���ɕ\��
		void add_komoku_x(string input);//����x�ǉ�
		void add_komoku_y(string input);//����y�ǉ�
		void file_output();//�t�@�C���o��
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