#include "Function.h"
#include "Unit.h"
#include "Type.h"
#include <list>
#include <cassert>
extern FILE* yyout;

int Function::deadinstelim()
{
    std::set<BasicBlock *> v;
    std::list<BasicBlock *> q;
    q.push_back(entry);
    v.insert(entry);
    int count = 0;
    while (!q.empty())
    {
        auto bb = q.front();
        q.pop_front();
        count += bb->deadinstelim();
        for (auto succ = bb->succ_begin(); succ != bb->succ_end(); succ++)
        {
            if (v.find(*succ) == v.end())
            {
                v.insert(*succ);
                q.push_back(*succ);
            }
        }
    }
    return count;
}
Function::Function(Unit *u, SymbolEntry *s)
{
    u->insertFunc(this);
    entry = new BasicBlock(this);
    sym_ptr = s;
    parent = u;
}

Function::~Function()
{
    auto delete_list = block_list;
    for (auto &i : delete_list)
        delete i;
    parent->removeFunc(this);
}

// remove the basicblock bb from its block_list.
void Function::remove(BasicBlock *bb)
{
    block_list.erase(std::find(block_list.begin(), block_list.end(), bb));
}

void Function::output() const
{
    FunctionType* funcType = dynamic_cast<FunctionType*>(sym_ptr->getType());
    Type *retType = funcType->getRetType();
    fprintf(yyout, "define %s %s(", retType->toStr().c_str(), sym_ptr->toStr().c_str());
    for(auto iter = params.begin();iter!=params.end();++iter)
    {
        fprintf(yyout, "%s %s",(*iter)->getType()->toStr().c_str(),(*iter)->toStr().c_str());
        if(params.end()-iter!=1)
        {
            fprintf(yyout,", ");
        }
    }
    fprintf(yyout, ") {\n");
    std::set<BasicBlock *> v;
    std::list<BasicBlock *> q;
    q.push_back(entry);
    v.insert(entry);
    int res = 0;
    while (!q.empty())
    {
        auto bb = q.front();
        q.pop_front();
        res += bb->output();
        if(bb->begin()==bb->end())
        {
            if(funcType->getRetType()->isInt())
                fprintf(yyout,"ret i32 0\n");
            else if(funcType->getRetType()->isFloat())
                fprintf(yyout,"ret float 0.000000e+00\n");
            else 
                fprintf(yyout,"ret\n");
        }
        for (auto succ = bb->succ_begin(); succ != bb->succ_end(); succ++)
        {
            if (v.find(*succ) == v.end())
            {
                v.insert(*succ);
                q.push_back(*succ);
            }
        }
    }
    assert(res>0);
    fprintf(yyout, "}\n");
}
