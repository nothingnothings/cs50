import csv 

# titles = set() # set is a collection of unique elements.
titles = {}

# it works, but using csv reader is not necessarily the best approach, in python... Dict Reader is also an option.
with open('favorites.csv', 'r') as csvfile:
    reader = csv.reader(csvfile)
    next(reader)
    for row in reader:
        print(row[1])
        

# Dict reader is better, but it's not as easy to use as csv reader (but you don't have the problem of someone messing with the column order, because you use object logic):
with open('favorites.csv', 'r') as csvfile:
    reader = csv.DictReader(csvfile)
    next(reader)
    for row in reader:
        # print(row['name'])
        # titles.add(row['name'])
        print(row['name'])
        
        
    

for title in sorted(titles): # sorted() sorts the titles for us...
    print(title)
    
    
    
    




# alternative syntax (we have this callback function, in the 'key' argument. It's called for each element in the list, and it returns the value to sort by):
for title in sorted(titles, key=lambda title: titles[title], reverse=True): # sorted() sorts the titles for us...
    print(title, titles[title])
    
    
    
    
    
# lambda --> o nome é 'lambda' pq é uma função anônima, que é usada para criar uma função temporária. Lambda é geralmente usado como símbolo para functions, em matemática...