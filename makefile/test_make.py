from easyprocess import EasyProcess
from nose.tools import eq_
import os
import util

FIRMWARE = os.path.dirname(__file__) + '/../Nanpy'
MAKEFILE_AND_LIB = os.path.dirname(__file__) + '/makefile_stuff'


def test_make():
    dest = util.tmpdir() + '/Nanpy'
    util.copytree(FIRMWARE, dest)
    util.copytree(MAKEFILE_AND_LIB, dest)
    p = EasyProcess('make size BOARD=uno', cwd=dest).call()
    eq_(p.return_code, 0)
