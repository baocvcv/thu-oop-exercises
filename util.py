#!/bin/python

import os, errno
import sys
import zipfile

def create_dir(week, noProblems):
    try:
        root = "week%d" % week
        os.makedirs(root)
        for i in range(1, noProblems+1):
            os.makedirs(os.path.join(root, 'Problem%d' % i))
    except OSError as e:
        if e.errno != errno.EEXIST:
            raise

def pack(week):
    rootdir = '2018011289_Bao_Han'
    zipname = rootdir + '.zip'
    zf = zipfile.ZipFile(zipname, 'w')
    os.rename('week%d' % week, rootdir)
    for dirname, subdirs, files in os.walk(rootdir):
        zf.write(dirname)
        for filename in files:
            zf.write(os.path.join(dirname, filename))
    zf.close()
    os.rename(rootdir, 'week%d' % week)

if __name__ == '__main__':
    if len(sys.argv) <= 2:
        print('Usage:')
        print('  python util.py create [week] [no_problems]')
        print('  python util.py pack [week]')
    elif sys.argv[1] == 'create':
        create_dir(int(sys.argv[2]), int(sys.argv[3]))
    elif sys.argv[1] == 'pack':
        pack(int(sys.argv[2]))


