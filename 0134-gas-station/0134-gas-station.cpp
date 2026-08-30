class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
int total_gas=0;
int cost_gas=0;

       for(int i=0;i<gas.size();i++) {
         total_gas+=gas[i];
         cost_gas+=cost[i];
         }

    if(total_gas<cost_gas) return -1;
    
    int tank=0;
    int start=0;

    for(int i=0;i<gas.size();i++){
        tank+=gas[i]-cost[i];
        if(tank<0){
            tank=0;
            start=i+1;
        }
       
    }
     return start;
}
};