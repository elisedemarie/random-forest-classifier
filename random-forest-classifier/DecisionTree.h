# ifndef DECISIONTREE_H
# define DECISIONTREE_H
# include <vector>

using namespace std;

class DecisionTree {
    public:
        double calcEntropy(vector<int>* var);
        double calcConditionalEntropy(vector<vector<int>*>* groupedVar);
        double calcInformationGain(vector<int>* var, vector<vector<int>*>* groupedVar);
};

# endif