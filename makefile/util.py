import tempfile
import os
import shutil


def copytree(src, dst, symlinks=False, ignore=None):
    '''http://stackoverflow.com/questions/1868714/how-do-i-copy-an-entire-directory-of-files-into-an-existing-directory-using-pyth'''
    if not os.path.exists(dst):
        os.makedirs(dst)
    for item in os.listdir(src):
        s = os.path.join(src, item)
        d = os.path.join(dst, item)
        if os.path.isdir(s):
            copytree(s, d, symlinks, ignore)
        else:
            if not os.path.exists(d) or os.stat(src).st_mtime - os.stat(dst).st_mtime > 1:
                shutil.copy2(s, d)


def tmpdir(dir=None, suffix=''):
    x = tempfile.mkdtemp(suffix=suffix, prefix='nanpy_test_', dir=dir)
    return x
