#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>

using namespace std;

int main()
{
    vector<vector<string> > table = {
		{"1","2","3"},
		{"4","5","6"},
		{"7","8","9"},
	};
	vector<string> komoku_x = {"a","b","c"};
	vector<string> komoku_y = { "d","e","f" };
	//ファイル出力
   FILE *fp;
   fp=fopen("database.txt","w");
   int size_x=(int)komoku_x.size();
   int size_y=(int)komoku_y.size();
	for(int i=0;i<size_x;i++) fprintf(fp," %s",koumoku_x[i]);
   fprintf(fp,"\n");
	for(int i=0;i<size_x;i++){
      fprintf(fp,"%s",koumoku_y[i]);
		for(int j=0;j<size_y;j++) fprintf(fp," %s",table[i][j]);
      fprintf(fp,"\n");
   }
   close(fp);
   return 0;
}

