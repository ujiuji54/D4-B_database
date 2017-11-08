#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> komoku_y={"1","2","3","4"};
vector<string> komoku_x={"1","2","3"};
vector<vector<string> > table={
	{"aa","bb","1000"},
	{"dd","ee","500"},
	{"cc","aa","70"},
	{"cc","cc","450"},
};
int sort_x;//xの項目をソートするとき
int sort_y;//yの項目をソートするとき
int y;
int x;
bool mode;//trueが文字列falseが整数


struct node{
	int str;
	struct node *left;
	struct node *right;
};

bool compare_x(int x_comp){
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
struct node *insert_x(struct node *y){
	 if(y==NULL){
		y=(struct node *)malloc(sizeof(struct node));
		y->str=x;
		x++;
	        y->left=NULL;
		y->right=NULL;
	}
	else if(compare_x(y->str)) y->left = insert_x(y->left);
	else y->right = insert_x(y->right);
	return y;
}

void treeprint_x(struct node *y,int y_val){
	if(y!=NULL){
		treeprint_x(y->left,y_val);
		cout<<" "<<table[y_val][y->str];
	     	//for(int i=0;i<komoku_y.size();i++)cout << " "<<table[i][y->str];
	       	treeprint_x(y->right,y_val);
	}
	//cout<<endl;
}
void treeprint_komoku_x(struct node *y){
	if(y!=NULL){
		treeprint_komoku_x(y->left);
		cout<<" "<<komoku_x[y->str];
	     	//for(int i=0;i<komoku_y.size();i++)cout << " "<<table[i][y->str];
	       	treeprint_komoku_x(y->right);
	}
}

bool compare_y(int y_comp){
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
struct node *insert_y(struct node *x){
	 if(x==NULL){
		x=(struct node *)malloc(sizeof(struct node));
		x->str=y;
		y++;
	        x->left=NULL;
		x->right=NULL;
	}
	else if(compare_y(x->str)) x->left = insert_y(x->left);
	else x->right = insert_y(x->right);
	return x;
}

void treeprint_y(struct node *x){
	if(x!=NULL){
		treeprint_y(x->left);
		cout<<komoku_y[x->str];
	     	for(int i=0;i<komoku_x.size();i++)cout << " "<<table[x->str][i];
		cout<<endl;
	       	treeprint_y(x->right);
	}
}

void sort_komoku_x(){
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
void sort_komoku_y(){
	struct node *root;
	root=NULL;
	for(auto i :komoku_y) root=insert_y(root);
	for(auto i :komoku_x) cout <<" "<<i;
	cout<<endl;
	treeprint_y(root);
}
int main(){
	/*
	string str="ABC";
	cout << str << endl;
	cout << p()<<endl;
	cout << table[0][2][0]<<endl;
	*/
	y=0;
	x=0;
	mode=false;
	sort_x=2;
	sort_y=2;
	//sort_komoku_x();
	sort_komoku_y();
	return 0;
}
