#!/usr/bin/python3
"""
Recursive function to query Reddit API, parse titles of
hot articles, and count keywords.
"""

import requests


def count_words(subreddit, word_list, after='', word_count={}):
    """ Recursively counts keywords in hot article titles from a subreddit. """

    # Initialize word count dict on first call
    if not word_count:
        word_count = {word.lower(): 0 for word in word_list}

    # Prepare the URL to query the Reddit API
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    headers = {'User-Agent': 'Mozilla/5.0'}
    params = {'after': after, 'limit': 100}

    # Perform the API request
    try:
        response = requests.get(url, headers=headers, params=params,
                                allow_redirects=False)

        # Check if the subreddit is invalid
        if response.status_code != 200:
            return

        # Parse the JSON response
        data = response.json().get('data', {})
        children = data.get('children', [])
        after = data.get('after', None)

        # Process each article title
        for child in children:
            title = child.get('data', {}).get('title', '').lower().split()
            for word in word_list:
                word_lower = word.lower()
                word_count[word_lower] += title.count(word_lower)

        # If there's another page, call recursively
        if after is not None:
            return count_words(subreddit, word_list, after, word_count)

        # Once recursion is done, sort and print results
        if after is None:
            sorted_words = sorted(
                word_count.items(),
                key=lambda kv: (-kv[1], kv[0])
            )
            for word, count in sorted_words:
                if count > 0:
                    print(f"{word}: {count}")

    except requests.exceptions.RequestException:
        return
