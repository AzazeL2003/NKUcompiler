#ifndef __AST_H__
#define __AST_H__

#include <asm-generic/errno-base.h>
#include <complex.h>
#include <fstream>
#include <string>
#include "SymbolTable.h"

class SymbolEntry;

class Node
{
private:
    static int counter;
    int seq;
public:
    Node();
    int getSeq() const {return seq;};
    virtual void output(int level) = 0;
};

class ExprNode : public Node
{
protected:
    SymbolEntry *symbolEntry = nullptr;
public:
    ExprNode(SymbolEntry *symbolEntry) : symbolEntry(symbolEntry){};
    SymbolEntry * getse() {return symbolEntry;}
    bool isInteger() {return symbolEntry->isInteger();}
};

class BinaryExpr : public ExprNode
{
private:
    int op;
    ExprNode *expr1= nullptr, *expr2= nullptr;
public:
    enum {ADD, SUB, LAND, LOR, LESS,MUL,DIV,MOD,GREATER,NGREATER,NLESS,EQUAL,NEQUAL};
    BinaryExpr(SymbolEntry *se, int op, ExprNode*expr1, ExprNode*expr2) : ExprNode(se), op(op), expr1(expr1), expr2(expr2){};
    void output(int level);
};

class Int : public ExprNode
{
public:
    Int(SymbolEntry *se) : ExprNode(se){};
    void output(int level);
};

class Float : public ExprNode
{
public:
    Float(SymbolEntry *se) : ExprNode(se){};
    void output(int level);
};

class StmtNode : public Node
{};

class CompoundStmt : public StmtNode
{
private:
    StmtNode *stmt= nullptr;
public:
    CompoundStmt(StmtNode *stmt) : stmt(stmt) {};
    void output(int level);
};

class SeqNode : public StmtNode
{
private:
    std::vector<StmtNode*>stmts{};
public:
    SeqNode(StmtNode *stmt1){stmts.push_back(stmt1);};
    void push_back(StmtNode *stmt1){stmts.push_back(stmt1);};
    void output(int level);
};

class IfStmt : public StmtNode
{
private:
    ExprNode *cond= nullptr;
    StmtNode *thenStmt= nullptr;
public:
    IfStmt(ExprNode *cond, StmtNode *thenStmt) : cond(cond), thenStmt(thenStmt){};
    void output(int level);
};
class BreakStmt : public StmtNode
{
public:
    BreakStmt(){};
    void output(int level);
};
class ContinueStmt : public StmtNode
{
public:
    ContinueStmt(){};
    void output(int level);
};

class WhileStmt : public StmtNode
{
private:
    ExprNode *cond= nullptr;
    StmtNode *thenStmt= nullptr;
public:
    WhileStmt(ExprNode *cond, StmtNode *thenStmt) : cond(cond), thenStmt(thenStmt){};
    void output(int level);
};

class PlainStmt : public StmtNode
{
private:
    ExprNode *exp= nullptr;
public:
    PlainStmt(){};
    PlainStmt(ExprNode *exp) : exp(exp){};
    void output(int level);
};

class IfElseStmt : public StmtNode
{
private:
    ExprNode *cond= nullptr;
    StmtNode *thenStmt= nullptr;
    StmtNode *elseStmt= nullptr;
public:
    IfElseStmt(ExprNode *cond, StmtNode *thenStmt, StmtNode *elseStmt) : cond(cond), thenStmt(thenStmt), elseStmt(elseStmt) {};
    void output(int level);
};

class ReturnStmt : public StmtNode
{
private:
    ExprNode *retValue= nullptr;
public:
    ReturnStmt(ExprNode*retValue) : retValue(retValue) {};
    void output(int level);
};

class AssignStmt : public StmtNode
{
private:
    ExprNode *lval= nullptr;
    ExprNode *expr= nullptr;
public:
    AssignStmt(ExprNode *lval, ExprNode *expr) : lval(lval), expr(expr) {};
    void output(int level);
};

class ArrayNode : public StmtNode
{
private:
    ExprNode *dim= nullptr;
public:
    ArrayNode(ExprNode *d) : dim(d){};
    ExprNode * getExprNode(){return dim;}
    void output(int level);
};

class ArrayList : public StmtNode
{
private:
    std::vector<ArrayNode *> dims{};
public:
    ArrayList(){};
    ArrayList(ArrayNode *i){dims.push_back(i);};
    std::vector<ArrayNode *> getVector(){return dims;}
    void push_back(ArrayNode *i){dims.push_back(i);};
    void output(int level);
};

class FArrayNode : public StmtNode
{
private:
    ExprNode *dim= nullptr;
public:
    FArrayNode(ExprNode *d) : dim(d){};
    ExprNode * getExprNode(){return dim;}
    void output(int level);
};

class FArrayList : public StmtNode
{
private:
    std::vector<FArrayNode *> dims{};
public:
    FArrayList(){};
    FArrayList(FArrayNode *i){dims.push_back(i);};
    std::vector<FArrayNode *> getVector(){return dims;}
    void push_back(FArrayNode *i){dims.push_back(i);};
    bool empty(){return dims.empty();}
    void output(int level);
};

class InitVal : public StmtNode
{
private:
    ExprNode * expr= nullptr;
    std::vector<InitVal*> ids{};
public:
    InitVal() {}
    InitVal(ExprNode * e) : expr(e){}
    InitVal(std::vector<InitVal*> e) : ids(e){}
    void push_back(InitVal *id) {ids.push_back(id);}
    void output(int level);
};

