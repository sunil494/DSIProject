
#include <iostream>
#include "Record.h"
#include <stdlib.h>
#include "DBFile.h"
using namespace std;

extern "C"
{
	int yyparse(void); // defined in y.tab.c
}

extern struct AndList *final;

int main()
{

	// try to parse the CNF
	// cout << "Enter in your CNF: ";
	// if (yyparse() != 0) {
	// 	cout << "Can't parse your CNF.\n";
	// 	exit (1);
	// }

	// suck up the schema from the file
	// Schema lineitem ("catalog", "lineitem");

	// grow the CNF expression from the parse tree
	// CNF myComparison;
	// Record literal;
	// myComparison.GrowFromParseTree (final, &lineitem, literal);

	// print out the comparison to the screen
	// myComparison.Print ();

	// // now open up the text file and start procesing it
	//     FILE *tableFile = fopen ("lineitem.tbl", "r");

	//     Record temp;
	//     Schema mySchema ("catalog", "lineitem");

	// char *bits = literal.GetBits ();
	// cout << " numbytes in rec " << ((int *) bits)[0] << endl;
	// literal.Print (&supplier);

	// read in all of the records from the text file and see if they match
	// the CNF expression that was typed in
	// int counter = 0;
	// int status = 1;
	// ComparisonEngine comp;
	// File file1;
	// Page hello1;
	// char zero = 1;
	// file1.Open(file1.GetLength(),&zero);
	//     while (temp.SuckNextRecord (&mySchema, tableFile) == 1) {
	// 	counter++;
	// 	status = hello1.Append(&temp);
	// 	if (status == 0){
	// 		file1.AddPage(&hello1,file1.GetLength());
	// 		hello1.EmptyItOut();
	// 		Record temp1;
	// 		if(hello1.GetFirst (&temp1)){
	// 			cout << "Page Not Reset" << "\n";
	// 			cerr << counter << "\n";
	// 		}
	// 	}
	// 	}
	// cout << "File Length: " << file1.Close() << "\n";

	// file1.Open(file1.GetLength(),&zero);
	// Page readPage;
	// Record temp2;
	// for (int i = 0; i <= 10; i++){
	// 	cout << i << "\n";
	// 	file1.GetPage(&readPage, i);
	// 	while(readPage.GetFirst (&temp2))
	// 		temp2.Print(&mySchema);
	// }
	DBFile *db = new DBFile();
	const char *f_path = "Hello";
	char startup = 'h';
	fType type = heap;
	db->Create(f_path, type, &startup);
	// cout << "db.Create(&zero, type, &zero)" << "\n";
}
