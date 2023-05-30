my_set = set()

N = int(input())

for i in range(N):
    user_input = input().split()
    if user_input[1] == 'leave':
        if user_input[0] in my_set:
            my_set.remove(user_input[0])
    else:
        my_set.add(user_input[0])

for person in sorted(my_set, reverse=True):
    print(person)

# n = int(input())  # 출입 기록의 수
#
# log = {}  # 출입 상태를 기록할 사전
#
# for _ in range(n):
#     name, status = input().split()  # 이름과 출입 상태 입력 받기
#
#     if status == "enter":
#         log[name] = "enter"  # 출근 상태로 기록
#     else:
#         del log[name]  # 퇴근 상태로 기록 (기존에 없는 경우는 무시)
#
# # 현재 회사에 있는 사람들을 구하기 위해 "enter"인 사람들을 찾음
# people = [name for name, status in log.items() if status == "enter"]
#
# # 이름을 사전 순으로 정렬한 후, 역순으로 출력
# for name in sorted(people, reverse=True):
#     print(name)
