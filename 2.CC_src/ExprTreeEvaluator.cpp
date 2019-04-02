/*************************************************************************
	> File Name:    ExprTreeEvaluator.cpp
	> Author:       sunowsir
	> Mail:         sunow.wang@gmail.com
	> GitHub:       github.com/sunowsir
	> Created Time: 2019年03月31日 星期日 19时11分09秒
 ************************************************************************/

#include "../4.CC_include/ExprTreeEvaluator.h"

using namespace ExprTreeEvaluator_Lib;


pANTLR3_BASE_TREE getChild (pANTLR3_BASE_TREE tree, unsigned i) {
    assert(i < tree->getChildCount(tree));
    return (pANTLR3_BASE_TREE) tree->getChild(tree, i);
}

const char* getText (pANTLR3_BASE_TREE tree) {
    return (const char*) tree->getText(tree)->chars;
}


ExprTreeEvaluator::ExprTreeEvaluator (ExprTreeEvaluator *next) {
    this->next = next;
}

int ExprTreeEvaluator::get_Value (string search_value) {
    if (this->memory.find(search_value) != this->memory.end()) {
        return this->memory[search_value];
    } else if (this->next != NULL) {
        return this->next->get_Value(search_value);
    }
    std::cerr << "\033[1;31mNo found variable \"" << search_value << "\"\033[0;m\n";
    exit (-1);
}

int ExprTreeEvaluator::run (pANTLR3_BASE_TREE tree) {
    pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
    if(tok) {
        switch(tok->type) {
            case TOK_BLOCK : {
                ExprTreeEvaluator new_poj(this);
                int tree_num = tree->getChildCount(tree);
                int run_result = 0;
                for (int i = 0; i < tree_num; i++) {
                    run_result = new_poj.run(getChild(tree, i));
                    // cout << "tree value : " << run_result << "\n";
                }
                cout << "Block value : " << run_result << "\n";
                return run_result;
            }
            case INT: {
                const char* s = getText(tree);
                if (s[0] == '~') {
                    return -atoi(s+1);
                } else {
                    return atoi(s);
                }
            }
            case ID: {
                string var(getText(tree));
                cout << "get memory : " << var << "\n";
                return get_Value(var);
            }
            case OPR_COMMA:
                return run(getChild(tree, 0)), run(getChild(tree, 1));
            case OPR_ASSIGN: {
                string var(getText(getChild(tree,0)));
                int val = run(getChild(tree,1));
                memory[var] = val;
                cout << "set " << var << " = " << val << "\n";
                return val;
            }
            case KW_IF: {
                int val = run(getChild(tree, 0));
                if (val) {
                    return run(getChild(tree, 1));
                } else if (getChild(tree, 2) != NULL) {
                    int ret_2 = run(getChild(tree, 2));
                    if (ret_2 == 0 && getChild(tree, 3) != NULL) {
                        return run(getChild(tree, 3));
                    }
                    return ret_2;
                } else if (getChild(tree, 3) != NULL){
                    return run(getChild(tree, 3));
                }
                return 0;
            }
            case KW_ELIF: {
                int val = run(getChild(tree, 0));
                if (val) {
                    return run(getChild(tree, 1));
                }
                return 0;
            }
            case KW_ELSE: {
                if (getChild(tree, 0) != NULL) {
                    return run(getChild(tree, 0));
                } else if (getChild(tree, 1) != NULL) {
                    return run(getChild(tree, 1));
                }
                return 0;
            }
            case KW_FOR: {
                run(getChild(tree, 0));
                int tail_val = 0;
                while (run(getChild(tree, 1))) {
                    run(getChild(tree, 2));
                    tail_val = run(getChild(tree, 3));
                }
                return tail_val;
            }
            case KW_WHILE: {
                int tail_val = 0;
                while (run(getChild(tree, 0))) {
                    tail_val = run(getChild(tree, 1));
                }
                return tail_val;
            }
            case OPR_OR:{
                int ret_val = run(getChild(tree, 0)) || run(getChild(tree, 1));
                return ret_val;
            }
            case OPR_AND:{
                int ret_val = run(getChild(tree, 0)) && run(getChild(tree, 1));
                return ret_val;
            }
            case OPR_BIT_OR: {
                int ret_val = run(getChild(tree, 0)) | run(getChild(tree, 1));
                return ret_val;
            }
            case OPR_XOR: {
                int ret_val = run(getChild(tree, 0)) ^ run(getChild(tree, 1));
                return ret_val;
            }
            case OPR_BIT_AND: {
                int ret_val = run(getChild(tree, 0)) & run(getChild(tree, 1));
                return ret_val;
            }
            case OPR_EQ: {
                int ret_val = run(getChild(tree, 0)) == run(getChild(tree, 1));
                return ret_val;
            }
            case OPR_NE: {
                int ret_val = run(getChild(tree, 0)) != run(getChild(tree, 1));
                return ret_val;
            }
            case OPR_LT: {
                int ret_val = run(getChild(tree, 0)) < run(getChild(tree, 1));
                return ret_val;
            }
            case OPR_LE: {
                int ret_val = run(getChild(tree, 0)) <= run(getChild(tree, 1));
                return ret_val;
            }
            case OPR_GT: {
                int ret_val = run(getChild(tree, 0)) > run(getChild(tree, 1));
                return ret_val;
            }
            case OPR_GE: {
                int ret_val = run(getChild(tree, 0)) >= run(getChild(tree, 1));
                return ret_val;
            }
            case OPR_PLUS: {
                int ret_val = run(getChild(tree, 0)) + run(getChild(tree, 1));
                return ret_val;
            }
            case OPR_MINUS: {
                int ret_val = run(getChild(tree, 0)) - run(getChild(tree, 1));
                return ret_val;
            }
            case OPR_MULT: {
                int ret_val = run(getChild(tree, 0)) * run(getChild(tree, 1));
                return ret_val;
            }
            case OPR_DIVISOR: {
                int ret_val = run(getChild(tree, 0)) / run(getChild(tree, 1));
                return ret_val;
            }
            case OPR_PERCENT: {
                int ret_val = run(getChild(tree, 0)) % run(getChild(tree, 1));
                return ret_val;
            }
            case OPR_NOT: {
                int ret_val = !run(getChild(tree, 0));
                return ret_val;
            }
            default: {
                cout << "\033[1;31m[ERROR]\033[0;m Unknown tok type number : #" << tok->type << '\n';
                return -1;
            }
        }
    } else {
        int k = tree->getChildCount(tree);
        int r = 0;
        for (int i = 0; i < k; i++) {
            r = run(getChild(tree, i));
            // cout << "value : " << r << "\n";
        }
        return r;
    }
}

