

file_name = open(/file_test.txt, 'w+')
file_name.write("just a test")
file_name.close()

file_name = open(file_test.txt, 'r')
read_file = file_name.read()
print(read_file)
file_name.close()