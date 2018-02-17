import sys
import time
import postesttool as POS
from PyQt5.QtWidgets import QApplication, QWidget

if __name__ == '__main__':   
    app = QApplication(sys.argv)

    puta = POS.PosTestTool(POS.PosModel_PAX_S920)

    while puta.isIdle() == False:
        app.processEvents()
    
    # # Test routines
    # # ...
    # puta.insertCard()
    

    # # Test routines
    # # ...
    puta.keyPress('AJUDA')
    
    app.exec_()
