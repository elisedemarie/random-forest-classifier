# ifndef VARPROCESSOR_H
# define VARPROCESSOR_H
# include <vector>

using namespace std;

class VarProcessor {
    public:
        vector<vector<int>> groupVarByClass(vector<int> var, vector<int> classVar);
};

# endif