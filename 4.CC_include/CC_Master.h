/*************************************************************************
	> File Name:    CC_Master.h
	> Author:       sunowsir
	> Mail:         sunow.wang@gmail.com
	> GitHub:       github.com/sunowsir
	> Created Time: 2019年04月05日 星期五 17时22分04秒
 ************************************************************************/
#ifndef _CC_MASTER_H
#define _CC_MASTER_H

#include "../4.CC_include/CC_SynTree.h"
#include "../4.CC_include/CC_Types.h"
#include <map>

using std::map;

namespace SKL {
    class Master {
    protected : 
        map<string, Types> memory;
    public : 
        Master *nextHandle;
        Master *headHandle;
        
        virtual Master () = 0;
        virtual ~Master() = 0;
        
        virtual Types Parsing (SynTree& STree) = 0;
    };

    class BlockMaster : 
    public : Master {
    private : 
    public : 
        BlockMaster (BlockMaster* new_nextHandle = nullptr, 
                     BlockMaster* new_headHandle = nullptr) : 
                        nextHandle (new_nextHandle), 
                        headHandle (headHandle) {}
        ~BlockMaster () {}
        
        Types Parsing (SynTree& Stree);
    };
}

#endif

