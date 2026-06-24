class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int n = stations.size();
        // if(n == 0 ) return 0;
        long long fuel = startFuel;
        int ans = 0;
        sort(stations.begin(), stations.end());

        for(int i = 0; i < stations.size(); i++){
            int temp = (stations[i][0] - (i-1 >= 0 ? stations[i-1][0] : 0 ));
            if(fuel >= temp){
                fuel = fuel - temp;
                pq.push(stations[i][1]); 
                continue;
            }
            
            while(!pq.empty() && fuel < temp){
                // cout<<fuel<<". "<<pq.top()<<endl;
                ans++;
                fuel += pq.top();
                pq.pop();
            }
            if(fuel >=  temp){
                fuel = fuel -  temp;
                pq.push(stations[i][1]); 
            }
            else {
                return -1;
            }
        }  
        fuel += (n-1 >= 0 ? stations[n-1][0] : 0);      
        
        while(!pq.empty() && (fuel < target)){
            ans++;
            fuel += pq.top();
            pq.pop();
        }
        return fuel >= target ? ans : -1;
    }
};