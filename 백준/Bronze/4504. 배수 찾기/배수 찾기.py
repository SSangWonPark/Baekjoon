num = int(input())

check = int(input())

while check != 0:
  if check % num == 0:
    print(f'{check} is a multiple of {num}.')
  else:
    print(f'{check} is NOT a multiple of {num}.')
  check = int(input())
