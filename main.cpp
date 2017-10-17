#include<iostream>
#include<vector>
#include"database.hpp"
#include"GUI.hpp"
using namespace std;

int main() {

	//デバッグ用コード
	database database;
	GUI GUI;
	
	GUI.GUI_main(database);

	return 0;

}
