# include "DataSet.h"
# include <vector>
# include <map>
# include <string>

vector<int> DataSet::findSubset(vector<int>* feature, vector<int>* subset) {
    vector<int> subsetVector;
    for (int& idx : *subset) {
        subsetVector.push_back((*feature)[idx]);
    }
    return subsetVector;
}

void DataSet::addFeature(vector<int> feature, string featureName) {
    featureVars[nFeatures] = feature;
    varNameByIdx[nFeatures] = featureName;
    if (varIdxByName.find(featureName) != varIdxByName.end())
        throw invalid_argument("Feature names cannot be duplicates.");
    if (featureName != "") {
        varIdxByName[featureName] = nFeatures;
    }
};

void DataSet::addTarget(vector<int> target, string targetName) {
    targetVar = target;
    targetName = targetName;
}

vector<int>* DataSet::getFeature(int featureIdx) {
    if (varNameByIdx.find(featureIdx) == varNameByIdx.end())
        throw invalid_argument("Feature index does not exist.");
    else
        return &featureVars[featureIdx];
}

vector<int>* DataSet::getFeatureByName(string featureName) {
    if (varIdxByName.find(featureName) == varIdxByName.end())
        throw invalid_argument("Feature name does not exist.");
    else
        return getFeature(varIdxByName[featureName]);
}

vector<int>* DataSet::getTarget() {
    return &targetVar;
}

vector<int> DataSet::getFeatureSubset(int featureIdx, vector<int>* subset) {
    vector<int>* feature = getFeature(featureIdx);
    return findSubset(feature, subset);
}

vector<int> DataSet::getTargetSubset(vector<int>* subset) {
    return findSubset(&targetVar, subset);
}


