#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include<fstream>
#include"database.hpp"
#include <stdio.h>

vector<string> komoku_y;
vector<string> komoku_x;
vector<vector<string> > table;

string some;

int sort_x;//xの項目をソートするとき
int sort_y;//yの項目をソートするとき
int y;
int x;
bool mode;//trueが文字列falseが整数
bool updown;
ofstream outputfile;
 
void getdata(database& input){
	table = input.return_table();
	komoku_x = input.return_komoku_x();
	komoku_y = input.return_komoku_y();
}

void setdata(database& output){
	output.table=table;
	output.komoku_x=komoku_x;
	output.komoku_y=komoku_y;
}

struct node{
	int str;
	struct node *left;
	struct node *right;
};

bool compare_x_down(int x_comp){
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
bool compare_x_up(int x_comp){
	int comp=0;
	if(mode){
		while(1){
			if(table[sort_y][x_comp][comp]<table[sort_y][x][comp]) return true;
			else if(table[sort_y][x_comp][comp]>table[sort_y][x][comp]) return false;
			else if(table[sort_y][x_comp][comp]==0&&table[sort_y][x][comp]==0) return true;
			else comp +=1;
		}
	}	
	else{
		while(1){
			if(stoi(table[sort_y][x_comp])<stoi(table[sort_y][x])) return true;
			else if(stoi(table[sort_y][x_comp])>stoi(table[sort_y][x])) return false;
			else if(table[sort_y][x][0]==0) return true;
			else return true;
		}
	}
}
struct node *insert_x(struct node *yp){
	 if(yp==NULL){
		yp=(struct node *)malloc(sizeof(struct node));
		yp->str=x;
		x++;
	   yp->left=NULL;
		yp->right=NULL;
	}
	else if(updown){
		if(compare_x_down(yp->str)) yp->left = insert_x(yp->left);
		else yp->right = insert_x(yp->right);
		return yp;
	}
	else{
		if(compare_x_up(yp->str)) yp->left = insert_x(yp->left);
		else yp->right = insert_x(yp->right);
		return yp;
	}
}

void treeprint_x(struct node *yp,int y_val){
	if(yp!=NULL){
		treeprint_x(yp->left,y_val);
		outputfile<<" "<<table[y_val][yp->str];
	     	//for(int i=0;i<komoku_y.size();i++)cout << " "<<table[i][y->str];
	       	treeprint_x(yp->right,y_val);
	}
	//cout<<endl;
}
void treeprint_komoku_x(struct node *yp){
	if(yp!=NULL){
		treeprint_komoku_x(yp->left);
		outputfile<<" "<<komoku_x[yp->str];
	     	//for(int i=0;i<komoku_y.size();i++)cout << " "<<table[i][y->str];
	       	treeprint_komoku_x(yp->right);
	}
}

bool compare_y_down(int y_comp){
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
bool compare_y_up(int y_comp){
	int comp=0;
	if(mode){
		while(1){
			if(table[y_comp][sort_x][comp]<table[y][sort_x][comp]) return true;
			else if(table[y_comp][sort_x][comp]>table[y][sort_x][comp]) return false;
			else if(table[y_comp][sort_x][comp]==0&&table[y][sort_x][comp]==0) return true;
			else comp +=1;
		}
	}	
	else{
		while(1){
			if(stoi(table[y_comp][sort_x])<stoi(table[y][sort_x])) return true;
			else if(stoi(table[y_comp][sort_x])>stoi(table[y][sort_x])) return false;
			else if(table[y_comp][sort_x][0]==0&&table[y][sort_x][0]==0) return true;
			else return true;
		}
	}
}
struct node *insert_y(struct node *xp){
	 if(xp==NULL){
		xp=(struct node *)malloc(sizeof(struct node));
		xp->str=y;
		y++;
	   xp->left=NULL;
		xp->right=NULL;
	}
	else if(updown){
		if(compare_y_down(xp->str)) xp->left = insert_y(xp->left);
		else xp->right = insert_y(xp->right);
		return xp;
	}
	else{
		if(compare_y_up(xp->str)) xp->left = insert_y(xp->left);
		else xp->right = insert_y(xp->right);
		return xp;
	}
}

void treeprint_y(struct node *xp){
	if(xp!=NULL){
		treeprint_y(xp->left);
		outputfile<<endl;
		outputfile<<komoku_y[xp->str];
	   for(int i=0;i<komoku_x.size();i++)outputfile << " "<<table[xp->str][i];
		//cout<<endl;
	   treeprint_y(xp->right);
	}
}

void set_x(struct node *set,database& output){
	if(set!=NULL){
		set_x(set->left,output);
		output.komoku_x[x]=komoku_x[set->str];
		for(int i=0;i<komoku_y.size();i++) output.table[i][x]=table[i][set->str];
		x++;
		set_x(set->right,output);
	}
}
void set_y(struct node *set,database& output){
	if(set!=NULL){
		set_y(set->left,output);
		output.komoku_y[y]=komoku_y[set->str];
		for(int i=0;i<komoku_x.size();i++) output.table[y][i]=table[set->str][i];
		y++;
		set_y(set->right,output);
	}
}
void sort_komoku_x(database& input){
	struct node *root;
	root=NULL;
	for(auto i :komoku_x) root=insert_x(root);
	/*
	treeprint_komoku_x(root);
	//cout << endl;
	for(int i=0;i<komoku_y.size();i++) {
		outputfile<<endl;
		outputfile<<komoku_y[i];
		treeprint_x(root,i);
		//cout<<endl;
	}
	*/
	x=0;y=0;
	set_x(root,input);
}
void sort_komoku_y(database& input){
	struct node *root;
	root=NULL;
	for(auto i :komoku_y) root=insert_y(root);
	/*
	for(auto i :komoku_x) outputfile <<" "<<i;
	//cout<<endl;
	treeprint_y(root);
	*/
	x=0;y=0;
	set_y(root,input);
}
	
void sort_inf(database& input,bool p,int val,bool p2,bool p3){ //pがxy p2が降順昇順 p3が数字か文字か
	getdata(input);
	//outputfile.open("sort.txt");
	y=0;
	x=0;
	mode=p3;	
	updown=p2;
	if(p){ //Y
		sort_y=val;
		sort_komoku_x(input);
	}
	else{ //x
		sort_x=val;
		sort_komoku_y(input);
	}
	//outputfile.close();
	//sort_komoku_x();
	//sort_komoku_y();
}
void xy_conversion(database& input){
	getdata(input);
	input.komoku_y.clear();
	input.komoku_x.clear();
	input.table.clear();
	for(auto i:komoku_x) input.komoku_y.push_back(i);
	for(auto i:komoku_y) input.komoku_x.push_back(i);
	vector<string> table2;
	for(int i=0;i<komoku_x.size();i++){
		for(int j=0;j<komoku_y.size();j++){
			table2.push_back(table[j][i]);
		}
		input.table.push_back(table2);
		table2.clear();
	}
}
