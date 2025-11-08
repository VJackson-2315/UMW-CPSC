def fut_val():
    print("This program calculates the future value")
    print("of a 10-year investment.")
    
    principal = eval(input("Enter the initial principal: "))
    apr = eval(input("Enter the annual interest rate: "))
    years = eval(input("Enter the amount of years: "))
    
    for i in range(years):
        principal = principal * (1 + apr)
        
    print("The value in", years, "years is:", principal)
    
fut_val()