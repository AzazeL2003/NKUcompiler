#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__

#include <cassert>
#include <string>
#include <map>
#include "Type.h"

class Type;

inline bool issysruntime(std::string t)
{
    if(t=="getint"||t=="getch"||t=="getfloat"||t=="getarray"||t=="getfarray"
    ||t=="putint"||t=="putch"||t=="putfloat"||t=="putarray"||t=="putfarray"
    ||t=="putf"||t=="starttime"||t=="stoptime")
    {
        return true;
    }
    return false;
}

class SymbolEntry
{
private:
    int kind;
protected:
    enum {INT, VARIABLE, TEMPORARY, FLOAT};
    Type *type;

public:
    SymbolEntry(Type *type, int kind);
    virtual ~SymbolEntry() {};
    bool isInt() const {return kind == INT;};
    bool isFloat() const {return kind == FLOAT;};
    bool isTemporary() const {return kind == TEMPORARY;};
    bool isVariable() const {return kind == VARIABLE;};
    bool isInteger() const {return type->isInt();};
    Type* getType() {return type;};
    virtual std::string toStr() = 0;
    // You can add any function you need here.
};


/*  
    Symbol entry for literal constant. Example:

    int a = 1;

    Compiler should create constant symbol entry for literal constant '1'.
*/
class IntSymbolEntry : public SymbolEntry
{
private:
    int value;

public:
    IntSymbolEntry(int value);
    virtual ~IntSymbolEntry() {};
    int getValue() const {return value;};
    std::string toStr();
    // You can add any function you need here.
};


class FloatSymbolEntry : public SymbolEntry
{
private:
    float value;

public:
    FloatSymbolEntry(float value);
    virtual ~FloatSymbolEntry() {};
    int getValue() const {return value;};
    std::string toStr();
    // You can add any function you need here.
};


/* 
    Symbol entry for identifier. Example:

    int a;
    int b;
    void f(int c)
    {
        int d;
        {
            int e;
        }
    }

    Compiler should create identifier symbol entries for variables a, b, c, d and e:

    | variable | scope    |
    | a        | GLOBAL   |
    | b        | GLOBAL   |
    | c        | PARAM    |
    | d        | LOCAL    |
    | e        | LOCAL +1 |
*/
class IdentifierSymbolEntry : public SymbolEntry
{
private:
    enum {GLOBAL, PARAM, LOCAL};
    std::string name;
    int scope;
    // You can add any field you need here.

public:
    IdentifierSymbolEntry(Type *type, std::string name, int scope);
    virtual ~IdentifierSymbolEntry() {};
    std::string toStr();
    int getScope() const {return scope;};
    // You can add any function you need here.
};


/* 
    Symbol entry for temporary variable created by compiler. Example:

    int a;
    a = 1 + 2 + 3;

    The compiler would generate intermediate code like:

    t1 = 1 + 2
    t2 = t1 + 3
    a = t2

    So compiler should create temporary symbol entries for t1 and t2:

    | temporary variable | label |
    | t1                 | 1     |
    | t2                 | 2     |
*/
class TemporarySymbolEntry : public SymbolEntry
{
private:
    int label;
public:
    TemporarySymbolEntry(Type *type, int label);
    virtual ~TemporarySymbolEntry() {};
    std::string toStr();
    // You can add any function you need here.
};

// symbol table managing identifier symbol entries
class SymbolTable
{
private:
    std::map<std::string, SymbolEntry*> symbolTable;
    SymbolTable *prev = nullptr;
    int level;
    static int counter;
public:
    SymbolTable();
    SymbolTable(SymbolTable *prev);
    void install(std::string name, SymbolEntry* entry);
    SymbolEntry* lookup(std::string name);
    SymbolTable* getPrev() {return prev;};
    int getLevel() {return level;};
    static int getLabel() {return counter++;};
    friend void initsys();
};



extern SymbolTable *identifiers;
extern SymbolTable *globals;



inline void initsys()
{
    std::string strarr[13]{"getint","getch","getfloat","getarray","getfarray"
    ,"putint","putch","putfloat","putarray","putfarray"
    ,"putf","starttime","stoptime"};

    SymbolTable * iter = identifiers;
    while(iter->prev!=nullptr)
    {
        iter = iter->prev;
    }
    for(int i = 0;i<13;++i)
    {
        Type *funcType;
        funcType = new FunctionType(TypeSystem::voidType,{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, strarr[i], identifiers->getLevel());
        iter->install(strarr[i], se);
    }
}


#endif
