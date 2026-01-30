class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        int sz = q.size();
        int half = sz / 2;

        vector<int> first, second;

        for (int i = 0; i < half; i++) {
            first.push_back(q.front());
            q.pop();
        }

        for (int i = 0; i < half; i++) {
            second.push_back(q.front());
            q.pop();
        }

        for (int i = 0; i < half; i++) {
            q.push(first[i]);
            q.push(second[i]);
        }
    }
};
