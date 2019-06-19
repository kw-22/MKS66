import subprocess

def converter(i):
    if i < 10:
        return "0" + str(i)
    else:
        return str(i)

def main():
    for i in range(36):
        f = open("mine", "w")
        script = "constants obsidian 0.0 0.2 0.3 0.1 0.2 0.3 0.1 0.2 0.3\n\
constants shiny_gold 0.2 0.8 0.6 0.2 0.6 0.6 0.0 0.2 0.4\n\
constants emerald 0.0 0.0 0.6 0.2 0.6 0.7 0.0 0.1 0.6\n"
        script += "push\n\
move 250 250 0\n\
rotate x 40\n\
rotate z "
        script += str(10 * i + 15) + "\n\
torus shiny_gold 0 0 0 15 150\n\
push\n\
rotate x "
        script += str(10 * i) + "\n\
torus emerald 0 0 0 15 130\n\
push\n\
rotate x "
        script += str(5 * i + 6) + "\n\
rotate y "
        script += str(10 * i) + "\n\
torus obsidian 0 0 0 15 110\n\
save pic"
        script += converter(i) + ".png\n"
        f.write(script)
        f.close()
        subprocess.run("make")
    subprocess.run(["convert", "-delay", "10", "-loop", "0", "pic*.png", "myimage.gif"])

main()
