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
    map<string,int> memory;
public:
    ExprTreeEvaluator (ExprTreeEvaluator *next);
    int run(pANTLR3_BASE_TREE);
    ExprTreeEvaluator *next;
    int get_Value(string search_value);
};

pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE, unsigned);
const char* getText(pANTLR3_BASE_TREE tree);

int main (int argc, char* argv[]) {
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
    int rr = eval.run(tree);
    cout << "Evaluator result: " << rr << '\n';

    parser->free(parser);
    tokens->free(tokens);
    lex->free(lex);
    input->close(input);

    return 0;
}

int ExprTreeEvaluator::get_Value (string search_value) {
    if (this->memory.find(search_value) != this->memory.end()) {
        return this->memory[search_value];
    } else if (this->next != NULL) {
        return this->next->get_Value(search_value);
    } 
    return -1;
}

ExprTreeEvaluator::ExprTreeEvaluator(ExprTreeEvaluator *next) {
    this->next = next;
}

int ExprTreeEvaluator::run(pANTLR3_BASE_TREE tree) {
    pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
    if(tok) {
        switch(tok->type) {
            case BLOCK : {
                int tree_num = tree->getChildCount(tree);
                int run_result = 0;
                for (int i = 0; i < tree_num; i++) {
                    run_result = run(getChild(tree, i));
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
                ExprTreeEvaluator now_prj(this);
                string var(getText(tree));
                int ret_value = now_prj.get_Value(var);
                if (ret_value == -1) {
                    std::cerr << "\033[1;31m undef variable \"" << var << "\"\033[0;m\n";
                    exit (-1);
                }
                return ret_value;
            }
            case COMMA: 
                return run(getChild(tree, 0)), run(getChild(tree, 1));
            case PLUS:
                return run(getChild(tree, 0)) + run(getChild(tree, 1));
            case MINUS:
                return run(getChild(tree, 0)) - run(getChild(tree, 1));
            case TIMES:
                return run(getChild(tree, 0)) * run(getChild(tree, 1));
            case ASSIGN: {
                string var(getText(getChild(tree,0)));
                int val = run(getChild(tree,1));
                memory[var] = val;
                return val;
            }
            default:
                cout << "Unhandled token: #" << tok->type << '\n';
                return -1;
        }
    } else {
        int k = tree->getChildCount(tree);
        int r = 0;
        for (int i = 0; i < k; i++) {
            r = run(getChild(tree, i));
            printf("value = %d\n", r);
        }
        return r;
    }
}

pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE tree, unsigned i) {
    assert(i < tree->getChildCount(tree));
    return (pANTLR3_BASE_TREE) tree->getChild(tree, i);
}

const char* getText(pANTLR3_BASE_TREE tree) {
    return (const char*) tree->getText(tree)->chars;
}
