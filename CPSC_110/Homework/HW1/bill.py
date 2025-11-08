#bill.py
sub = float(input("What is your subtotal?  "))
tax = float(input("What percentage is your tax rate(whole numbers only)?  "))
total = (sub * (tax/100)) + sub
print("Your subtotal is", sub, "and your tax rate is", tax, "and your total is", total)