def count_word(file, word):
    wordCount = 0
    with open(file, 'r') as fh:      
        for line in fh:
            if word in line:
                wordCount += 1
        
        print(wordCount)
        fh.close()
        
def main():
    file = input("What file should I search? ")
    word = input ("What word should I count? ")
    
    count_word(file, word)