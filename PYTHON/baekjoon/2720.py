def get_change(change):
    coins = [25, 10, 5, 1]
    coin_counts = [0, 0, 0, 0]

    remaining_change = change

    for i, coin in enumerate(coins):
        count, remaining_change = divmod(remaining_change, coin)
        coin_counts[i] = int(count)

    return coin_counts

count = int(input())

for i in range(count):
    change_cents = int(input())
    result = get_change(change_cents)
    for j in result:
        print(j, end = " ")
    print()
