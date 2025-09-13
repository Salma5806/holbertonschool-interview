#!/usr/bin/python3
"""
Recursive function that queries the Reddit API, parses the titles
of all hot articles, and prints a sorted count of given keywords.
"""

import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """Recursively count occurrences of each word in hot article titles"""
    if counts is None:
        # Initialisation : dictionnaire des comptes
        counts = {}
        for word in word_list:
            word = word.lower()
            counts[word] = counts.get(word, 0)

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "holberton_count_script"}
    params = {"limit": 100, "after": after}
    resp = requests.get(url, headers=headers,
                        params=params, allow_redirects=False)

    if resp.status_code != 200:
        return  # Subreddit invalide → rien à afficher

    data = resp.json().get("data", {})
    children = data.get("children", [])

    for child in children:
        title = child.get("data", {}).get("title", "").lower().split()
        for word in word_list:
            w = word.lower()
            counts[w] += title.count(w)

    # Vérifier s’il reste d’autres pages
    after = data.get("after")
    if after:
        return count_words(subreddit, word_list, after, counts)

    # ---- Fin de la récursion : impression des résultats ----
    # On enlève les mots avec 0 occurrence
    results = {k: v for k, v in counts.items() if v > 0}

    if results:
        # Tri : d’abord par fréquence décroissante, puis alphabétique croissant
        sorted_results = sorted(results.items(),
                                key=lambda x: (-x[1], x[0]))
        for word, count in sorted_results:
            print(f"{word}: {count}")