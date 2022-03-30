import json

# 사전 자료형(dict) 데이터 선언
user = {
    "id": "gildong123",
    "password": "1!2@3#4$",
    "age": 30,
    "hobby": ["football", "programming"]
}

# 파이썬 변수를 JSON 객체로 변환
json_data = json.dumps(user, indent=4)
print(json_data)
