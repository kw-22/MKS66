import subprocess

def converter(i):
    if i < 10:
        return "0" + str(i)
    else:
        return str(i)

def main():
    for i in range(36):
        f = open("mine", "w")
        script = "push\n\
move\n\
250 250 0\n\
rotate\n\
x 40\n\
rotate\n\
z "
        script += str(10 * i + 15) + "\n\
torus\n\
0 0 0 15 150\n\
push\n\
rotate\n\
x "
        script += str(10 * i) + "\n\
torus\n\
0 0 0 15 130\n\
push\n\
rotate\n\
x "
        script += str(5 * i + 6) + "\n\
rotate\n\
y "
        script += str(10 * i) + "\n\
torus\n\
0 0 0 15 110\n\
save\n\
pic"
        script += converter(i) + ".png\n"
        f.write(script)
        f.close()
        subprocess.run("make")
    subprocess.run(["convert", "-delay", "10", "-loop", "0", "pic*.png", "myimage.gif"])

main()
