#include "Ast.h"
#include "SymbolTable.h"
#include <string>
#include "Type.h"

extern FILE *yyout;
int Node::counter = 0;

Node::Node()
{
    seq = counter++;
}

void Ast::output()
{
    fprintf(yyout, "program\n");
    if(root != nullptr)
        root->output(4);
}

void BinaryExpr::output(int level)
{
    std::string op_str;
    switch(op)
    {
        case ADD:
            op_str = "add";
            break;
        case SUB:
            op_str = "sub";
            break;
        case LAND:
            op_str = "land";
            break;
        case LOR:
            op_str = "lor";
            break;
        case LESS:
            op_str = "less";
            break;
        case MUL:
            op_str = "mul";
            break;
        case DIV:
            op_str = "div";
            break;
        case MOD:
            op_str = "mod";
            break;
        case GREATER:
            op_str = "greater";
            break;
        case NGREATER:
            op_str = "ngreater";
            break;
        case NLESS:
            op_str = "nless";
            break;
        case EQUAL:
            op_str = "equal";
            break;
        case NEQUAL:
            op_str = "nequal";
            break;
    }
    fprintf(yyout, "%*cBinaryExpr\top: %s\n", level, ' ', op_str.c_str());
    expr1->output(level + 4);
    expr2->output(level + 4);
}

void UnaryExpr::output(int level)
{
    std::string op_str;
    if(op==FUNCCALL)
    {
        fprintf(yyout, "%*cUnaryExpr\top: funccall\n", level, ' ');
        if(params!=nullptr)
        params->output(level + 4);
    }
    else
    {
        switch(op)
        {
            case ADD:
                op_str = "add";
                break;
            case SUB:
                op_str = "sub";
                break;
            case NOT:
                op_str = "not";
                break;
            case NONE:
                op_str = "none";
                break;
        }
        fprintf(yyout, "%*cUnaryExpr\top: %s\n", level, ' ', op_str.c_str());
        expr->output(level + 4);
    }
}

void CallParams::output(int level)
{
    fprintf(yyout, "%*cCallParams\n", level, ' ');
    for(const auto& node : params)
    {
        node->output(level);
    }
}

void Int::output(int level)
{
    std::string type, value;
    type = symbolEntry->getType()->toStr();
    value = symbolEntry->toStr();
    fprintf(yyout, "%*cIntegerLiteral\tvalue: %s\ttype: %s\n", level, ' ',
            value.c_str(), type.c_str());
}

void Float::output(int level)
{
    std::string type, value;
    type = symbolEntry->getType()->toStr();
    value = symbolEntry->toStr();
    fprintf(yyout, "%*cFloatLiteral\tvalue: %s\ttype: %s\n", level, ' ',
            value.c_str(), type.c_str());
}

void Id::output(int level)
{
    std::string name, type;
    int scope;
    name = symbolEntry->toStr();
    type = symbolEntry->getType()->toStr();
    scope = dynamic_cast<IdentifierSymbolEntry*>(symbolEntry)->getScope();
    fprintf(yyout, "%*cId\tname: %s\tscope: %d\ttype: %s\n", level, ' ',
            name.c_str(), scope, type.c_str());
    if(!arr->empty())
    {
        arr->output(level+4);
    }
}

void VarId::output(int level)
{
    std::string name, type;
    int scope;
    name = symbolEntry->toStr();
    type = symbolEntry->getType()->toStr();
    scope = dynamic_cast<IdentifierSymbolEntry*>(symbolEntry)->getScope();
    if(arrlist==nullptr||arrlist->getVector().empty())
    {
        fprintf(yyout, "%*cVarId\tname: %s\tscope: %d\ttype: %s\n", level, ' ',
            name.c_str(), scope, type.c_str());
    }
    else
    {
        fprintf(yyout, "%*cVarId\tname: %s\tscope: %d\ttype: %s array\n", level, ' ',
            name.c_str(), scope, type.c_str());
        arrlist->output(level+4);
    }
    if(isinited)
    {
        initval->output(level+4);
    }
}

void CompoundStmt::output(int level)
{
    fprintf(yyout, "%*cCompoundStmt\n", level, ' ');
    if(stmt!=nullptr)
    {
        stmt->output(level + 4);
    }
}

