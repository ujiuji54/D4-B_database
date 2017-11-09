#include<iostream>
#include<string>
#include<vector>
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
}

void database::add_komoku_y(string input) {
	//項目y追加(input:項目名)
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
	return 0;
}

int database::search_y(string name) {
	//項目yから名前を検索(name:項目名)
	return 0;
}

void database::sort(bool komoku, string name, bool order) {
	//項目xをソート(komoku:xかyか,n:vecter[n],order:昇順か降順か)
}

void database::sort_1(int x){
	vector<vector<string> > table_sort;
	int len=komoku_x.size();
	int y=0;
	struct node{
 		vector<string> number;
 		//int count;
		struct node *left;
		struct node *right;
	};
	struct node *insert(struct node *x){
 		if(x==NULL){
  			for (int i=0;i<len;i++) x->number.push_back(table[y][len]);
  			//strcpy(x->number,a);
  			//x->count=1;
  			x->left=NULL;
  			x->right=NULL;
  		}
 		else{
  			//int p=0;
  			//p=strcmp(x->number,a);
  			if(p==0) x->count+=1;
  			else if(a[0]<x->number[0]) x->left = insert(x->left,a);
  			else x->right = insert(x->right,a);
 		}
 		return x;
	}
	void treeprint(struct node *x){
 		if(x!=NULL){
  			treeprint(x->left);
  			printf("%s : %d \n",x->number,x->count);
  			treeprint(x->right);
 		}
	}






	
}
