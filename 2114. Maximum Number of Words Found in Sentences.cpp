class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int count = 0,maxCount = 0;
        for(int j = 0;j<sentences.size();j++){
            count = 0;
            for(int i=0;i<sentences[j].size();i++){
                if(sentences[j][i] == ' ')
                    count++;
            }
            
            maxCount = max(maxCount,count);
        }
        return maxCount+1;
    }
};
