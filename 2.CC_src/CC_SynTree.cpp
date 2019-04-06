/*************************************************************************
	> File Name:    CC_SynTree.cpp
	> Author:       sunowsir
	> Mail:         sunow.wang@gmail.com
	> GitHub:       github.com/sunowsir
	> Created Time: 2019年04月05日 星期五 17时04分04秒
 ************************************************************************/
#include "../4.CC_include/CC_SynTree.h"

SKL::SynTree SKL::SynTree::getChild (unsigned childNum) {
    assert(childNum < this->getChildNum());
    SynTree _tempST(this->tree->getChild(this->tree, childNum));
    return _tempST;
}

const char* SKL::SynTree::getText () {
    return this->tree->getText(this->tree)->chars;
}

int SKL::SynTree::getChildNum () {
    return this->tree->getChildCount(this->tree);
}

int SKL::getTokType () {
    return this->tok->type;
}

bool SKL::tokEmpty() {
    return (this->tok ? false : true);
}
