#include<iostream>
#include<string>
#include<vector>
#include"database.hpp"
using namespace std;

inline vector<vector<string>> database::return_table() { return table; }
inline vector<string> database::return_komoku_x() { return komoku_x; }
inline vector<string> database::return_komoku_y() { return komoku_y; }

inline void database::write(int x, int y, string input) {
	//�w�肵�����W�̗v�f������������
	if (table[0].size() < x && table.size() < y) {
		cout << "error" << endl;
		return;
	}
	table[y][x] = input;
}


inline void database::add_komoku_x(string input) {
	//����x�ǉ�(input:���ږ�)
}

inline void database::add_komoku_y(string input) {
	//����y�ǉ�(input:���ږ�)
}

inline void database::file_output() {
	//�t�@�C���o��
}

inline int database::search_x(string name) {
	//����x���疼�O������(name:���ږ�)
}

inline int database::search_y(string name) {
	//����y���疼�O������(name:���ږ�)
}

inline void database::sort(bool komoku, int n, bool order) {
	//����x���\�[�g(komoku:x��y��,n:vecter[n],order:�������~����)
}