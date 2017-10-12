#include<iostream>
#include<vector>
#include"database.h"
using namespace std;

int main() {

	//デバッグ用コード
	database root;
	int x, y;
	string str;
	root.display();
	cin >> x >> y >> str;
	root.write(x,y,str);
	root.display();
	return 0;

}