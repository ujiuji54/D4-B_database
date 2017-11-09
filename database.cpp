#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include<fstream>
#include"database.hpp"
#include <stdio.h>
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

/////////////////////////////////////////////以下ソート
/*
struct database::node{
	int str;
	struct node *left;
	struct node *right;
};

bool database::compare_x(int x_comp){
	int comp=0;
	if(mode){
		while(1){
			if(table[sort_y][x_comp][comp]<table[sort_y][x][comp]) return false;
			else if(table[sort_y][x_comp][comp]>table[sort_y][x][comp]) return true;
			else if(table[sort_y][x_comp][comp]==0&&table[sort_y][x][comp]==0) return false;
			else comp +=1;
		}
	}	
	else{
		while(1){
			if(stoi(table[sort_y][x_comp])<stoi(table[sort_y][x])) return false;
			else if(stoi(table[sort_y][x_comp])>stoi(table[sort_y][x])) return true;
			else if(table[sort_y][x][0]==0) return false;
			else return false;
		}
	}
}
struct database::node database::*insert_x(struct database::node *yp){
	 if(yp==NULL){
		yp=(struct database::node *)malloc(sizeof(struct database::node));
		yp->str=x;
		x++;
	   yp->left=NULL;
		yp->right=NULL;
	}
	else if(database::compare_x(yp->str)) yp->left = database::insert_x(yp->left);
	else yp->right = database::insert_x(yp->right);
	return yp;
}

void database::treeprint_x(struct node *yp,int y_val){
	if(yp!=NULL){
		treeprint_x(yp->left,y_val);
		cout<<" "<<table[y_val][yp->str];
	     	//for(int i=0;i<komoku_y.size();i++)cout << " "<<table[i][y->str];
	       	treeprint_x(yp->right,y_val);
	}
	//cout<<endl;
}
void database::treeprint_komoku_x(struct node *yp){
	if(yp!=NULL){
		treeprint_komoku_x(yp->left);
		cout<<" "<<komoku_x[yp->str];
	     	//for(int i=0;i<komoku_y.size();i++)cout << " "<<table[i][y->str];
	       	treeprint_komoku_x(yp->right);
	}
}

bool database::compare_y(int y_comp){
	int comp=0;
	if(mode){
		while(1){
			if(table[y_comp][sort_x][comp]<table[y][sort_x][comp]) return false;
			else if(table[y_comp][sort_x][comp]>table[y][sort_x][comp]) return true;
			else if(table[y_comp][sort_x][comp]==0&&table[y][sort_x][comp]==0) return false;
			else comp +=1;
		}
	}	
	else{
		while(1){
			if(stoi(table[y_comp][sort_x])<stoi(table[y][sort_x])) return false;
			else if(stoi(table[y_comp][sort_x])>stoi(table[y][sort_x])) return true;
			else if(table[y_comp][sort_x][0]==0&&table[y][sort_x][0]==0) return false;
			else return false;
		}
	}
}
struct database::node database::*insert_y(struct database::node *xp){
	 if(xp==NULL){
		xp=(struct database::node *)malloc(sizeof(struct database::node));
		xp->str=y;
		y++;
	   xp->left=NULL;
		xp->right=NULL;
	}
	else if(database::compare_y(xp->str)) xp->left = database::insert_y(xp->left);
	else xp->right = database::insert_y(xp->right);
	return xp;
}

void database::treeprint_y(struct node *xp){
	if(xp!=NULL){
		treeprint_y(xp->left);
		cout<<komoku_y[xp->str];
	   for(int i=0;i<komoku_x.size();i++)cout << " "<<table[xp->str][i];
		cout<<endl;
	   treeprint_y(xp->right);
	}
}

void database::sort_komoku_x(){
	struct node *root;
	root=NULL;
	for(auto i :komoku_x) root=insert_x(root);
	treeprint_komoku_x(root);
	cout << endl;
	for(int i=0;i<komoku_y.size();i++) {
		cout<<komoku_y[i];
		treeprint_x(root,i);
		cout<<endl;
	}
}
void database::sort_komoku_y(){
	struct node *root;
	root=NULL;
	for(auto i :komoku_y) root=insert_y(root);
	for(auto i :komoku_x) cout <<" "<<i;
	cout<<endl;
	treeprint_y(root);
}
void database::sort_inf(){
	y=0;
	x=0;
	mode=false;
	sort_x=2;
	sort_y=2;
	//sort_komoku_x();
	sort_komoku_y();
}
*/
/////////////////////////////////////////////
