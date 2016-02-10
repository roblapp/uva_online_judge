import sys

'''
Accepted: 0.045s
Category: big num arithmetic
Algorithm: used eval() in Python :)
'''

def main():
    for line in sys.stdin:
        print(eval(line))

if __name__ == "__main__":
    main()
