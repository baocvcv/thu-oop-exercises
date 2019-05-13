//////////////////////////////////////////////////////////////////////////
// Description: this is the base implementation of a simple maze router
// Author: YHL
// Date: 20120323
// Note: Modify this file and add OptRouter.cpp file for the
//       implementation of the additional functionalities
//////////////////////////////////////////////////////////////////////////
#ifndef OPT_ROUTER_H_
#define OPT_ROUTER_H_

#include "BaseRouter.h"

#include <vector>

class OptRouter:public BaseRouter
{
private:
    int bound;
    std::vector<int> tmp_path;

  public:
    OptRouter(int r, int c, const Point &source, const Point &target, const PointVector &obs)
        : BaseRouter(r, c, source, target, obs)
    {
    }
	~OptRouter() {}

    bool route();
    void mazeBacktrace(int depth, int no_turns);
};

#endif
