/*************************************************************************
	> File Name:    CC_SynTree.h
	> Author:       sunowsir
	> Mail:         sunow.wang@gmail.com
	> GitHub:       github.com/sunowsir
	> Created Time: 2019年04月05日 星期五 17时03分50秒
 ************************************************************************/
#ifndef _CC_SYNTREE_H
#define _CC_SYNTREE_H

#include "../5.CC_lib/ExprCppTreeLexer.h"
#include "../5.CC_lib/ExprCppTreeParser.h"

namespace SKL {
    class SynTree {
    private : 
        pANTLR3_BASE_TREE tree;
        pANTLR3_COMMON_TOKEN tok;
    public : 
        SynTree (pANTLR3_BASE_TREE new_tree) 
        tree (new_tree) {
            tok = this->tree->getToken(this->tree);
        }
        
        SynTree getChild (unsigned childNum);
        const char* getText();
        int getChildNum();
        int getTokType();
        bool tokEmpty();
    };
}

#endif

