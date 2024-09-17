# include "DecisionTree.h"
# include <vector>
# include <iostream>

using namespace std;
int main() {
    vector<int> targetVar = {1, 1, 0, 0, 0};
    vector<int> var = {2, 3, 0, 2, 0};
    DecisionTree* dt = new DecisionTree();
    double entropy = dt->calcInformationGain(&targetVar, &var);
    cout << entropy << endl;
    return 0;
}