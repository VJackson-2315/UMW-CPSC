def convert_table():
    for celsius in range (0, 110, 10):       
        fahrenheit = 9/5 * celsius + 32
        print(celsius, "degrees Celsius is", fahrenheit, "degrees Fahrenheit.")

convert_table()