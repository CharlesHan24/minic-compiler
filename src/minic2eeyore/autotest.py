import glob
import os
import time
import pdb

src = glob.glob("../../open-test-cases/sysy/section1/functional_test/*.sy")
file_all = glob.glob("../../open-test-cases/sysy/section1/functional_test/*")

for src_file in src:
    if int(src_file[52:54]) > 96:
        continue
    os.system("./main -S -t %s -o ../../data/example.t" % src_file)
    print(src_file)
    # pdb.set_trace()
    print("")
    prefix = src_file[:-2]
    inp_name = prefix + "in"
    if inp_name in file_all:
        ret_code = os.system("./minivm -t ../../data/example.t < %s > ../../data/example.out" % inp_name)
    
    else:
        ret_code = os.system("./minivm -t ../../data/example.t > ../../data/example.out")

    #pdb.set_trace()
    ret_code = ret_code >> 8
    fout = open("../../data/example.out", "a+")
    fout.write("\n%d\n" % ret_code)
    fout.close()
    oup_name = prefix + "out"
    os.system("diff  -w ../../data/example.out %s" % oup_name)
    time.sleep(0.00001)
        