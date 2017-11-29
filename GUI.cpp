#include<iostream>
#include<string>
#include<vector>
#include"database.hpp"
#include"GUI.hpp"
#include"sort.hpp"
#include <cctype>
#include <algorithm>
using namespace std;

void GUI::display(database& input) {
	cout << "-----------------------" << endl;
	string str;
	int box=0;
	for (int i = 0; i < (int)input.komoku_y.size(); i++){
		if(input.strlen_conversion(komoku_y[i]) > box) box = input.strlen_conversion(komoku_y[i]); 
	}
	
	int boxx[(int)input.komoku_x.size()];
	for (int i = 0; i < (int)input.komoku_x.size();i++) boxx[i]=input.strlen_conversion(komoku_x[i]);//boxx[]の初期化
	for (int i = 0; i < (int)input.komoku_y.size(); i++){
		for (int j = 0; j < (int)input.komoku_x.size(); j++){
			if(boxx[j] < input.strlen_conversion(table[i][j])) boxx[j] = input.strlen_conversion(table[i][j]);
		}
	}
	
	for (int i = 0; i < box+1; i++) cout << " ";
	for (int i = 0; i < (int)input.komoku_x.size(); i++){
		cout << input.komoku_x[i] << " ";
		for(int j = 0; j < boxx[i] - input.strlen_conversion(komoku_x[i]);j++) cout << " ";
	}
	cout << endl;

	for (int i = 0; i < (int)input.komoku_y.size(); i++) {
		cout << input.komoku_y[i] << " ";
		for(int j = 0; j < box - input.strlen_conversion(komoku_y[i]);j++)cout << " ";
		for (int j = 0; j < (int)input.komoku_x.size(); j++) {
			cout << input.table[i][j] << " ";
			for(int k = 0; k < boxx[j] - input.strlen_conversion(table[i][j]);k++) cout << " ";
		}
		cout << endl;
	}
	cout << "-----------------------" << endl;
}

void GUI::update(database& input) {
	table = input.return_table();
	komoku_x = input.return_komoku_x();
	komoku_y = input.return_komoku_y();
}

void GUI::write(database& input) {
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

void GUI::add_komoku(database& input) {
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

void GUI::remove_komoku(database& input){
	int xory;
	string name;
	cout<<"横の項目を削除するなら0,縦の項目を削除するなら1を入力してください"<<endl;
	cin>>xory;
	cout<<"削除する項目名を入力してください"<<endl;
	cin>>name;
	if(xory==0){
		input.remove_komoku_x(name);
	}
	if(xory==1){
		input.remove_komoku_y(name);
	}
}

void GUI::sort(database& input) {
	bool xory;
	string name;
	int val;
	bool order,mode;
	cout<<"横の項目を並び替えるなら0,縦の項目を並び替えるなら1を入力してください"<<endl;
	cin>>xory;
	cout<<"並び替える項目の名前を入力してください"<<endl;
	cin>>name;
	cout<<"昇順にしたいなら0,降順にしたいなら1を入力してください"<<endl;
	cin>>order;
	cout<<"数字でソートなら0,文字列でソートなら1を入力してください"<<endl;
	cin>>mode;
	//database.sort(xory,name,order);
	
	//getdata(input);
	if(xory==false)val=input.search_x(name);
	else val=input.search_y(name);
	sort_inf(input,xory,val,order,mode);
	//setdata(input);
	//input.file_input("sort.txt");
}

void GUI::search(database& input) {
	int xory;
	string name;
	cout<<"横の項目から検索するなら0,縦の項目から検索するなら1を入力してください"<<endl;
	cin>>xory;
	cout<<"検索する項目名を入力してください"<<endl;
	cin>>name;
	int num;
	cout << "-----------------------" << endl;
	if(xory==0){
		num=input.search_x(name);
		cout << komoku_x[num] << endl;
		cout << "-----------------------" << endl;
		for (int i=0;i<(int)komoku_y.size();i++)cout << table[i][num]<<endl;
	}
	if(xory==1){
		num=input.search_y(name);
		cout << komoku_y[num]<<" |";
		for(int i=0;i<(int)komoku_x.size();i++)cout << table[num][i]<<" ";
		cout << endl;
	}
	cout << "-----------------------" << endl;
}

void GUI::file_output(database& input) {
	string name;
	cout<<"出力するファイル名=";
	cin>>name;
	input.file_output2(name);
	cout<<name<<"に出力が完了しました"<<endl;
}

void GUI::file_input(database& input){
	string name;
	cout<<"入力するファイル名=";
	cin>>name;
	if(input.file_input(name)) cout<<name<<"ファイルを読み込みました"<<endl;
	else cout<<"存在しないファイルです"<<endl;
}

void GUI::file_copy(){
	string str;
	string str2;
	cout<<"プリンタ名＝";
	cin>>str;
	cout<<"ファイル名＝";
	cin>>str2;
	copy(str,str2);
}

void GUI::data_clear(database& input){
	input.komoku_x.clear();
	input.komoku_y.clear();
	input.table.clear();
	string null;
	vector<string> table_f;
	cout <<"項目横=";
	cin>>null;
	input.komoku_x.push_back(null);
	cout <<"項目縦=";
	cin>>null;
	input.komoku_y.push_back(null);
	null="NULL";
	table_f.push_back(null);
	input.table.push_back(table_f);
}

void GUI::GUI_main(database& input) {
	int mode=0;
	string mode2;
	bool mode_p;
	char c[1023];
	while (mode!=7) {
		mode_p=true;
		update(input);
		display(input);
		//cout << "利用したい機能を選択してください" << endl;
		cout << "0  : 新規作成"<<endl;
		cout << "1  : 情報の書き込み" << endl;
		cout << "2  : データベース項目の追加" << endl;
		cout << "3  : データベース項目の削除" << endl;
		cout << "4  : 項目の並び替え" << endl;
		cout << "5  : 項目の検索" << endl;
		cout << "6  : データベース情報をファイル出力" << endl;
		cout << "7  : 終了" << endl;
		cout << "8  : xy反転" <<endl;
      cout <<"9  : データベース情報のファイル入力" << endl;
		cout <<"10 : テキストファイル印刷(Linux限定)" <<endl;
		c[0]='\n';
		while(c[0]=='\n'||c[0]==0){
		cin.getline(c,sizeof(c)); //mode選択
		}
		mode2=string(c);		
		for(int i=0;i<mode2.size();i++) {
			if(mode2[i]<'0'||mode2[i]>'9') mode_p=false;
			if(i==3) mode_p=false; 
	   }
		if(mode_p){
		mode=stoi(mode2);
		//cin>>mode;
		switch (mode){
		case 0:
			data_clear(input);
			break;
		case 1:
			write(input);
			break;
		case 2:
			add_komoku(input);
			break;
		case 3:
			remove_komoku(input);
			break;
		case 4:
			sort(input);
			break;
		case 5:
			search(input);
			break;
		case 6:
			file_output(input);
			break;
		case 7:
			cout << "終了します．" << endl;
			break;
		case 8:
			xy_conversion(input);
			break;
		case 9:
			file_input(input);
			break;
		case 10:
			file_copy();
			break;
		default:
			cout << "無効な数字です．入力し直してください" << endl;
			break;
		}
		}
		else cout << "無効な入力です．入力し直してください" << endl;
	}
}
