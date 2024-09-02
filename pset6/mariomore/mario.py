from cs50 import get_int


def main():
    # Taking input Height:
    pyramid = 0
    height = get_int("Enter Height: ")
    while (height <= 0 or height > 8):
        height = get_int("Enter Height: ")

    # Drawing pyramids
    for i in range(height):  # Nested loop
        for j in range(height):
            if (j >= height - 1 - i):  # Conditions
                print("#", end="")
            else:
                print(" ", end="")
        print("  ", end="")
        for n in range(height):
            if (n <= pyramid):        # Conditions
                print("#", end="")
        print()
        pyramid += 1


if __name__ == "__main__":
    main()