#include<iostream>
#include<vector>
#include"database.hpp"
#include"GUI.hpp"
#include"sort.hpp"
using namespace std;

int main() {

	//デバッグ用コード
	database database;
	GUI GUI;
	
	//データベース開発用デバッグコード
	//GUI.update(database);
	//GUI.display();
	//cout << database.search_x("c") << endl; //ここをデバッグしたい関数に変える。

	//GUI.GUI_main(database);
	getdata(database);
	/*  input output のテストよう
	database.file_output();
	database.file_input();
	*/
	sort_inf();
	return 0;

}
