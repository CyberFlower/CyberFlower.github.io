# -*- coding: utf-8 -*-
import os.path
import glob
import re

# change every file names in current directory
# change once for a file
# you can change extension use this function
def change_filename(files, ori, new):
    for x in files:
        if os.path.isdir(x):
            pass
        else:
            os.rename(x,x.replace(ori,new,1))    

# change every file in current directory
# change every word in contents
# if cnt given, change word less than cnt times per files
def change_all_file(files,ori,new,cnt=0):
    for file in files:
        if os.path.isfile(file):
            open_file=open(file,'r',encoding='UTF-8')
            read_file=open_file.read()
            tmp=re.compile(ori)
            read_file=tmp.sub(new,read_file,cnt)
            write_file=open(file,'w',encoding='UTF-8')
            write_file.write(read_file)            

if __name__=="__main__":
    os.chdir(os.getcwd()+"/_posts")
    files=glob.glob('*')
    #change_filename(files,"2","a")
    change_all_file(files,'/',' ',1)
