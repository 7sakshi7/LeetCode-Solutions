class Solution {
public:
    bool isRobotBounded(string ins) {
        char dir = 'N';
        int xcor = 0,ycor = 0;
        
        for(int i=0;i<ins.size();i++){
            if(ins[i] == 'G'){
                if(dir == 'N')
                    ycor++;
                else if(dir == 'S')
                    ycor--;
                else if(dir == 'E')
                    xcor++;
                else
                    xcor--;
            }
            else if(ins[i] == 'L'){
                if(dir == 'N')
                    dir = 'W';
                else if(dir == 'S')
                   dir = 'E';
                else if(dir == 'E')
                    dir = 'N';
                else
                    dir = 'S';
            }
            else{
                if(dir == 'N')
                    dir = 'E';
                else if(dir == 'S')
                   dir = 'W';
                else if(dir == 'E')
                    dir = 'S';
                else
                    dir = 'N';
            }
        }
        if(dir != 'N' || (ycor==0&&xcor==0))
            return true;
        return false;
    }
};
