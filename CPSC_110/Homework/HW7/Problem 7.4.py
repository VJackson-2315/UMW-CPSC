def count_word_no_case(file, word):
    wordList = list(word)
    firstLetter = wordList[0].upper()
    
    newWord = firstLetter
    for char in wordList[1:]:
        newWord += char

    wordCount = 0
    with open(file, 'r') as fh:      
        for line in fh:
            if newWord in line:
                wordCount += 1
        
        print(wordCount)
        fh.close()