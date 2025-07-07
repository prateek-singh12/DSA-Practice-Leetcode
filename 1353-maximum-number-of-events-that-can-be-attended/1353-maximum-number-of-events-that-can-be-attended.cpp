class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by start time
        sort(events.begin(), events.end());

        // Min-heap to store end days of events available on current day
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int i = 0, n = events.size();
        int day = 1, count = 0;

        //  maximum end day
        int lastDay = 0;
        for (auto& e : events)
            lastDay = max(lastDay, e[1]);

        while (day <= lastDay) {
            // Push all events starting today into the heap
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]);
                i++;
            }
            // OR FOR ABOVE LOOP:
            // for (; i < n; ++i) {
            //     if (events[i][0] == day) {
            //         minHeap.push(events[i][1]);
            //     } else {
            //         break; 
            //     }
            // }

            // Remove all events that have already expired SKIP
            while (!minHeap.empty() && day > minHeap.top())
                minHeap.pop();

            // Attend the event that ends earliest
            if (!minHeap.empty()) {
                minHeap.pop();
                count++;
            }

            day++;
        }

        return count;
    }
};
