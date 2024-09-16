# include "../../random-forest-classifier/DecisionTree.h"
# include <vector>
# include <string>
# include <any>
# include <iostream>
# include <cmath>

using namespace std;

void printResult(bool condition, string testName, string returnValue, string targetValue) {
    if (!condition) {
        cout << "FAILED: " << testName << endl;
        cout << "\t excepted:\n\t\t" << targetValue << endl;
        cout << "\t returned:\n\t\t" << returnValue << endl;
    }
    else {
        cout << "PASSED: " << testName << endl;
    }
}

void singleValueVectorReturns0Entropy() {
    string testName = "single vector returns entropy==0";
    // given a single value vector and a decision tree
    vector<int> v = {1};
    DecisionTree* dt = new DecisionTree();
    // when calculating entropy
    double entropy = dt->calcEntropy(&v);
    // then the entropy is 0
    int target = (double)0;
    bool condition = (entropy == target);
    printResult(condition, testName, to_string(target), to_string(entropy));
}

void twoUniqueValueVectorReturns1Entropy() {
    string testName = "two unqiue valued vector returns entropy==1";
    // given a single value vector and a decision tree
    vector<int> v = {1, 2};
    DecisionTree* dt = new DecisionTree();
    // when calculating entropy
    double entropy = dt->calcEntropy(&v);
    // then the entropy is 0
    int target = (double)1;
    bool condition = (entropy == target);
    printResult(condition, testName, to_string(target), to_string(entropy));
}


int main() {
    singleValueVectorReturns0Entropy();
    twoUniqueValueVectorReturns1Entropy();
    return 0;
}