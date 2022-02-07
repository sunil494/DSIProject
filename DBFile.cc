#include "TwoWayList.h"
#include "Record.h"
#include "Schema.h"
#include "File.h"
#include "Comparison.h"
#include "ComparisonEngine.h"
#include "DBFile.h"
#include "Defs.h"
#include <iostream>

#define verbose

// stub file .. replace it with your own DBFile.cc

DBFile::DBFile()
{
    cout << "DBFile"
         << "\n";
    Page *currentPage = new Page();
    Record *pointer = new Record();
    File *file = new File();
}

DBFile ::~DBFile()
{
    // delete pointer;
    // delete currentPage;
    // delete file;
}

int DBFile::Create(const char *f_path, fType f_type, void *startup)
{
    file->Open(0, (char *)f_path);
    file->Close();
}

void DBFile::Load(Schema &f_schema, const char *loadpath)
{
    cout << "Load"
         << "\n";
}

int DBFile::Open(const char *f_path)
{
    file->Open(file->GetLength(), (char *)f_path);
}

void DBFile::MoveFirst()
{
    file->GetPage(currentPage, 0);
    currentPage->GetFirst(pointer);
}

int DBFile::Close()
{
    cout << "Close"
         << "\n";
}

void DBFile::Add(Record &rec)
{
    cout << "Add"
         << "\n";
}

int DBFile::GetNext(Record &fetchme)
{
    cout << "GetNext"
         << "\n";
}

int DBFile::GetNext(Record &fetchme, CNF &cnf, Record &literal)
{
    cout << "GetNext"
         << "\n";
}
