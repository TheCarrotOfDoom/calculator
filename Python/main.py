#! usr/bin python

import sys
import operation

def main():

    if len(sys.argv) > 1:
        file = open(sys.argv[1], "r")
        expressions = [line.rstrip().lower() for line in file]
    else:
        while(True): 
            expressions = input("Enter expression: ").lower()
            if(expressions != "quit"): 
                continue
            else: 
                break
    operations = calculate(expressions)
    for i in operations:
        print(i)


def calculate(expressions):
    operations = []

    for i in expressions:
        inputs = i.split()
        if inputs[0] == "print":
            print(inputs[1])
        else:
            if inputs[1] == "add":
                operations.append(operation.Add(inputs[0],inputs[2]))
            elif inputs[1] == "subtract":
                operations.append(operation.Subtract(inputs[0],inputs[2]))
            elif inputs[1] == "multiply":
                operations.append(operation.Multiply(inputs[0],inputs[2]))

    return operations




main()