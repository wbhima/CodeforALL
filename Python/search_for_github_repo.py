import requests
import json

repo = input("Enter a repo name: ")
print("Searching for " + repo + "...")
print()

url = "https://api.github.com/search/repositories?q=" + repo
response = requests.get(url)
data = response.json()
print("The most appropriate 3 results are: ")
for i in range(3):
    print("> ", data["items"][i]["name"])
    print("> ", data["items"][i]["html_url"])
    print("> ", data["items"][i]["description"])
    print("")
