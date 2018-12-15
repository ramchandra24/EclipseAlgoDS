import random

random.seed(None)
inp = ["$facebook", "$google", "$gmail", "$youtube", "$amazon", "$linkedin",     "$gmail", "$news", "$bloomberg", "$walmart", "$dell", "$ufl", "$apple", "$m    icrosoft", "$windows", "$linux", "$github"]


count = 0
wdict = {}
with open("oGen.txt", "w") as ofile:
    with open("iGen.txt", "w") as f:
        for i in range(1000):
                ind = random.randint(0, len(inp)-1)
                freq = random.randint(0, 50)
    
                if ind in wdict:
                    wdict[ind] = wdict[ind] + freq
                else:
                    wdict[ind] = freq
                f.write(inp[ind] + " " + str(freq) + "\n")
                counnt = random.randint(0, 100)
                if count > 66:
                        f.write(str(random.randint(0, count)) + "\n")
                        dictTop = sorted(wdict, reverse=True)
                        if count < len(dictTop): 
                            count = len(dictTop)
                            fline = True
                        for i in range(count):
                                if fline:
                                    ofile.write("\n")
                                    fline = False
                                ofile.write(str(dictTop[i] + ",")
                                ofile.write("\n")