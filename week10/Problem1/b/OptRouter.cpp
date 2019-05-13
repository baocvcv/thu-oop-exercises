#include "OptRouter.h"

#include <cstdio>

const static int X[4] = {1,-1,0,0};
const static int Y[4] = {0,0,1,-1};

//maze routing
bool OptRouter::route(){
	if (this->m_sourceIndex < 0 || this->m_targetIndex < 0 || this->m_row <= 0 || this->m_col <= 0)
		return false;

	this->m_path.clear();

	//initialize the cost of the source grid
	m_grids[this->m_sourceIndex] = 0;

    //maze expansion
	if (mazeSearch())
	{
        this->bound = this->m_grids.size();
        this->tmp_path.push_back(m_targetIndex);
        mazeBacktrace(0, 0);
		return true;
	}
	else
		return false;
}

// trace back
void OptRouter::mazeBacktrace(int depth, int no_turns){
    int curIndex = this->tmp_path[depth];
    int curCost = this->m_grids[curIndex];
    int x, y;
    compXYIndex(curIndex, x, y);

    printf("BackTrace grid [%d,%d] cost %d turns %d\n", x, y, curCost, no_turns);
    for (int i = 0; i < 4; i++){
        int newX = x + X[i];
        int newY = y + Y[i];
        if (newY >= 0 && newY < this->m_row && newX >= 0 && newX < this->m_col){
            int newIndex = compIndex(newX, newY);
            if(this->m_grids[newIndex]+1 == curCost){
                // check for turns
                int hasTurn = 0;
                if(depth + 1 >= 2){
                    int i1(curIndex);
                    int i2(tmp_path[depth - 1]);
                    int i3(newIndex);
                    if (i1%m_col == i2%m_col && i2%m_col == i3%m_col) {
                        hasTurn = 0;
                    }else if (i1/m_col == i2/m_col && i2/m_col == i3/m_col){
                        hasTurn = 0;
                    }else{
                        hasTurn = 1;
                    }
                }

                // check boundary
                if(no_turns + hasTurn >= bound){
                    continue;
                }
                tmp_path.push_back(newIndex);

                // search
                if(newIndex == m_sourceIndex){
                    bound = no_turns + hasTurn;
                    m_path = tmp_path;
                    printf("Found path with %d turns: ", bound);
                    for (unsigned i = 0; i < this->m_path.size(); ++ i)
                    {
                        int index = this->m_path[i];
                        int x, y;
                        this->compXYIndex(index, x, y);
                        printf("[%d,%d] ", x, y);
                    }
                    printf("\n");
                }else{
                    mazeBacktrace(depth + 1, no_turns + hasTurn);
                }
                tmp_path.pop_back();
            }
        }
    }
}