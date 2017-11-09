#include<iostream>
#include<string>
#include<vector>
#include"database.hpp"
#include"GUI.hpp"
using namespace std;

void GUI::display() {
	cout << "-----------------------" << endl;
	string str;
	int box=0;
	for (int i = 0; i < komoku_y.size(); i++){
		if(komoku_y[i].size() > box) box = komoku_y[i].size(); 
	}
	
	/*string boxx;
	for (int i = 0; i < table.size(); i++){
		for (int j = 0; j < table[i].size(); j++){
			if(boxx[j] << table[i][j].size()) boxx[j] = table[i][j].size();
			cout << table[i][j].size() << endl;
		}
	}*/
	
	for(int j = 0; j <= box; j++) cout << " ";
	
	for (int i = 0; i < komoku_x.size(); i++){
		cout << komoku_x[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < table.size(); i++) {
		cout << komoku_y[i] << " ";
		for(int j = 0; j < box - komoku_y[i].size();j++) cout << " ";
		for (int j = 0; j < table[i].size(); j++) {
			cout << table[i][j] << " ";
			//for(int a = 0; a < boxx[j] - table[i][j].size();a++) cout << " ";
		}
		cout << endl;
	}
	cout << "-----------------------" << endl;
}


void GUI::update(database input) {
	table = input.return_table();
	komoku_x = input.return_komoku_x();
	komoku_y = input.return_komoku_y();
}

void GUI::write() {
	string x;
	string y;
	string inf;
	cout << "データを入力するモードです。座標指定後、データを入力します。"　<< endl;
	cout << "横の項目を選択してください" << endl;
	cin >> x;
	cout << "縦の項目を選択してください" << endl;
	cin >> y;
	cout << "情報を入力してください" << endl;
	cin >> inf;
	database.write(x,y,inf)
}

void GUI::add_komoku() {}

void GUI::sort() {}

void GUI::search() {}

void GUI::file_output() {}

void GUI::GUI_main(database input) {
	int mode=0;
	while (mode!=6) {
		update(input);
		display();
		cout << "利用したい機能を選択してください" << endl;
		cout << "1  : 情報の書き込み" << endl;
		cout << "2  : データベース項目の追加" << endl;
		cout << "3  : 項目の並び替え" << endl;
		cout << "4  : 項目の検索" << endl;
		cout << "5  : データベース情報をファイル出力" << endl;
		cout << "6  : 終了" << endl;
		cin >> mode; //mode選択
		switch (mode){
		case 1:
			write();
			break;
		case 2:
			add_komoku();
			break;
		case 3:
			sort();
			break;
		case 4:
			search();
			break;
		case 5:
			file_output();
			break;
		case 6:
			cout << "終了します．" << endl;
			break;
		default:
			cout << "無効な数字です．入力し直してください" << endl;
			break;
		}
	}
}
