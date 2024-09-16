# include "DecisionTree.h"
# include <vector>
# include <map>
# include <math.h>
# include <iostream>

using namespace std;

double DecisionTree::calcEntropy(vector<int>* variable){
    int variableSize = variable->size();
    map<int, int> valuesCount;
    double entropy = 0.;
    for (const int& value : *variable) {
        if (!valuesCount[value]) {
            valuesCount[value] = 1;
            }
        else
            valuesCount[value]++;
    }
    map<int, int>::iterator it;
    for (it = valuesCount.begin(); it != valuesCount.end(); it++) {
        double p = (float)it->second / (float)variableSize;
        entropy -= p * log2(p);
    }
    return entropy;
}

double DecisionTree::calcConditionalEntropy(vector<vector<int>*>* groupedVar) {
    double conditionalEntropy = 0;
    int totalSize = 0;
    for (vector<int>* variable : *groupedVar) {
        double entropy = calcEntropy(variable);
        conditionalEntropy += (double)variable->size() * entropy;
        totalSize += variable->size();
    }
    return conditionalEntropy / (double)totalSize;
}

double DecisionTree::calcInformationGain(vector<int>* var, vector<vector<int>*>* groupedVar) { 
    double entropy = calcEntropy(var);
    double conditionalEntropy = calcConditionalEntropy(groupedVar);
    return entropy-conditionalEntropy;
}