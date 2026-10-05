class Twitter {
private:
  unordered_map<int, deque<pair<int, int>>> tweets;
  unordered_map<int, unordered_set<int>> following;
  int currTime = 0;

public:
  void postTweet(int userId, int tweetId) {
    tweets[userId].emplace_front(currTime++, tweetId);

    if (tweets[userId].size() == 11) {
      tweets[userId].pop_back();
    }
  }

  vector<int> getNewsFeed(int userId) {
    unordered_set<int> feedSet;

    auto getEarliestTweet = [&](int user) -> optional<pair<int, int>> {
      for (auto tweet : tweets[user]) {
        if (!feedSet.contains(tweet.second)) {
          return tweet;
        }
      }
      return nullopt;
    };

    for (int i = 0; i < 10; i++) {
      auto earliestTweet = getEarliestTweet(userId);

      for (int followingId : following[userId]) {
        auto tweet = getEarliestTweet(followingId);

        if (!earliestTweet.has_value() || earliestTweet->first < tweet->first) {
          earliestTweet = tweet;
        }
      }

      if (!earliestTweet.has_value()) {
        break;
      }

      feedSet.insert(earliestTweet->second);
    }

    vector<int> feed(feedSet.begin(), feedSet.end());
    reverse(feed.begin(), feed.end());

    return feed;
  }

  void follow(int followerId, int followeeId) {
    following[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    following[followerId].erase(followeeId);
  }
};
