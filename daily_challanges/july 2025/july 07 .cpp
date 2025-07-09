leetcode 1353       
class Solution {
public:

    int maxEvents(vector<vector<int>>& events) {
       int count=0;
       int i=0;
       int n=events.size();
       sort(events.begin(),events.end());
       int day=events[0][0];
       priority_queue<int,vector<int>,greater<int>>pq; // min heap of end day
       while(i<n || !pq.empty())
       {
            while( i< n && events[i][0] == day )
            {
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty())
            {
                pq.pop();
                count++;
            }
            day++;
            while(!pq.empty() && pq.top() < day)
            {
                pq.pop();
            }
       }
       return count;
    }
};
