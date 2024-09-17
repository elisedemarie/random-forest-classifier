# ifndef DATASET_H
# define DATASET_H
# include <vector>
# include <map>
# include <string>
using namespace std;

class DataSet {
    private:
        vector<int> targetVar;
        string targetName;
        int nFeatures = 0;
        map<int, vector<int>> featureVars;
        map<int, string> varNameByIdx;
        map<string, int> varIdxByName;
        vector<int> findSubset(vector<int>* feature, vector<int>* subset);
    public:
        void addFeature(vector<int> feature, string featureName="");
        void addTarget(vector<int> target, string targetname="");
        vector<int>* getFeature(int featureIdx);
        vector<int>* getFeatureByName(string featureName);
        vector<int>* getTarget();
        vector<int> getFeatureSubset(int featureIdx, vector<int>* subset);
        vector<int> getTargetSubset(vector<int>* subset);
};

# endif
