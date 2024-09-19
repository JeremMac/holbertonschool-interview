#!/usr/bin/python3
"""
Count words in Reddit hot articles.
"""
import requests

def count_words(subreddit, word_list):
    """Recursively count occurrences of keywords in hot articles."""
    if not isinstance(word_list, list) or len(word_list) == 0:
        return

    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    headers = {'User-Agent': 'Mozilla/5.0'}
    response = requests.get(url, headers=headers, allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json()
    articles = data.get('data', {}).get('children', [])
    
    word_count = {}
    for article in articles:
        title = article['data']['title']
        for word in word_list:
            count = title.lower().split().count(word.lower())
            if count > 0:
                if word.lower() in word_count:
                    word_count[word.lower()] += count
                else:
                    word_count[word.lower()] = count

    # Sort the results
    sorted_words = sorted(word_count.items(), key=lambda item: (-item[1], item[0]))

    for word, count in sorted_words:
        print(f"{word}: {count}")

    # If there are more articles, call the function recursively
    after = data.get('data', {}).get('after')
    if after:
        count_words(subreddit, word_list, after)
