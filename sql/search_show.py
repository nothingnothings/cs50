import csv 

title = input("Title: ").strip().upper()


with open("favorites.py", "r") as file:
    reader = csv.reader(file)
    counter = 0
    next(reader)
    for row in reader:
        if row['title'].strip().upper() == title:
            counter += 1
            
print(counter)