import csv
import sys
import linecache as row


def main():

    if len(sys.argv) != 3:
        sys.exit("Usage: python tournament.py FILENAME")  # if total arguments are not provided then this will executed
    number = 0
    DNA = []
    with open(sys.argv[1]) as csvfile:    # open csv file large or small from database
        infile = csv.DictReader(csvfile)
        for line in infile:
            DNA.append(line)
            number += 1                  # total row in csv file means total persons

        text = row.getline(sys.argv[2], 1)  # reading genes sequence from text file

        dictkeys = []
        for i in DNA[0].keys():
            dictkeys.append(i)

        genes = 0
        values = []
        for step in dictkeys:
            if(step != "name"):  # as we also store name as in dict keys at first but we consider only genes so we are ignoring name
                start = maxi = end = count = 0
                length = len(text)
                end = len(step)
                for value in range(length):
                    if text[start:end] == step:
                        # checking that first genetic word is found at which location in genes b incrementing start position and end ending position by 1
                        count = 0
                        while text[start:end] == step:
                            # if found that then it checks for continuous pattern by adding length of genetic string word to the start and end position of previous word
                            count = count + 1
                            if(count > maxi):  # longest combination of genes is stored as max
                                maxi = count
                            start = start + len(step)
                            end = end + len(step)

                    else:
                        start = start + 1
                        end = end + 1
                values.append(maxi)  # storing max values in values
                genes += 1  # counting how many total genetic combinations are compared

        person = 0
        rcount = 0
        for f in range(number):
            for step in dictkeys:
                if(step != "name"):  # checking that if genetic combinations in values list are some where in the csv file if all combinations are found thenit will print the name of the person
                    t = values[rcount]
                    h = int(DNA[f][step])
                    if(t == h):
                        rcount += 1
                    else:
                        break
            if(rcount == genes):
                print(DNA[person]["name"])
                return 1
            person += 1
            rcount = 0
        print("No match")  # if no one found to be of that particular genetic combinations that no match is printed


if __name__ == "__main__":
    main()