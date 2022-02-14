#include "TwoWayList.h"
#include "Record.h"
#include "Schema.h"
#include "File.h"
#include "Comparison.h"
#include "ComparisonEngine.h"
#include "DBFile.h"
#include "Defs.h"

// stub file .. replace it with your own DBFile.cc

DBFile::DBFile () {
    pagePointer = 0;
}

int DBFile::Create (const char *f_path, fType f_type, void *startup) {
    switch(f_type) {
        case heap:
            file.Open(0,(char*)f_path);
    }

    return 1;
}

void DBFile::Load (Schema &f_schema, const char *loadpath) {
    int counter = 0;
    int status = 1;
    Record temp;
    FILE *tableFile = fopen (loadpath, "r");
	ComparisonEngine comp;
    Page tempPage;
    Record tempRecord;
    while (temp.SuckNextRecord (&f_schema, tableFile) == 1) {
		counter++;
        status = tempPage.Append(&temp);
        if (status == 0){
            file.AddPage(&tempPage,file.GetLength());
            tempPage.EmptyItOut();
            if(tempPage.GetFirst (&tempRecord)){
                printf("Page Not Reset at Record Number: %d\n",counter);
			}
            status = tempPage.Append(&temp);
        }
    }
    file.AddPage(&tempPage,file.GetLength());
    printf("File Length: %d\n",file.GetLength());
}

int DBFile::Open (const char *f_path) {
    file.Open(1,(char*)f_path);
    return 1;
}

void DBFile::MoveFirst () {
    recordPointer = 0;
}

void DBFile::MoveFirstPage () {
    pagePointer = 0;
}

int DBFile::Close () {
    file.Close();
    return 1;
}

void DBFile::Add (Record &rec) {
    Page addPage;
    file.GetPage(&addPage, pagePointer);
    int status = addPage.Append(&rec);
    if (status == 0){
        MoveFirst();
        Page temp;
        temp.Append(&rec);
        file.AddPage(&temp,pagePointer);
        pagePointer++;
    }
    recordPointer++;
}

int DBFile::GetNext (Record &fetchme) {
    if (recordPointer == 0){
        file.GetPage(&buffer, pagePointer);
    }
    int status = buffer.GetFirst(&fetchme);
    if(status == 0){
        pagePointer++;
        if (pagePointer >= (file.GetLength()) - 1){
            return 0;
        }
        file.GetPage(&buffer, pagePointer);
        buffer.GetFirst(&fetchme);
        MoveFirst();
    }
    recordPointer++;
    return 1;
}

int DBFile::GetNext (Record &fetchme, CNF &cnf, Record &literal) {
    ComparisonEngine comp;
    int getNextOutput = 1;
    GetNext(fetchme);
    GetNext(literal);
    printf("%d",comp.Compare (&fetchme, &literal, &cnf));
    while(getNextOutput == 1){
        if (comp.Compare (&fetchme, &literal, &cnf)){
            return 1;
        }else{
                getNextOutput = GetNext(fetchme);
            }
    }
    return 0;
}
