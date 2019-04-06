/*************************************************************************
	> File Name:    CC_Master.cpp
	> Author:       sunowsir
	> Mail:         sunow.wang@gmail.com
	> GitHub:       github.com/sunowsir
	> Created Time: 2019年04月05日 星期五 17时22分10秒
 ************************************************************************/
#include "../4.CC_include/CC_Master.h"

SKL::Types SKL::BlockMaster::Parsing (SKL::SynTree& Stree) {
    if (Stree->tokEmpty()) {
        switch (Stree->getTokType()) {
            case TOK_BLOCK : {
                // ExprTreeEvaluator new_poj(this);
                // int tree_num = tree->getChildCount(tree);
                // int run_result = 0;
                // for (int i = 0; i < tree_num; i++) {
                //     run_result = new_poj.run(getChild(tree, i));
                //     // cout << "tree value : " << run_result << "\n";
                // }
                // cout << "Block value : " << run_result << "\n";
                // return run_result;
            }
        }
    }
}

