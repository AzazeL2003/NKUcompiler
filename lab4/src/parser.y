%code top{
    #include <iostream>
    #include <string>
    #include <assert.h>
    #include "parser.h"
    extern Ast ast;
    int yylex();
    int yyerror( char const * );
    bool issysinit = false;
    Type* vtype = nullptr;
    std::string name{};
}

%code requires {
    #include "Ast.h"
    #include "SymbolTable.h"
    #include "Type.h"
}

%union {
    int itype;
    float ftype;
    char* strtype;
    StmtNode* stmttype;
    ExprNode* exprtype;
    SeqNode* seqtype;
    Type* type;
    VarIds* vistype;
    VarId* vitype;
    TDeclStmt* dectype;
    ArrayList* altype;
    ArrayNode* artype;
    FArrayList* faltype;
    FArrayNode* fartype;
    ConstDeclStmt* cdectype;
    InitVal* ivtype;
    InitVals* vivtype;
    FuncParam* fptype;
    FuncParams* fpstype;
    CallParams* cptype;
}

%start Program
%token <strtype> ID FLT INTEGER OCTAL HEX
%token IF ELSE WHILE CONTINUE BREAK
%token INT VOID CONST FLOAT
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA LBRACKET RBRACKET
%token ADD SUB MUL DIV MOD LESS ASSIGN GREATER NGREATER NLESS NEQUAL EQUAL NOT LOR LAND 
%token RETURN

%nterm <cptype> CallParams
%nterm <fptype> FuncParam
%nterm <fpstype> FuncParams
%nterm <ivtype> InitVal ConstInitVal
%nterm <vivtype> InitVals ConstInitVals
%nterm <cdectype> ConstDeclStmt
%nterm <altype> ArrayList
%nterm <artype> ArrayNode
%nterm <faltype> FArrayList
%nterm <fartype> FArrayNode
%nterm <seqtype> Stmts
%nterm <vistype> VarIds ConstVarIds
%nterm <vitype> VarId TempVarId ConstVarId
%nterm <dectype> DeclStmt TempDecl
%nterm <stmttype>  Stmt AssignStmt BlockStmt IfStmt ReturnStmt PlainStmt WhileStmt BreakStmt ContinueStmt
%nterm <exprtype> Exp AddExp Cond LOrExp PrimaryExp LVal RelExp LAndExp MulExp EqExp ConstExp UnaryExp
%nterm <type> BType

%precedence THEN
%precedence ELSE


%%
Program
    : Stmts {
        ast.setRoot($1);
    }
    ;
Stmts
    : Stmt {$$ = new SeqNode($1);}
    | Stmts Stmt{
        $1->push_back($2);
        $$ = $1;
    }
    ;
Stmt
    : AssignStmt {$$=$1;}
    | BlockStmt {$$=$1;}
    | IfStmt {$$=$1;}
    | WhileStmt {$$=$1;}
    | ReturnStmt {$$=$1;}
    | DeclStmt {$$=$1;}
    | ConstDeclStmt {$$=$1;}
    | PlainStmt {$$=$1;}
    | BreakStmt {$$=$1;}
    | ContinueStmt {$$=$1;}
    ;//TODO
BreakStmt
    : BREAK SEMICOLON{
        $$ = new BreakStmt();
    }
    ;
ContinueStmt
    : CONTINUE SEMICOLON{
        $$ = new ContinueStmt();
    }
PlainStmt
    : SEMICOLON {$$ = new PlainStmt();}
    | Exp SEMICOLON {$$ = new PlainStmt($1);}
BType
    : INT {
        $$ = TypeSystem::intType;
    }
    | FLOAT {
        $$ = TypeSystem::floatType;
    }
    ;
ConstDeclStmt
    :
    CONST BType {
        vtype = $2;
    }
    ConstVarIds SEMICOLON{
        $$ = new ConstDeclStmt($4);
    }

DeclStmt
    :
    BType {
        vtype = $1;
    }
    TempDecl {
        $$ = $3;
    }
    | VOID{
        vtype = TypeSystem::voidType;
    }
    TempDecl {
        $$ = $3;
    }
    ;
