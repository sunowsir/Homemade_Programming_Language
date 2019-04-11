/*************************************************************************
	> File Name:    CC_Types.cpp
	> Author:       sunowsir
	> Mail:         sunow.wang@gmail.com
	> GitHub:       github.com/sunowsir
	> Created Time: 2019年04月07日 星期日 19时49分03秒
 ************************************************************************/
#include "../include/CC_Types.h"


    template <typename T>
    class Types {
    private :
        T data;
    public :
        Types (T initData) : data (initData) {}
        bool setVal (T newVal) {
            return (this->data = newVal);
        }
        T getValue () {
            return this->data;
        }
    };

