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
}

DBFile ::~DBFile()
{
    delete pointer;
    delete currentPage;
    delete DB_FILE;
}

int DBFile::Create(const char *f_path, fType f_type, void *startup)
{
    // DB_FILE->Open(0,(char*)f_path);
    // DB_FILE->Close();
}

void DBFile::Load(Schema &f_schema, const char *loadpath)
{
}

int DBFile::Open(const char *f_path)
{
    DB_FILE->Open(DB_FILE->GetLength(), (char *)f_path);
}

void DBFile::MoveFirst()
{
    DB_FILE->GetPage(currentPage, 0);
    currentPage->GetFirst(pointer);
}

int DBFile::Close()
{
}

void DBFile::Add(Record &rec)
{
}

int DBFile::GetNext(Record &fetchme)
{
}

int DBFile::GetNext(Record &fetchme, CNF &cnf, Record &literal)
{
}
