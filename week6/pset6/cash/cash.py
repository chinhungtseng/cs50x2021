from cs50 import get_float


def get_cash():
    """Prompt user for cash."""
    while True:
        cash = get_float("Change owed: ")
        if cash > 0.0:
            return cash


def count_coins(cash):
    # Convert cash to pennies.
    cash = int(cash*100)

    coins = {
        25: 0,  # quarters
        10: 0,  # dimes
        5: 0,  # nickels
        1: 0,  # pennies
    }

    for coin in coins:
        while cash >= coin:
            coins[coin] += 1
            cash -= coin

    return sum(coins.values())


def main():
    cash = get_cash()
    total_coins = count_coins(cash)
    print(total_coins)


if __name__ == "__main__":
    main()
