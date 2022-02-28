class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
       vector<string>v;
        if(nums.size()==0){
             return v;
        }
        if(nums.size()==1){
            string str = to_string(nums[0]);
            v.push_back(str);
             return v;
        }
        string str = to_string(nums[0]);
        for(int i = 1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                continue;
            }
            else{
                if(i==1){
                    v.push_back(str);
                    str = to_string(nums[i]);
                    continue;
                }
                else if(nums[i-1]+'0'==str[str.size()-1]){
                    v.push_back(str);
                    str = to_string(nums[i]);
                    continue;
                } 
                str = str+"->"+to_string(nums[i-1]);
                int index = str.find('>');
                cout<<index<<" "<<str.substr(0,index-1);
                if(index!=-1 && str.substr(0,index-1) == str.substr(index+1)){
                    str = to_string(nums[i-1]);
                }
                   
                v.push_back(str);
                str = to_string(nums[i]);
            }
        }
        if(nums[nums.size()-1] == nums[nums.size()-2]+1){
            str = str+"->";
            str = str+to_string(nums[nums.size()-1]);
        }
        v.push_back(str);
        return v;
    }
};
