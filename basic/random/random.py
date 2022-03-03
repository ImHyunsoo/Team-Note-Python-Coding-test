import random

n = random.randint(2, 30)
k = random.randint(1, n)
lost = random.sample(range(1, n+1), k)       # 중복없이,  1 ~ n  중에서  랜덤한 수 k개를 뽑음
to = []
to += chr(random.randint(65, 90))  # A(65) ~ Z(90)
random.shuffle(lost)  # 티켓 리스트 셔플
