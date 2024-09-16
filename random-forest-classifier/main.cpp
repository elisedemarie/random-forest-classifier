# include "DecisionTree.h"
# include <vector>
# include <iostream>

using namespace std;
int main() {
    vector<int>* v1 = new vector<int>({1, 2, 3});
    vector<int>* v2 = new vector<int>({1, 2, 3, 3});
    vector<int>* vC = new vector<int>({1, 2, 3, 1, 2, 3, 3});

    vector<vector<int>*>* v3 = new vector<vector<int>*>({v1, v2});
    DecisionTree* dt = new DecisionTree();
    double entropy = dt->calcInformationGain(vC, v3);
    cout << entropy << endl;
    return 0;
}