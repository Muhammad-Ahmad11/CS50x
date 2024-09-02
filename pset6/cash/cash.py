from cs50 import get_float


def main():

    dollars = 0.0
    coins = 0
    cents = 0
    dollars = get_float("Change owned: ")      # Taking amount in dollars (float)
    while (dollars < 0):
        dollars = get_float("Change owned: ")       # Taking amount in dollars (float)
    dollars = dollars * 100
    cents = round(dollars)   # round used here to get correct values
    # Conditions to calculate exact coins
    while (cents != 0):
        if (cents >= 25):        # if cents greater than 25 detuct them first
            cents = cents - 25
            coins += 1
        elif (cents >= 10):    # if cents greater than 10 detuct them first
            coins += 1
            cents = cents - 10
        elif (cents >= 5):      # if cents greater than 5 detuct them first
            coins += 1
            cents = cents - 5
        elif (cents >= 1):      # if cents greater than 25 detuct them first
            coins += 1
            cents = cents - 1
        else:                     # if on reamining cash left then break
            break
    print(coins)    # Printing coins


if __name__ == "__main__":
    main()