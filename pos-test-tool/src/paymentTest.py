#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import postesttool as POS

from PySide.QtCore import *
from PySide.QtGui import *

if __name__ == '__main__':
    app = QApplication(sys.argv)

    ptt = POS.PosTestTool(POS.PosModel_PAX_S920)
    ptt.write("tcc")
    app.exec_()
