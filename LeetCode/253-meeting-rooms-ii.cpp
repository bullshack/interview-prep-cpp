// Time: O(N^2), Space: O(1)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals.size();
        sort(intervals.begin(), intervals.end(), 
            [] (const auto& i, const auto& j) {
                return i[0] < j[0];
            });
        int roomsRequired = 1;
        for (int i = 1; i < intervals.size(); i++) {
            int currRoomsRequired = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (intervals[i][0] < intervals[j][1]) {
                    currRoomsRequired++;
                }
            }
            roomsRequired = max(roomsRequired, currRoomsRequired);
        }
        return roomsRequired;
    }
};