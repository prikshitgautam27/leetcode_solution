class ThroneInheritance {
public:
string king;
unordered_map<string,vector<string>>children;
unordered_set<string>dead;

    ThroneInheritance(string kingName) {
        king =kingName;
    }
    
    void birth(string parentName, string childName) {
        children[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string>res;
        dfs(king,res);
        return res;
    }

    void dfs(string name,vector<string>&order){
        if(dead.find(name)==dead.end()){
            order.push_back(name);
        }
        for(string child:children[name]){
            dfs(child,order);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */