#include<iostream>
#include<vector>
#include"database.hpp"
#include"GUI.hpp"
using namespace std;

int main() {

	//デバッグ用コード
	database database;
	GUI GUI;
	
	GUI.update(database);
	GUI.display();

	return 0;

}
