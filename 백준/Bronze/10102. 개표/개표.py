num = input()
word = input()

if word.count("A") == word.count("B"):
  print("Tie")
elif word.count("A") > word.count("B"):
  print("A")
else:
  print("B")