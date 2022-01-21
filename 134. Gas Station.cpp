class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        multimap<int,int>m;
        for(int i=0;i<n;i++){
            m.insert({cost[i],i});
        }
        
        for(auto it : m){
            int i = it.second;
            bool pathFound = true;
            int gasLeft = gas[it.second];
            int count = 1;
            while(count<=n){  
                if(gasLeft<=0){
                    pathFound = false;
                    break;
                }
                gasLeft-=cost[i];
                if(gasLeft<0){
                    pathFound = false;
                    break;
                }
                i = (i+1)%n;
                gasLeft+=gas[i];
                count++;
            }
            if(pathFound)
                return it.second;
        }
        return -1;
    }
};
