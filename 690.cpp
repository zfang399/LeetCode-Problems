/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> map;
        for(int i=0;i<employees.size();i++){
            map[employees[i]->id]=employees[i];
        }
        return dfs(map,id);
    }
    int dfs(unordered_map<int, Employee*>& map, int id){
        int ret=map[id]->importance;
        for(int i=0;i<map[id]->subordinates.size();i++){
            ret+=dfs(map,map[id]->subordinates[i]);
        }
        return ret;
    }
};
