#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include<fstream>
#include"database.hpp"
using namespace std;

vector<vector<string> > database::return_table() { return table; }
vector<string> database::return_komoku_x() { return komoku_x; }
vector<string> database::return_komoku_y() { return komoku_y; }

void database::write(string x_name, string y_name, string input) {
	//指定した座標の要素を書き換える
	int x, y;
	x = search_x(x_name);
	y = search_y(y_name);
	if (table[0].size() < x && table.size() < y) {
		cout << "error" << endl;
		return;
	}
	table[y][x] = input;
}


void database::add_komoku_x(string input) {
	//項目x追加(input:項目名)
	int y_size=table.size();
	komoku_x.push_back(input);
	for(int i=0; i<y_size; i++){
		table[i].push_back("NULL");
	}
	
	
}

void database::add_komoku_y(string input) {
	//項目y追加(input:項目名)
	int x_size=table[0].size();
	int y_size=table.size();
	vector<string> str;
	komoku_y.push_back(input);
	for(int i=0; i<x_size; i++){
		str.push_back("NULL");		
	}
	table.push_back(str);
}

void database::remove_komoku_x(string input) {
	int num = search_x(input);
	int y_size=table.size();
	komoku_x.erase(komoku_x.begin()+num);
	for(int i=0; i<y_size; i++){
		table[i].erase(table[i].begin()+num);
	}
}

void database::remove_komoku_y(string input) {
	int num = search_y(input);
	int x_size=table[0].size();
	komoku_y.erase(komoku_y.begin()+num);
	table.erase(table.begin()+num);
}	

void database::file_output() {
	//ファイル出力
	ofstream outputfile("test.txt");
   int size_x=(int)komoku_x.size();
   int size_y=(int)komoku_y.size();
	for(int i=0;i<size_x;i++) outputfile<<" "<<komoku_x[i];
	for(int i=0;i<size_y;i++){
		outputfile<<endl;
      outputfile<<komoku_y[i];
		for(int j=0;j<size_x;j++) outputfile<<" "<<table[i][j];
   }
   outputfile.close();
}

void database::file_input(){
	char c = 0;
	string s;
	vector<string> data_str;
	komoku_x.clear();//念のためclear
	komoku_y.clear();//念のためclear
	table.clear();//念のためclear
	ifstream inputfile("test.txt");
	//ofstream outputfile("test2.txt");
	while (1) {
		inputfile >> s;
		komoku_x.push_back(s);
		inputfile.get(c);
		if (c == 10) break;
	}
	while ((inputfile >> s)) {
		komoku_y.push_back(s);
		inputfile.get(c);
		for (auto i : komoku_x) {
			inputfile >> s;
			data_str.push_back(s);
		}
		table.push_back(data_str);
		data_str.clear();
	}
	int size_x = (int)komoku_x.size();
	int size_y = (int)komoku_y.size();
	for (int i = 0; i<size_x; i++) cout<< " " << komoku_x[i];
	for (int i = 0; i<size_y; i++) {
		cout << endl;
		cout << komoku_y[i];
		for (int j = 0; j<size_x; j++) cout << " " << table[i][j];

	}
	cout << endl;
	inputfile.close();
	//outputfile.close();
}

int database::search_x(string name) {
	//項目xから名前を検索(name:項目名)
	for (int i = 0; i < komoku_x.size(); i++) {
		if(komoku_x[i] == name)return i;
	}
	return -1;
}

int database::search_y(string name) {
	//項目yから名前を検索(name:項目名)
	for	(int i = 0; i < komoku_y.size(); i++) {
		if (komoku_y[i] == name)return i;
	}
	return -1;
}

void database::sort(bool komoku, string name, bool order) {
	//項目xをソート(komoku:xかyか,n:vecter[n],order:昇順か降順か)
	
}
