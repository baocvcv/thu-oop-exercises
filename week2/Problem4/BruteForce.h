#include <vector>

class BruteForce{
    public:
    int solve(std::vector<int> T, std::vector<int> M, int totalT);

    private:
    int dfs(std::vector<int> T, std::vector<int> M, int totalT, int depth);
};