TempDecl
    :
    VarIds SEMICOLON{
        $$ = new TDeclStmt(new DeclStmt($1));
    }
    | ID 
    {
        Type *funcType;
        funcType = new FunctionType(vtype,{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        identifiers = new SymbolTable(identifiers);
    }
    LPAREN FuncParams RPAREN BlockStmt
    {
        SymbolEntry *se;
        se = identifiers->lookup($1);
        std::vector<Type*> t{};
        for(const auto& node : $4->getVector())
        {
            t.emplace_back(node->getType());
        }
        dynamic_cast<FunctionType*>(se->getType())->changeParams(t);
        assert(se != nullptr);
        $$ = new TDeclStmt(new FunctionDef(se, $6,$4));
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev(); 
        delete top;
        delete []$1;

    }
ConstVarIds
    :
    ConstVarId{
        $$ = new VarIds($1);
    }
    | ConstVarIds COMMA ConstVarId{
        $1->push_back($3);
        $$ = $1;
    }
    ;
ConstVarId
    :ID {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(vtype, $1, identifiers->getLevel());
        identifiers->install($1, se);
    }
    ArrayList ASSIGN ConstInitVal 
    {
        auto se = identifiers->lookup($1);
        assert(se!=nullptr);
        $$ = new VarId(se,$3,$5);
        $$->changeinit(true);
        $$->changeconst(true);
        delete []$1;
    }
    ;
VarIds
    :
    VarId{
        $$ = new VarIds($1);
    }
    | VarIds COMMA VarId{
        $1->push_back($3);
        $$ = $1;
    }
    ;
VarId
    : ID {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(vtype, $1, identifiers->getLevel());
        identifiers->install($1, se);
        name = $1;
        delete []$1;
    }
    TempVarId
    {
        $$ = $3;
    }
    ;
TempVarId:
    ArrayList
    {
        auto se = identifiers->lookup(name);
        assert(se!=nullptr);
        $$ = new VarId(se,$1);
    }
    | ArrayList ASSIGN InitVal 
    {
        auto se = identifiers->lookup(name);
        assert(se!=nullptr);
        $$ = new VarId(se,$1,$3);
        $$->changeinit(true);
    }
InitVal
    : Exp{
        $$ = new InitVal($1);
    }
    | LBRACE InitVals RBRACE{
        $$ = new InitVal($2->vals);
    }
    | LBRACE RBRACE{
        $$ = new InitVal();
    }
    ;
InitVals
    : InitVal {
        $$ = new InitVals();
        $$->vals.push_back($1);
    }
    | InitVals COMMA InitVal{
        $1->vals.push_back($3);
        $$ = $1;
    }
    ;
ConstInitVal
    : ConstExp{
        $$ = new InitVal($1);
    }
    | LBRACE ConstInitVals RBRACE{
        $$ = new InitVal($2->vals);
    }
    | LBRACE RBRACE{
        $$ = new InitVal();
    }
    ;
ConstInitVals
    : ConstInitVal {
        $$ = new InitVals();
        $$->vals.push_back($1);
    }
    | ConstInitVals COMMA ConstInitVal{
        $1->vals.push_back($3);
        $$ = $1;
    }
    ;
FuncParams
    :
    %empty {
        $$ = new FuncParams();
    } 
    | FuncParam {
        $$ = new FuncParams($1);
    } 
    | FuncParams COMMA FuncParam{
        $1->push_back($3);
        $$ = $1;
    }
    ;
FuncParam
    : BType ID {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry($1, $2, identifiers->getLevel());
        identifiers->install($2, se);
        $$ = new FuncParam(se);
    }
    | BType ID LBRACKET RBRACKET FArrayList{
        SymbolEntry *se;
        se = new IdentifierSymbolEntry($1, $2, identifiers->getLevel());
        identifiers->install($2, se);
        $$ = new FuncParam(se,$5);
        $$->changearray(true);
    }
    ;
CallParams
    :
    Exp {
        $$ = new CallParams($1);
    } 
    | CallParams COMMA Exp{
        $1->push_back($3);
        $$ = $1;
    }
    ;
FArrayList
    : %empty { 
        $$ = new FArrayList();
    }
    | FArrayList FArrayNode   {
        $1->push_back($2);
        $$ = $1;
    }
    ;
FArrayNode
    : LBRACKET Exp RBRACKET {
        $$ = new FArrayNode($2);
    }
    ;
ArrayList
    : %empty { 
        $$ = new ArrayList();
    }
    | ArrayList ArrayNode   {
        $1->push_back($2);
        $$ = $1;
    }
    ;
ArrayNode
    : LBRACKET ConstExp RBRACKET {
        $$ = new ArrayNode($2);
    }
    ;
ConstExp
    : AddExp {$$ = $1;}
    ;
AssignStmt
    :
    LVal ASSIGN Exp SEMICOLON {
        $$ = new AssignStmt($1, $3);
    }
    ;
BlockStmt
    :   LBRACE 
        {identifiers = new SymbolTable(identifiers);} 
        Stmts RBRACE 
        {
            $$ = new CompoundStmt($3);
            SymbolTable *top = identifiers;
            identifiers = identifiers->getPrev();
            delete top;
        }
    |   LBRACE RBRACE 
        {
            $$ = new CompoundStmt(nullptr);
        }
    ;
IfStmt
    : IF LPAREN Cond RPAREN Stmt %prec THEN {
        $$ = new IfStmt($3, $5);
    }
    | IF LPAREN Cond RPAREN Stmt ELSE Stmt {
        $$ = new IfElseStmt($3, $5, $7);
    }
    ;
WhileStmt
    : WHILE LPAREN Cond RPAREN Stmt {
        $$ = new WhileStmt($3, $5);
    }
    ;
ReturnStmt
    :
    RETURN Exp SEMICOLON{
        $$ = new ReturnStmt($2);
    }
    | RETURN SEMICOLON{
        $$ = new ReturnStmt(nullptr);
    }
    ;
Exp
    :
    AddExp {$$ = $1;}
    ;
Cond
    :
    LOrExp {$$ = $1;}
    ;
LVal
    : ID FArrayList {
        if(!issysinit)
        {
            initsys();
            issysinit = true;
        }
        SymbolEntry *se;
        se = identifiers->lookup($1);
        if(se == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)$1);
            delete [](char*)$1;
            assert(se != nullptr);
        }
        $$ = new Id(se,$2);
        delete []$1;
    }
    ;//TODO
