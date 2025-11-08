start = float(input("Old balance "))
dep = float(input("What is your deposit (+) or withdrawl (-)? "))
interest_rate = float(input("Annual Percentage? "))

balance = start + dep
interest_earned = interest_rate * balance
end = balance + interest_earned
print_balance = round(end, 2)

print(print_balance)