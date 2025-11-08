def username():
    print("Program intro. \n")

    first = input("Please enter your first name: ")
    last = input("Please enter your last name: ")

    uname = first[0] + last[:7]

    print(uname)

def calendar():
    months = "JanFebMarAprMayJunJulAugSepOctNovDec"

    n = int(input("Enter a month number (1 - 12): "))

    pos = (n-1) * 3

    monthsAbbrev = months[pos:pos+3]
    print(monthsAbbrev)
    
def calendarV2():
    months = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec']
    
    n = int(input("Enter a month number (1 - 12): "))
    
    print(months[n-1])

def encoder():
    message = input("Please enter the message to encode: ")
    
    print("\nHere are the Unicode codes:")
    
    for ch in message:
        print(ord(ch), end=" ")
    
    print()
    
def decoder():
    inString = input("Enter a message in Unicode: ")
    
    message = ""
    for numStr in inString.split():
        codeNum = int(numStr)
        message += chr(codeNum)
    
    print(message)
    
def dateconverter():
    dateStr = input("Enter a date (mm/dd/yyyy): ")
    
    monthStr, dayStr, yearStr = dateStr.split("/")
    
    months = ['January', 'Febuary', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']
    monthStr = months[int(monthStr)-1]
    
    print(monthStr, dayStr+",", yearStr)
    
def change():
    quarters = int(input("Quarters: "))
    dimes = int(input("Dimes: "))
    nickles = int(input("Nickles: "))
    pennies = int(input("Pennies: "))
    
    total = quarters * 25 + dimes * 10 + nickles * 5 + pennies
    
    print("${0}.{1:0>2}".format(total//100, total % 100))
    
def printFile():
    fname = input("Enter filename: ")
    infile = open(fname, "r")
    data = infile.read()
    print(data)