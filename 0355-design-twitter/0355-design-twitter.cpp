class Twitter {
public:
    struct Node {
        int time;
        int tweetid;
        Node* next;
        Node(int ti, int twee) : time(ti), tweetid(twee), next(nullptr){};
    };
    unordered_map<int, unordered_set<int>> followData;
    unordered_map<int, pair<Node*, Node*>> postData;
    int time = 0;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        time++;
        Node* temp = new Node(time, tweetId);
        if (postData.find(userId) == postData.end()) {
            postData[userId] = make_pair(temp, temp);
        } else {
            temp->next=postData[userId].first;
            postData[userId].first = temp;
        }
    }

    vector<int> getNewsFeed(int userId) {
        auto con = [](Node* n1, Node* n2) { return n1->time < n2->time; };
        priority_queue<Node*, vector<Node*>, decltype(con)> pq;
        if (followData.find(userId) != followData.end()) {
            for (int followeeId : followData[userId]) {
                if (postData.find(followeeId) != postData.end()) {
                    pq.push(postData[followeeId].first);
                }
            }
        }
        if (postData.find(userId) != postData.end())
            pq.push(postData[userId].first);
        vector<int> feed;
        for (int i = 0; i < 10; i++) {
            if (pq.empty())
                return feed;
            Node* temp = pq.top();
            pq.pop();
            feed.push_back(temp->tweetid);
            if (temp->next != nullptr) {
                pq.push(temp->next);
            }
        }
        return feed;
    }

    void follow(int followerId, int f2id) {
        if (followData.find(followerId) == followData.end()) {
            followData[followerId] = unordered_set<int>();
        }
        followData[followerId].insert(f2id);
    }

    void unfollow(int f1id, int f2id) {
        if (followData.find(f1id) == followData.end()) {
            return;
        }
        followData[f1id].erase(f2id);
    }
};

/**

Your Twitter object will be instantiated and called as such:
Twitter* obj = new Twitter();
obj->postTweet(userId,tweetId);
vector<int> param_2 = obj->getNewsFeed(userId);
obj->follow(followerId,followeeId);
obj->unfollow(followerId,followeeId);
*/