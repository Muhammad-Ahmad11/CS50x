from cs50 import get_string
import math


def main():
    # Getting string input
    text = get_string("Enter Text: ")
    length = len(text)
    letters = 0
    words = 0
    sentences = 0

    # Counting letters
    for i in range(length):
        if ((text[i] >= "A" and text[i] <= "Z") or (text[i] >= "a" and text[i] <= "z")):
            letters += 1

    # Counting words
    for i in range(length):
        if (text[i] == ' '):
            words += 1
    words += 1

    # Counting Sentences
    for i in range(length):
        if (text[i] == '?' or text[i] == '!' or text[i] == '.'):
            sentences += 1

    # Formula
    L = ((letters / words) * 100)
    S = ((sentences / words) * 100)
    Grade = round(0.0588 * L - 0.296 * S - 15.8)

    c = 0    # check

    # Making Grade by using ceil and floor operations
    for i in range(16):
        check = i + 0.5
        if (round(Grade) == check):
            Grade = math.ceil(Grade)
            c = 1
            break
        if (round(Grade) < check):
            Grade = math.floor(Grade)
            c = 1
            break
    if (c == 0):
        Grade = math.ceil(Grade)

    # Printing Exact Grade
    Final_Grade = 0
    Final_Grade = Grade
    if (Final_Grade < 1):
        print("Before Grade 1")
    elif (Final_Grade >= 16):
        print("Grade 16+")
    else:
        print("Grade ")
        print(Final_Grade)


if __name__ == "__main__":
    main()