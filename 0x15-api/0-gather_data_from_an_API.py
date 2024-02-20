#!/usr/bin/python3
""" testing API """
import requests
import sys


if __name__ == "__main__":
    url = "https://jsonplaceholder.typicode.com/"
    user = requests.get(f"{url}users/{sys.argv[1]}").json()
    todos = requests.get(f"{url}users/{sys.argv[1]}/todos").json()

    done = [t.get('title') for t in todos if t.get('completed') is True]

    print(f"Employee {user.get('name')}\
is done with tasks({len(done)}/{len(todos)}):")

    [print(f"\t {c}") for c in done]
