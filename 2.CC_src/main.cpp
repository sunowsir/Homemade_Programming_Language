#include "ExprCppTreeLexer.h"
#include "ExprCppTreeParser.h"
#include <cassert>
#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::cout;

class ExprTreeEvaluator {
private:
    map<string,int> memory;
    ExprTreeEvaluator *next;
public:
    ExprTreeEvaluator (ExprTreeEvaluator *next);
    int run(pANTLR3_BASE_TREE);
    int get_Value(string search_value);
};


pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE, unsigned);
const char* getText(pANTLR3_BASE_TREE tree);


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
                    cout << "value : " << run_result << "\n";
                }
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
                return get_Value(var);
            }
            case OPR_COMMA: 
                return run(getChild(tree, 0)), run(getChild(tree, 1));
            case OPR_ASSIGN: {
                string var(getText(getChild(tree,0)));
                int val = run(getChild(tree,1));
                memory[var] = val;
                return val;
            }
            case TOK_IF: {
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
            case TOK_ELIF: {
                int val = run(getChild(tree, 0));
                if (val) {
                    return run(getChild(tree, 1)); 
                } 
                return 0;
            }
            case TOK_ELSE: {
                if (getChild(tree, 0) != NULL) {
                    return run(getChild(tree, 0));
                } else if (getChild(tree, 1) != NULL) {
                    return run(getChild(tree, 1));
                }
                return 0;
            }
            case OPR_OR: 
                return run(getChild(tree, 0)) || run(getChild(tree, 1));
            case OPR_AND: 
                return run(getChild(tree, 0)) && run(getChild(tree, 1));
            case OPR_BIT_OR: 
                return run(getChild(tree, 0)) | run(getChild(tree, 1));
            case OPR_XOR: 
                return run(getChild(tree, 0)) ^ run(getChild(tree, 1));
            case OPR_BIT_AND: 
                return run(getChild(tree, 0)) & run(getChild(tree, 1));
            case OPR_EQ: 
                return run(getChild(tree, 0)) == run(getChild(tree, 1));
            case OPR_NE: 
                return run(getChild(tree, 0)) != run(getChild(tree, 1));
            case OPR_LT:
                return run(getChild(tree, 0)) < run(getChild(tree, 1));
            case OPR_LE:
                return run(getChild(tree, 0)) <= run(getChild(tree, 1));
            case OPR_GT:
                return run(getChild(tree, 0)) > run(getChild(tree, 1));
            case OPR_GE:
                return run(getChild(tree, 0)) >= run(getChild(tree, 1));
            case OPR_PLUS:
                return run(getChild(tree, 0)) + run(getChild(tree, 1));
            case OPR_MINUS:
                return run(getChild(tree, 0)) - run(getChild(tree, 1));
            case OPR_MULT:
                return run(getChild(tree, 0)) * run(getChild(tree, 1));
            case OPR_DIVISOR:
                return run(getChild(tree, 0)) / run(getChild(tree, 1));
            case OPR_PERCENT:
                return run(getChild(tree, 0)) % run(getChild(tree, 1));
            case OPR_NOT:
                return !run(getChild(tree, 0));
            default:
                cout << "Unhandled token: #" << tok->type << '\n';
                return -1;
        }
    } else {
        int k = tree->getChildCount(tree);
        int r = 0;
        for (int i = 0; i < k; i++) {
            r = run(getChild(tree, i));
            cout << "value : " << r << "\n";
        }
        return r;
    }
}

pANTLR3_BASE_TREE getChild (pANTLR3_BASE_TREE tree, unsigned i) {
    assert(i < tree->getChildCount(tree));
    return (pANTLR3_BASE_TREE) tree->getChild(tree, i);
}

const char* getText (pANTLR3_BASE_TREE tree) {
    return (const char*) tree->getText(tree)->chars;
}

void Analysis_Start(int argc, char **argv) {
    pANTLR3_INPUT_STREAM input;
    pExprCppTreeLexer lex;
    pANTLR3_COMMON_TOKEN_STREAM tokens;
    pExprCppTreeParser parser;

    assert(argc > 1);
    input = antlr3FileStreamNew((pANTLR3_UINT8)argv[1],ANTLR3_ENC_8BIT);
    lex = ExprCppTreeLexerNew(input);

    tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT,
                                              TOKENSOURCE(lex));
    parser = ExprCppTreeParserNew(tokens);

    ExprCppTreeParser_prog_return r = parser->prog(parser);

    pANTLR3_BASE_TREE tree = r.tree;

    ExprTreeEvaluator eval(NULL);
    int res = eval.run(tree);
    cout << "Evaluator result: " << res << '\n';

    parser->free(parser);
    tokens->free(tokens);
    lex->free(lex);
    input->close(input);

}

int main (int argc, char* argv[]) {
    Analysis_Start(argc, argv);
    return 0;
}
