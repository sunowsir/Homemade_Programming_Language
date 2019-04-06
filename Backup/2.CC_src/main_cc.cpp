#include "../4.CC_include/ExprTreeEvaluator.h"

using namespace KSLib;;

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
    
    return ;
}

int main (int argc, char* argv[]) {
    Analysis_Start(argc, argv);
    return 0;
}
