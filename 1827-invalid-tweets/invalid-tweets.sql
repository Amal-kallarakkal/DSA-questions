# Write your MySQL query statement below
-- SELECT tweet_id FROM Tweets WHERE LEN(tweet_id) > 15;

SELECT tweet_id FROM Tweets WHERE LENGTH(content) > 15;