class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        while (maxHeap.size() > 1) {
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();

            if (stone1 != stone2) {
                int diff = stone1 - stone2;
                maxHeap.push(diff);
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};