PrimaryExp
    :
    LVal {
        $$ = $1;
    }
    | INTEGER {
        std::string temp = $1;
        SymbolEntry *se = new IntSymbolEntry(std::stoi(temp, 0, 10));
        $$ = new Int(se);
    }
    | OCTAL {
        std::string temp = $1;
        SymbolEntry *se = new IntSymbolEntry(std::stoi(temp, 0, 8));
        $$ = new Int(se);
    }
    | HEX {
        std::string temp = $1;
        SymbolEntry *se = new IntSymbolEntry(std::stoi(temp.substr(2), 0, 16));
        $$ = new Int(se);
    }
    | FLT {
        std::string temp = $1;
        SymbolEntry *se = new FloatSymbolEntry(std::stof(temp));
        $$ = new Float(se);
    }
    | LPAREN Exp RPAREN {
        $$ = $2;
    }
    ;
UnaryExp
    :
    PrimaryExp {
        $$ = $1;
    }
    | ID LPAREN RPAREN {
        if(!issysinit)
        {
            initsys();
            issysinit = true;
        }
        auto tse = identifiers->lookup($1);
        assert(tse != nullptr);
        SymbolEntry *se = new TemporarySymbolEntry(dynamic_cast<FunctionType*>(tse->getType())->getReturn(), SymbolTable::getLabel());
        $$ = new UnaryExpr(se,nullptr);
    }
    | ID LPAREN CallParams RPAREN {
        if(!issysinit)
        {
            initsys();
            issysinit = true;
        }
        auto tse = identifiers->lookup($1);
        assert(tse != nullptr);
        SymbolEntry *se = new TemporarySymbolEntry(dynamic_cast<FunctionType*>(tse->getType())->getReturn(), SymbolTable::getLabel());
        $$ = new UnaryExpr(se,$3);
    }
    | ADD UnaryExp {
        SymbolEntry *se = new TemporarySymbolEntry(($2->isInteger())?TypeSystem::intType:TypeSystem::floatType, SymbolTable::getLabel());
        $$ = new UnaryExpr(se, UnaryExpr::ADD, $2);
    }
    | SUB UnaryExp {
        SymbolEntry *se = new TemporarySymbolEntry(($2->isInteger())?TypeSystem::intType:TypeSystem::floatType, SymbolTable::getLabel());
        $$ = new UnaryExpr(se, UnaryExpr::SUB, $2);
    }
    | NOT UnaryExp {
        SymbolEntry *se = new TemporarySymbolEntry(($2->isInteger())?TypeSystem::intType:TypeSystem::floatType, SymbolTable::getLabel());
        $$ = new UnaryExpr(se, UnaryExpr::NOT, $2);
    }
    ;
MulExp
    :
    UnaryExp {$$ = $1;}
    |
    MulExp MUL UnaryExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(($1->isInteger()&&$3->isInteger())?TypeSystem::intType:TypeSystem::floatType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::MUL, $1, $3);
    }
    |
    MulExp DIV UnaryExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(($1->isInteger()&&$3->isInteger())?TypeSystem::intType:TypeSystem::floatType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::DIV, $1, $3);
    }
    |
    MulExp MOD UnaryExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::MOD, $1, $3);
    }
    ;
AddExp
    :
    MulExp {$$ = $1;}
    |
    AddExp ADD MulExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(($1->isInteger()&&$3->isInteger())?TypeSystem::intType:TypeSystem::floatType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::ADD, $1, $3);
    }
    |
    AddExp SUB MulExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(($1->isInteger()&&$3->isInteger())?TypeSystem::intType:TypeSystem::floatType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::SUB, $1, $3);
    }
    ;
RelExp
    :
    AddExp {$$ = $1;}
    |
    RelExp LESS AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LESS, $1, $3);
    }
    |
    RelExp GREATER AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::GREATER, $1, $3);
    }
    |
    RelExp NGREATER AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::NGREATER, $1, $3);
    }
    |
    RelExp NLESS AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::NLESS, $1, $3);
    }
    ;
EqExp
    :
    RelExp {$$ = $1;}
    |
    EqExp EQUAL RelExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::EQUAL, $1, $3);
    }
    |
    EqExp NEQUAL RelExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::NEQUAL, $1, $3);
    }
    ;
LAndExp
    :
    EqExp {$$ = $1;}
    |
    LAndExp LAND EqExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LAND, $1, $3);
    }
    ;
LOrExp
    :
    LAndExp {$$ = $1;}
    |
    LOrExp LOR LAndExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LOR, $1, $3);
    }
    ;
%%

int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
