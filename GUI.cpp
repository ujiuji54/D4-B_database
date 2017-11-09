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

void GUI::write(database input) {
	string x;
	string y;
	string inf;
	cout << "データを入力するモードです。座標指定後、データを入力します。" << endl;
	cout << "横の項目名を入力してください" << endl;
	cin >> x;
	cout << "縦の項目名を入力してください" << endl;
	cin >> y;
	cout << "情報を入力してください" << endl;
	cin >> inf;
	input.write(x,y,inf);
}

void GUI::add_komoku(database input) {
	int xory;
	string name;
	cout<<"横の項目を追加するなら0,縦の項目を追加するなら1を入力してください"<<endl;
	cin>>xory;
	cout<<"追加する項目名を入力してください"<<endl;
	cin>>name;
	if(xory==0){
		input.add_komoku_x(name);
	}
	if(xory==1){
		input.add_komoku_y(name);
	}
}

void GUI::sort(database input) {
	bool xory;
	string name;
	bool order;
	cout<<"横の項目を並び替えるなら0,縦の項目を並び替えるなら1を入力してください"<<endl;
	cin>>xory;
	cout<<"並び替える項目の名前を入力してください"<<endl;
	cin>>name;
	cout<<"昇順にしたいなら0,降順にしたいなら1を入力してください"<<endl;
	cin>>order;
		//database.sort(xory,name,order);
}

void GUI::search(database input) {
	int xory;
	string name;
	cout<<"横の項目から検索するなら0,縦の項目から検索するなら1を入力してください"<<endl;
	cin>>xory;
	cout<<"検索する項目名を入力してください"<<endl;
	if(xory==0){
		input.search_x(name);
	}
	if(xory==1){
		input.search_y(name);
	}
}

void GUI::file_output(database input) {
	input.file_output();
	cout<<"test.txtに出力が完了しました"<<endl;
}

void GUI::GUI_main(database input) {
	int mode=0;
	while (mode!=6) {
		update(input);
		display();
		//cout << "利用したい機能を選択してください" << endl;
		cout << "1  : 情報の書き込み" << endl;
		cout << "2  : データベース項目の追加" << endl;
		cout << "3  : 項目の並び替え" << endl;
		cout << "4  : 項目の検索" << endl;
		cout << "5  : データベース情報をファイル出力" << endl;
		cout << "6  : 終了" << endl;
		cin >> mode; //mode選択
		switch (mode){
		case 1:
			write(input);
			break;
		case 2:
			add_komoku(input);
			break;
		case 3:
			sort(input);
			break;
		case 4:
			search(input);
			break;
		case 5:
			file_output(input);
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
