class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxDis = INT_MIN;
        for(int i = 0;i<seats.size();i++){
            if(seats[i] == 0){
                int j = i+1;
                while(j<seats.size() && seats[j] == 0)
                    j++;
                
                int k  = i-1;
                while(k>=0 && seats[k] == 0)
                    k--;
                
                if(j<seats.size() && k>=0 && seats[k] && seats[j]){
                    maxDis = max(maxDis,min(abs(i-j),abs(i-k)));
                }
                else if(j<seats.size()){
                    maxDis = max(maxDis,abs(i-j));
                }
                else
                    maxDis = max(maxDis,abs(i-k)); 
            }
        }
        return maxDis;
    }
};

// 2nd Approach
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int n = seats.size();
        vector<int>left(n),right(n);
        int filled = -1;
        for(int i = 0;i<n;i++){
            if(seats[i]){
                filled = i;
                left[i] = -1;
            }
            else
                left[i] = filled == -1 ? INT_MAX : filled;
        }
        filled = -1;
        for(int i = n-1;i>=0;i--){
            if(seats[i]){
                filled = i;
                right[i] = i;
            }
            else
                right[i] = filled == -1 ? INT_MAX : filled;
        }
                
        int maxDis = 0;
        
        for(int i = 0;i<n;i++){
            if(seats[i]==0)
            maxDis = max(maxDis,min(abs(i-left[i]),abs(i-right[i])));
        }
        return maxDis;
    }
};
