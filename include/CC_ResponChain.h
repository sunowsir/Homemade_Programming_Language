/*************************************************************************
	> File Name:    CC_ResponChain.h
	> Author:       sunowsir
	> Mail:         sunow.wang@gmail.com
	> GitHub:       github.com/sunowsir
	> Created Time: 2019年04月05日 星期五 17时22分04秒
 ************************************************************************/
#ifndef _CC_RESPONCHAIN_H
#define _CC_RESPONCHAIN_H

#include "../include/CC_VarStore.h"
#include "../include/CC_SynTree.h"
#include "../include/CC_Types.h"
#include <map>

using std::map;



namespace SKL {

    class Master {
    protected :
        Master* nextMaster;
    public :
        Master (Master* Initnext = nullptr) {
            this->nextMaster = Initnext;
        }
        virtual Master* getNextMaster() = 0;
        virtual bool IsMyRespon (SynTree& STree) = 0;
        virtual Types Parsing (SynTree& STree) = 0;
    };

    /* Processing operations. */
    class OperaMaster :
    public Master {
    public :
        OperaMaster (Master* Initnext = nullptr);
        Master* getNextMaster();
        bool IsMyRespon(SynTree& STree);
        Types Parsing(SynTree& STree);
    };

    /* Processing problem about scope (not including circulate problem)  */
    class ScopeMaster :
    public Master {
    public :
        ScopeMaster (Master* Initnext = nullptr);
        Master* getNextMaster();
        bool IsMyRespon(SynTree& STree);
        Types Parsing(SynTree& STree);
    };

    /* Processing problem about variable.  */
    class VariableMaster :
    public Master {
    public :
        VariableMaster (Master* Initnext = nullptr);
        Master* getNextMaster();
        bool IsMyRespon(SynTree& STree);
        Types Parsing(SynTree& STree);
    };

    /* Processing circulate.  */
    class CirculateMaster :
    public Master {
    public :
        CirculateMaster (Master* Initnext);
        Master* getNextMaster();
        bool IsMyRespon(SynTree& STree);
        Types Parsing(SynTree& STree);
    };

    class ResponChain {
    private :
        Master *headMaster;
        VarStore *store;
    public :
        ResponChain ();
        Types Accountability(SynTree& STree);
    };

}




#endif

