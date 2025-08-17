import sys
 
def main():
    input_string = sys.stdin.readline().rstrip()
    index = input_string.find('\\')
    if index != -1:
        print(input_string[:index])
    else:
        print(input_string)
 
if __name__ == "__main__":
    main()