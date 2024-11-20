# height = 0

# height = input("Pyramid Height: ")

# while not height.isdigit():
#     height = input("Pyramid Height: ")

# numeric_height = int(height)

# while (numeric_height < 1) or (numeric_height > 8):
#     height = input("Pyramid Height: ")
#     numeric_height = int(height)


# for i in range(numeric_height):
#     print(" " * (numeric_height - i - 1), end="")
#     for j in range(i + 1):
#         print("#", end="")
#     print()




height = 0

height = input("Pyramid Height: ")

while not height.isdigit():
    height = input("Pyramid Height: ")

numeric_height = int(height)

while (numeric_height < 1) or (numeric_height > 8):
    height = input("Pyramid Height: ")
    numeric_height = int(height)


for i in range(numeric_height):
    print(" " * (numeric_height - i - 1), end="")
    for j in range(i + 1):
        print("#", end="")
    print(" " * 2, end="")
    for j in range(i + 1):
        print("", end="")
        print("#", end="")
    print()
