# include "VarProcessor.h"
# include <vector>
# include <map>

using namespace std;

vector<vector<int>> VarProcessor::groupVarByClass(vector<int> var, vector<int> classVar) {
    map<int, vector<int>> groupedVarMap;
    vector<vector<int>> groupedVar;
    for (int i=0; i<classVar.size(); i++) {
        if (groupedVarMap.find(classVar[i]) == groupedVarMap.end())
            groupedVarMap[i] = {var[i]};
        else
            groupedVarMap[i].push_back(var[i]);
    }
    map<int, vector<int>>::iterator it;
    for (it = groupedVarMap.begin(); it != groupedVarMap.end(); it++) {
        groupedVar.push_back(it->second);
    }
    return groupedVar;       
}
