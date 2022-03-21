import requests

target = "https://jsonplaceholder.typicode.com/users"
response = requests.get(url=target)
print(response.text)
