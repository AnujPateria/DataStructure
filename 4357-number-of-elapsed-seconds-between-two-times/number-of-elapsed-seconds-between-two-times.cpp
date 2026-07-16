class Solution {
public:

    int return_second(int x, int y, int z){
        return x * 60 * 60 + y * 60 + z;
    }


    int secondsBetweenTimes(string startTime, string endTime) {
        int x, y, z;

        x = (startTime[0] - '0') * 10 + (startTime[1] - '0');
        y = (startTime[3] - '0') * 10 + (startTime[4] - '0');
        z = (startTime[6] - '0') * 10 + (startTime[7] - '0');
    
        int getstart = return_second(x, y, z);

        x = (endTime[0] - '0') * 10 + (endTime[1] - '0');
        y = (endTime[3] - '0') * 10 + (endTime[4] - '0');
        z = (endTime[6] - '0') * 10 + (endTime[7] - '0');
    
        int getend = return_second(x, y, z);

        return getend - getstart;
    }
};