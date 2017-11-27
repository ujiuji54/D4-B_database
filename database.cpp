#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include<fstream>
#include"database.hpp"
#include <stdio.h>
//#include <locale.h>
using namespace std;
vector<vector<string> > database::return_table() { return table; }
vector<string> database::return_komoku_x() { return komoku_x; }
vector<string> database::return_komoku_y() { return komoku_y; }

void database::write(string x_name, string y_name, string input) {
	//指定した座標の要素を書き換える
	int x, y;
	x = search_x(x_name);
	y = search_y(y_name);
	if (table[0].size() < x || table.size() < y) {
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

void database::file_output(string name) {
	//ファイル出力
	ofstream outputfile(name);
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
int database::strlen_conversion(string str){
	int len,len2,i;
	len=0;
	len2=0;
	i=0;
	while(str[i]!=0){		
		if(str[i]<128&&str[i]>=0)len+=1;
		else len2+=1;
		i+=1;
	}
	return len+(len2/3*2);
}
void database::file_output2(string name){
	ofstream outputfile(name);	
	string str;
	int box=0;
	int box2=0;
	int k=0;
	int len;
	for (int i = 0; i < komoku_y.size(); i++){
		if(strlen_conversion(komoku_y[i]) > box) box=strlen_conversion(komoku_y[i]);
	}
	int boxx[komoku_x.size()];
	int boxx2;
	for (int i = 0; i < komoku_x.size();i++) boxx[i]=strlen_conversion(komoku_x[i]);//boxx[]の初期化;//boxx[]の初期化
	for (int i = 0; i < komoku_y.size(); i++){
		for (int j = 0; j < komoku_x.size(); j++){
			if(boxx[j]<strlen_conversion(table[i][j])) boxx[j]=strlen_conversion(table[i][j]);
			//if(boxx[j] < table[i][j].size()) boxx[j] = table[i][j].size();
		}
	}
	for (int i = 0; i < box+1; i++) outputfile<<" ";
	outputfile << komoku_x[0];
	for (int i = 1; i < komoku_x.size(); i++){
		//outputfile << komoku_x[i] << " ";
		for(int j = 0; j < boxx[i-1] - strlen_conversion(komoku_x[i-1]);j++) outputfile << " ";
		outputfile << " "<<komoku_x[i];
	}
	//cout << endl;

	for (int i = 0; i < komoku_y.size(); i++) {
		outputfile<<endl;
		outputfile << komoku_y[i] << " ";
		for(int j = 0; j < box - strlen_conversion(komoku_y[i]);j++)outputfile << " ";
		outputfile << table[i][0];
		for (int j = 1; j < komoku_x.size(); j++) {
			for(int k = 0; k < boxx[j-1] - strlen_conversion(table[i][j-1]);k++) outputfile << " ";
			outputfile <<" "<<table[i][j];
			//for(int k = 0; k < boxx[j] - table[i][j].size();k++) outputfile << " ";
		}
		//cout << endl;
	}
}

void database::file_input(string name){
	char c = 0;
	string s;
	vector<string> data_str;
	komoku_x.clear();//念のためclear
	komoku_y.clear();//念のためclear
	table.clear();//念のためclear
	ifstream inputfile(name);
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
	/*
	for (int i = 0; i<size_x; i++) cout<< " " << komoku_x[i];
	for (int i = 0; i<size_y; i++) {
		cout << endl;
		cout << komoku_y[i];
		for (int j = 0; j<size_x; j++) cout << " " << table[i][j];

	}
	cout << endl;
	*/
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
