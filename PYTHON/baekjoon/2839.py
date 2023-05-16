def five(N):
    for i in range(N):
        for j in range(N):
            if 5 * j + 3 * i == N:
                return i + j
    return -1

N = int(input())
sugar_bags = five(N)

print(sugar_bags)


#N = int(input())

# 큰 봉지인 5킬로그램 봉지부터 사용하여 나누는 것이 최소 봉지 개수를 구하는 방법입니다.
# 큰 봉지를 우선 사용하고, 나머지를 작은 봉지로 나누어야 합니다.

# 큰 봉지의 개수를 늘려가며 나눠본다.
#bag_count = N // 5

#while bag_count >= 0:
#    remainder = N - (5 * bag_count)
#    if remainder % 3 == 0:
#        # 나누어 떨어지는 경우, 작은 봉지의 개수를 더해줍니다.
#        bag_count += remainder // 3
#        break
#    bag_count -= 1
#
# 결과 출력
#if bag_count < 0:
#    print(-1)  # 정확하게 N킬로그램을 만들 수 없는 경우
#else:
#    print(bag_count)
