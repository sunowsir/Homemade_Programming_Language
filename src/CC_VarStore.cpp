/*************************************************************************
	> File Name:    CC_VarStore.cpp
	> Author:       sunowsir
	> Mail:         sunow.wang@gmail.com
	> GitHub:       github.com/sunowsir
	> Created Time: 2019年04月07日 星期日 13时28分27秒
 ************************************************************************/
#include "../include/CC_VarStore.h"

bool SKL::VarStore::setValue (string varName, const Types& val) {
    if (varName == "") {
        throw runtime_error("Invalid variable name <The variable name is empty>");
        return false;
    }
    if (this->memory.find(varName) == this->memory.end()) {
        if (this->FatherStore == nullptr) 
            throw runtime_error("No found this variable in this variable store");
        return this->FatherStore->setValue(varName, val);
    }
    this->memory[varName] = val;
    return true;
}

void SKL::VarStore::setValue (string varName) {
    Types _temp;
    this->memory[varName] = _temp;
}

SKL::Types& SKL::VarStore::getValue (string varName) {
    if (varName == "") {
        throw runtime_error("Invalid variable name <The variable name is empty>");
    }
    if (this->memory.find(varName) == this->memory.end()) {
        if (this->FatherStore == nullptr) 
            throw runtime_error("No found this variable in this variable store");
        return this->FatherStore->getValue(varName);
    }
    return this->memory[varName];
}