class InitVals : public StmtNode
{
public:
    std::vector<InitVal*> vals{};
    InitVals(){}
    void output(int level){};
};

class VarDef : public ExprNode
{
private:
    ArrayList* arr= nullptr;
    InitVal* initval;
    bool isconst = false;
    bool isinited = false;
public:
    VarDef(SymbolEntry* s,ArrayList* a) : ExprNode(s),arr(a){};
    VarDef(SymbolEntry* s,ArrayList* a,InitVal* i) : ExprNode(s),arr(a),initval(i){};
    ArrayList* getArr() {return arr;}
    InitVal* getInitval() {return initval;}
    void changeinit(bool res) { isinited = res;}
    bool isinit() { return isinited;}
    void changeconst(bool res) { isconst = res;}
    void output(int level){};
};

class VarId : public ExprNode
{
private:
    ArrayList* arrlist= nullptr;
    InitVal* initval=nullptr;
    bool isconst = false;
    bool isinited = false;
public:
    VarId(SymbolEntry *se,ArrayList* a) : ExprNode(se),arrlist(a){};
    VarId(SymbolEntry *se,ArrayList* a,InitVal* init) : ExprNode(se),arrlist(a),initval(init){};
    void changeinit(bool res) { isinited = res;}
    bool isinit() { return isinited;}
    void changeconst(bool res) { isconst = res;}
    void output(int level);
};

class VarIds : public StmtNode
{
private:
    std::vector<VarId *> ids{};
public:
    VarIds(VarId *i){ids.push_back(i);};
    std::vector<VarId *> getVector(){return ids;}
    void push_back(VarId *i){ids.push_back(i);};
    void output(int level){};
};


class Id : public ExprNode
{
private:
    FArrayList *arr = nullptr;
public:
    Id(SymbolEntry *se) : ExprNode(se){};
    Id(SymbolEntry *se,FArrayList *a) : ExprNode(se),arr(a){};
    void output(int level);
};


class TDeclStmt : public StmtNode //TODO
{
private:
    StmtNode* st = nullptr;
public:
    TDeclStmt() {}
    TDeclStmt(StmtNode* s) :st(s) {}
    void output(int level);
};

class DeclStmt : public StmtNode
{
private:
    std::vector<VarId*> ids{};
public:
    DeclStmt() {}
    DeclStmt(VarIds* v) :ids(v->getVector()) {}
    DeclStmt(std::vector<VarId*> id): ids(id){}
    void push_back(VarId *id) {ids.push_back(id);}
    VarId* get_back() {return ids.back();}
    void output(int level);
};


class ConstDeclStmt : public StmtNode
{
private:
    std::vector<VarId*> ids{};
public:
    ConstDeclStmt() {}
    ConstDeclStmt(VarIds* v) :ids(v->getVector()) {}
    ConstDeclStmt(std::vector<VarId*> id): ids(id){}
    void push_back(VarId *id) {ids.push_back(id);}
    VarId* get_back() {return ids.back();}
    void output(int level);
};


class FuncParam : public ExprNode
{
private:
    FArrayList* arr= nullptr;
    bool isarray = false;
    Type* t = nullptr;
public:
    FuncParam(SymbolEntry *s):ExprNode(s),t(s->getType()){};
    FuncParam(SymbolEntry *s,FArrayList* a) : ExprNode(s),arr(a),t(s->getType()){};
    FArrayList* getArr() {return arr;}
    Type* getType() {return t;}
    void changearray(bool a) {isarray = a;}
    void output(int level);
};

class FuncParams : public StmtNode
{
private:
    std::vector<FuncParam*> params{};
public:
    FuncParams() {}
    FuncParams(FuncParam * e){params.push_back(e);}
    void push_back(FuncParam *id) {params.push_back(id);}
    std::vector<FuncParam*> getVector() {return params;}
    void output(int level);
};

class FunctionDef : public StmtNode
{
private:
    SymbolEntry *se= nullptr;
    StmtNode *stmt= nullptr;
    FuncParams * fparams = nullptr;
public:
    FunctionDef(SymbolEntry *se, StmtNode *stmt) : se(se), stmt(stmt){};
    FunctionDef(SymbolEntry *se, StmtNode *stmt,FuncParams * f) : se(se), stmt(stmt) , fparams(f){};
    void output(int level);
};

class CallParams : public StmtNode
{
private:
    std::vector<ExprNode*> params{};
public:
    CallParams(ExprNode *e) {params.push_back(e);}
    void push_back(ExprNode *e) {params.push_back(e);}
    std::vector<ExprNode*> getVector() {return params;}
    void output(int level);
};

class UnaryExpr : public ExprNode
{
private:
    int op;
    ExprNode *expr= nullptr;
    CallParams* params = nullptr;
public:
    enum {ADD, SUB, NOT, FUNCCALL, NONE};
    UnaryExpr(SymbolEntry *se, int op, ExprNode*expr) : ExprNode(se), op(op), expr(expr){};
    UnaryExpr(SymbolEntry *se, CallParams* f) : ExprNode(se), op(FUNCCALL), params(f){};
    void output(int level);
};


class Ast
{
private:
    Node* root= nullptr;
public:
    Ast() {root = nullptr;}
    void setRoot(Node*n) {root = n;}
    void output();
};


#endif
