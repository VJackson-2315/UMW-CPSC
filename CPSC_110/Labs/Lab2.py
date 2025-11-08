def eligible(name, age, cit, state_res, state_run):
    if state_res != state_run or age < 25 or cit < 7:
        print(name, 'cannot run for Congress.')
    else:
        if age < 30 or cit < 9:
            print(name, 'can run for the House of Representatives.')

        else:
            print(name, 'can run for the House of Representatives and', name, 'can run for the Senate.')

def main():
    name = input('What is your name? ')
    age = int(input('How old are you? '))
    cit = int(input('How long have you been a citizen? '))
    state_res = input('What is your state of residence? ')
    state_run = input('What is the state you are running for? ')
    
    eligible(name, age, cit, state_res, state_run)

if __name__ == '__main__':
    eligible('James', 33, 10, 'California', 'California') #Can run for both
    eligible('Alice', 58, 7, 'New York', 'New York') #Can run for House
    eligible('Samuel', 27, 15, 'West Virginia', 'West Virginia') #Can run for House
    eligible('Austin', 22, 9, 'California', 'California') #Can't run because of age
    eligible('Jessie', 33, 6, 'California', 'California') #Can't run because of citizenship status
    eligible('Christina', 36, 15, 'Tennessee', 'Arizona') #Can't run because states don't match