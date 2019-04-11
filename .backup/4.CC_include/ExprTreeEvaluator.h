/*************************************************************************
	> File Name:    ExprTreeEvaluator.h
	> Author:       sunowsir
	> Mail:         sunow.wang@gmail.com
	> GitHub:       github.com/sunowsir
	> Created Time: 2019年03月31日 星期日 19时11分01秒
 ************************************************************************/
#ifndef _EXPRTREEEVALUATOR_H
#define _EXPRTREEEVALUATOR_H

#include "../5.CC_lib/ExprCppTreeLexer.h"
#include "../5.CC_lib/ExprCppTreeParser.h"
#include <cassert>
#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::cout;


namespace KSLib {
    
    class Master {
    public : 
        pANTLR3_COMMON_TOKEN *tok;
        Master *next;
        
        /* 设置自身能处理的节点 */
        Master(pANTLR3_COMMON_TOKEN init_tok) : tok(init_tok) {}
        
        /* 设置下一个责任人 */
        void setNextPrincipal (Master *NextPrincipal) {
            this->next = NextPrincipal;
        }

        /* 处理办法 */
        virtual void DealWith() = 0;
        virtual ~Master() = 0;
    };

    // class ExprTreeEvaluator {
    // private:
    //     map<string,int> memory;
    //     ExprTreeEvaluator *next;
    // public:
    //     ExprTreeEvaluator (ExprTreeEvaluator *next);
    //     int run(pANTLR3_BASE_TREE);
    //     bool get_Value(string search_var, int &val);
    //     bool set_Value(string set_var, int set_val);
    //     friend pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE, unsigned);
    //     friend const char* getText(pANTLR3_BASE_TREE tree);
    // };

}

#endif

