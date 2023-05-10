//
// Created by mrbru on 10.05.2023.
//

#ifndef DATABASE_SCRIPT_BD_H
#define DATABASE_SCRIPT_BD_H

#include <vector>
#include "sqlite3.h"
#include "DATA.h"

struct Data{
    char *NameCol;
    char *ValCol;

    Data();
    Data(const char *_NameCol, const char *_ValCol);
    ~Data();
};

class BD{
private:
    sqlite3* bd;
    bool IsOpened;
    int getLastRowId();
public:
    BD();
    BD(const char* nameBD);
    virtual ~BD() = 0;

    void openBD(const char* nameBD);
    void CloseBD();
    int req_create_insert(const char* sqlString);
    int req_select(const char* sqlString, int (*call)(void*, int, char**, char**), void*);
};

class BD_dict : public BD{
private:
    LinkedList<Data*> *curData;
    void createWords();
    void createTranslations();
    void createTags();
    void createInfoWords();

    static int updateLL(void*, int, char**, char**);
public:
    BD_dict() : BD(){}
    BD_dict(const char *nameBD) : BD(nameBD){}
    ~BD_dict(){delete curData;}

    int InsertWord(const char *word);
    int InsertListWords(const std::vector<char*>& words);
    int InsertTag(const char *tag);
    int InsertTranslation(const char* word);
    int AddNewWordToDict(const char* word, const char* translation, const char *tag = nullptr);
    int UpdateTag(const char* word, const char* tag);

    std::vector<Data*> getWords(){
        req_select("SELECT * FROM words;", updateLL, curData);

    }
    std::vector<Data*> getWordByWord(const char* word);
    std::vector<Data*> getWordByTag(const char* tag);



};

#endif //DATABASE_SCRIPT_BD_H
