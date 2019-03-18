f = open("./1.map", "w")
f.write("1" * 100 + '\n')
for i in range(0, 28):
    f.write("1" + "0" * 98 + "1" + '\n')
f.write("1" * 100 + '\n')
f.close()