void PlainStmt::output(int level)
{
    fprintf(yyout, "%*cPlainStmt\n", level, ' ');
    if(exp!=nullptr)
    {
        exp->output(level + 4);
    }
}

void SeqNode::output(int level)
{
    fprintf(yyout, "%*cSequence\n", level, ' ');
    for(auto node : stmts)
    {
        node->output(level+4);
    }
}

void DeclStmt::output(int level)
{
    fprintf(yyout, "%*cDeclStmt\n", level, ' ');
    for(const auto& node : ids)
    {
        node->output(level + 4);
    }
}

void TDeclStmt::output(int level)
{
    fprintf(yyout, "%*cTDeclStmt\n", level, ' ');
    if(st!=nullptr)
    {
        st->output(level + 4);
    }
}

void ConstDeclStmt::output(int level)
{
    fprintf(yyout, "%*cConstDeclStmt\n", level, ' ');
    for(const auto& node : ids)
    {
        node->output(level + 4);
    }
}

void IfStmt::output(int level)
{
    fprintf(yyout, "%*cIfStmt\n", level, ' ');
    cond->output(level + 4);
    thenStmt->output(level + 4);
}

void WhileStmt::output(int level)
{
    fprintf(yyout, "%*cWhileStmt\n", level, ' ');
    cond->output(level + 4);
    thenStmt->output(level + 4);
}

void BreakStmt::output(int level)
{
    fprintf(yyout, "%*cBreakStmt\n", level, ' ');
}

void ContinueStmt::output(int level)
{
    fprintf(yyout, "%*cContinueStmt\n", level, ' ');
}

void IfElseStmt::output(int level)
{
    fprintf(yyout, "%*cIfElseStmt\n", level, ' ');
    cond->output(level + 4);
    thenStmt->output(level + 4);
    elseStmt->output(level + 4);
}

void ReturnStmt::output(int level)
{
    fprintf(yyout, "%*cReturnStmt\n", level, ' ');
    if(retValue!=nullptr)
    retValue->output(level + 4);
}

void AssignStmt::output(int level)
{
    fprintf(yyout, "%*cAssignStmt\n", level, ' ');
    lval->output(level + 4);
    expr->output(level + 4);
}

void FunctionDef::output(int level)
{
    std::string name, type;
    name = se->toStr();
    type = se->getType()->toStr();
    fprintf(yyout, "%*cFunctionDefine function name: %s, type: %s\n", level, ' ', 
            name.c_str(), type.c_str());
    if(fparams != nullptr)
    {
        fparams->output(level+4);
    }
    stmt->output(level + 4);
}

void ArrayNode::output(int level)
{
    dim->output(level + 4);
}

void ArrayList::output(int level)
{
    fprintf(yyout, "%*cArrayList\n", level, ' ');
    for(const auto& node : dims)
    {
        node->output(level);
    }
}

void FuncParam::output(int level)
{
    std::string name, type;
    int scope;
    name = symbolEntry->toStr();
    type = t->toStr();
    scope = dynamic_cast<IdentifierSymbolEntry*>(symbolEntry)->getScope();
    
    if(isarray)
    {
        fprintf(yyout, "%*cFuncParam\tname: %s\tscope: %d\ttype: %s array\n", level, ' ',
            name.c_str(), scope, type.c_str());
        if(arr!=nullptr)
        {
            arr->output(level+4);
        }
    }
    else
    {
        fprintf(yyout, "%*cFuncParam\tname: %s\tscope: %d\ttype: %s \n", level, ' ',
            name.c_str(), scope, type.c_str());
    }
}

void FuncParams::output(int level)
{
    fprintf(yyout, "%*cFuncParams\n", level, ' ');
    for(const auto& node : params)
    {
        node->output(level);
    }
}

void FArrayNode::output(int level)
{
    dim->output(level + 4);
}

void FArrayList::output(int level)
{
    fprintf(yyout, "%*cFArrayList\n", level, ' ');
    for(const auto& node : dims)
    {
        node->output(level);
    }
}

void InitVal::output(int level)
{
    if(expr!=nullptr)
    {
        expr->output(level);
    }
    else
    {
        fprintf(yyout, "%*cInitVal\n", level, ' ');
        for(const auto& node : ids)
        {
            node->output(level+4);
        }
    }
}

