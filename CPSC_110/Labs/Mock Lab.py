def encode(a_string):
    list_of_numbers = []
    for i in a_string:
        num = ord(i)
        list_of_numbers.append(num)
    return list_of_numbers

def decode(list_of_num):
    strings = ""
    for num in list_of_num:
        letter = str(chr(num))
        strings += letter
    return strings